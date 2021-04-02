// lab 4 - asm.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

extern "C" bool _fastcall IsPalindrom(char* s);
extern "C" int _stdcall DeleteBracers(char* str, int length);

int main()
{
	std::cout << "Please, enter your string:" << std::endl;
	char* str1 = new char[300];
	char* str2 = new char[300];
	std::cin.getline(str1, 300);
	std::cout.setf(std::ios::boolalpha);
	int n1 = strlen(str1);
	str1[n1] = '?';
	str1[n1 + 1] = '\0';
	std::cout << "The statement that this string is palindrom is " << IsPalindrom(str1);
	std::cout << std::endl << "Please, enter your new string:" << std::endl;
	std::cin.getline(str2, 300);
	int n2 = strlen(str2);
	std::cout << "Now, the length of this string is " << DeleteBracers(str2, n2);
	delete[] str1;
	delete[] str2;
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
