// lab 2 - sem2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

bool CheckingTheTriangle(unsigned int a, unsigned int b, unsigned int c) {
    bool result = 1;
    __asm {
        mov eax, a
        mov ebx, b
        mov ecx, c

        add eax, ebx
        jc _pair2
        cmp eax, ecx
        jng _false
        
        _pair2:
        mov eax, a
        add ebx, ecx
        jc _pair3
        cmp ebx, eax
        jng _false

        _pair3 :
        mov ebx, b
        add eax, ecx
        jc _end
        cmp eax, ebx
        jng _false
        jmp _end

        _false:
        mov result, 0

        _end:
    }
    return result;
}

int ScalarProduct(int* a_arr, int* b_arr, int n) {
    int result[3] = { 0, 0, 0 };
    __asm {
        mov edi, a_arr
        mov esi, b_arr

        XOR ECX, ECX;
    ForBegin1:
        CMP ECX, n;
        JE ForEnd1;
        mov ebx, dword ptr[edi]; // ai
        add edi, 4;          // edi[++i]
        mov eax, dword ptr[esi]; // bi
        add esi, 4;         // esi[++i]
        imul ebx;           // edx:eax = ai * bi
        add [result], eax
        adc [result+4], edx
        adc [result+8], 0
        INC ECX;
        JMP ForBegin1;
    ForEnd1:
 /*       mov eax, result[1]
        add result[0], eax*/
    }
    return result[0];
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
