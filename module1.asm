.686
.model flat
public _Calculate@16
.data

.code
_Calculate@16 proc
        mov eax, [esp + 8]
        mov ebx, [esp + 16]
        imul ebx
        mov ebx, [esp + 12]
        add eax, ebx
        neg eax
        mov ecx, eax; ecx - делимое
        mov ebx, 3
        mov eax, [esp + 4]
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
       ; mov result, ecx
       mov eax, ecx
            jmp _end

            _greater :
            cmp ecx, 0
            jng _neg3
            add ecx, 1
            ;mov result, ecx
            mov eax, ecx
            jmp _end
                _neg3:
                sub ecx, 1
                    ;mov result, ecx
                    mov eax, ecx
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
        ;mov result, ecx
        mov eax, ecx
    _end:
       ret 16
_Calculate@16 endp

end
