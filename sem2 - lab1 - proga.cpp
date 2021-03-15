// sem2 - lab1 - proga.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>

int Calculate(int a, int b, int c, int y)
{
    int result;

    __asm
    {
        mov eax, b
        mov ebx, y
        imul ebx
        mov ebx, c
        add eax, ebx
        neg eax
        mov ecx, eax; ecx - делимое
        mov ebx, 3
        mov eax, a
        cdq
        imul ebx
        mov ebx, eax
        mov eax, ecx
        cdq
        idiv ebx; eax - частное, ebx - делитель
        mov ecx, eax; теперь в есх лежит частное
        cmp edx, 0
        je _nope
        mov eax, 2
        imul edx; eax - удвоенный остаток
        cmp eax, 0
        jng _neg1
        _ret1:
        cmp ebx, 0
        jng _neg2
        _ret2:
        cmp eax, ebx
        jnge _less
        jnle _greater
        je _equal

            _less :
        mov result, ecx
            jmp _end

            _greater :
            cmp ecx, 0
            jng _neg3
            add ecx, 1
            mov result, ecx
            jmp _end
                _neg3:
                sub ecx, 1
                    mov result, ecx
            jmp _end

                    _equal:
                mov eax, 0
                    mov ebx, 2
                    add eax, ecx
                    cdq
                    idiv ebx
                    cmp edx, 0
                    jne _greater
                    jmp _nope

    _neg1:
        neg eax
        jmp _ret1
   
    _neg2 :
        neg ebx
        jmp _ret2
   
    _nope :
        mov result, ecx
    
    _end:
    }

    return result;
}

int main() {
    int a, b, c, y;
    std::cin >> a >> b >> y >> c;
    std::cout << std::endl;
    std::cout << Calculate(a, b, c, y);
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
