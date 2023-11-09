#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "mpi.h"
#include <sys\timeb.h>
#include <fstream>
#include <iostream>


double realtime();

void main(int argc, char** argv)
{
	MPI_Init(&argc, &argv);

	int procs_rank, procs_count;
	MPI_Comm_size(MPI_COMM_WORLD, &procs_count);
	MPI_Comm_rank(MPI_COMM_WORLD, &procs_rank);

	std::ifstream fin("input.txt");
	int n;
	fin >> n;
	double* a = new double[n * n];
	double* b = new double[n];
	double* alpha = new double[n * n];
	double* beta = new double[n];
	if (procs_rank == 0)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				fin >> a[i * n + j];
			}
			fin >> b[i];
		}

		for (int i = 0; i < n; i++)
		{
			beta[i] = b[i] / a[i * n + i];
			for (int j = 0; j < n; j++)
			{
				if (i == j)
				{
					alpha[i * n + j] = 0;
				}
				else
				{
					alpha[i * n + j] = -a[i * n + j] / a[i * n + i];
				}
			}
		}
	}
	fin.close();

	MPI_Bcast(beta, n, MPI_DOUBLE, 0, MPI_COMM_WORLD);
	MPI_Bcast(alpha, n * n, MPI_DOUBLE, 0, MPI_COMM_WORLD);

	int single_proc_n = (n / procs_count) + (n % procs_count > procs_rank ? 1 : 0);
	int* sendcounts = new int[procs_count];
	int size = n * single_proc_n;
	double* single_proc_alpha = new double[size];
	MPI_Allgather(&size, 1, MPI_INT, sendcounts, 1, MPI_INT, MPI_COMM_WORLD);
	int* displs = new int[procs_count];
	displs[0] = 0;
	for (int i = 1; i < procs_count; i++)
	{
		displs[i] = displs[i - 1] + sendcounts[i - 1];
	}
	MPI_Scatterv(alpha, sendcounts, displs, MPI_DOUBLE, single_proc_alpha, single_proc_n* n, MPI_DOUBLE, 0, MPI_COMM_WORLD);

	double* single_proc_beta = new double[single_proc_n];
	MPI_Allgather(&single_proc_n, 1, MPI_INT, sendcounts, 1, MPI_INT, MPI_COMM_WORLD);
	for (int i = 1; i < procs_count; i++)
	{
		displs[i] = displs[i - 1] + sendcounts[i - 1];
	}
	MPI_Bcast(displs, procs_count, MPI_DOUBLE, 0, MPI_COMM_WORLD);
	MPI_Scatterv(beta, sendcounts, displs, MPI_DOUBLE, single_proc_beta, single_proc_n, MPI_DOUBLE, 0, MPI_COMM_WORLD);

	double* x = new double[n];
	double* single_proc_x = new double[single_proc_n];
	for (int i = 0; i < n; i++)
	{
		x[i] = beta[i];
	}

	double start_time = MPI_Wtime();

	double eps = 1e-6;
	double difference = 1e6;
	double* x_old = new double[n];
	if (procs_rank == 0)
	{
		for (int i = 0; i < n; i++)
		{
			x_old[i] = x[i];
		}
	}
	do
	{
		for (int i = 0; i < single_proc_n; i++)
		{
			single_proc_x[i] = 0;
			for (int j = 0; j < n; j++)
			{
				single_proc_x[i] += single_proc_alpha[i * n + j] * x[j];
			}
			single_proc_x[i] += single_proc_beta[i];
		}
		MPI_Allgatherv(single_proc_x, single_proc_n, MPI_DOUBLE, x, sendcounts, displs, MPI_DOUBLE, MPI_COMM_WORLD);

		if (procs_rank == 0)
		{
			for (int i = 0; i < n; i++)
			{
				difference = std::min(difference, std::abs(x[i] - x_old[i]));
				x_old[i] = x[i];
			}
		}
		MPI_Bcast(&difference, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);
	} while (difference > eps);

	double end_time = MPI_Wtime();

	if (procs_rank == 0)
	{
		std::ofstream fout("output.txt");
		for (int i = 0; i < n; i++)
		{
			fout << x[i] << " ";
		}
		std::cout << end_time - start_time;
	}

	delete[] a;
	delete[] b;
	delete[] alpha;
	delete[] beta;
	delete[] x;
	delete[] single_proc_alpha;
	delete[] single_proc_beta;
	delete[] single_proc_x;
	delete[] sendcounts;
	delete[] displs;

	MPI_Finalize();
}

double realtime()
{
	struct _timeb tp;
	_ftime(&tp);
	return ((double)(tp.time) * 1000 + (double)(tp.millitm));
}
