﻿// LibraryApp.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Header.h"
#include "Number.h"

int main()
{
    Number n(10);
    Number n2(4);
    Number n3 = n + n2;
    Number n4 = n - n2;
    Number n5 = n * n2;
    Number n6 = n / n2;
    std::cout << n3.getValue() << std::endl;
    std::cout << n4.getValue() << std::endl;
    std::cout << n5.getValue() << std::endl;
    std::cout << n6.getValue() << std::endl;
    Vector v1(n, n2);
    Vector v2(n3, zero);
    Number num = createNumber(6);
    std::cout << num.getValue();
    v2.add(v1);
    std::cout << v1.countFi().getValue() << std::endl;
    std::cout << v1.countRo().getValue() << std::endl;
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
