#include <iostream>
using namespace std;

extern "C"
{
    bool __stdcall CheckingTheTriangle(unsigned int, unsigned int, unsigned int);

int  __stdcall ScalarProduct(int*, int*, int);
}

int main()
{
    std::cout << "Please, enter your numbers:" << std::endl;
    unsigned int a, b, c;
    std::cin >> a >> b >> c;
    std::cout << std::endl;
    std::cout.setf(std::ios::boolalpha);
    std::cout << "The statement that these numbers can form a triangle is " << CheckingTheTriangle(a, b, c) << std::endl;
    std::cout << "Now, please, enter the size og your arrays:" << std::endl;
    int n;
    std::cin >> n;
    int* a_array = new int[n];
    int* b_array = new int[n];
    std::cout << std::endl << "Now enter the elements for the first array:" << std::endl;
    for (int i = 0; i < n; ++i) {
        int number;
        std::cin >> number;
        a_array[i] = number;
    }
    std::cout << std::endl;
    std::cout << std::endl << "Then enter the elements for the second array:" << std::endl;
    for (int l = 0; l < n; ++l) {
        int num;
        std::cin >> num;
        b_array[l] = num;
    }
    std::cout << std::endl << "The scalar product is " << ScalarProduct(a_array, b_array, n);
    delete[] a_array;
    delete[] b_array;
    return 0;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
