.686
.model flat

public @IsPalindrom@4
public _DeleteBracers@8

.data

.code

@IsPalindrom@4 proc
   mov edi, ecx
   mov esi, ecx
   xor ecx, ecx
   mov eax, '?'
    _begin1:
    scasb
    je _finish1
    inc ecx
    jmp _begin1
	_finish1:
   
   mov edx, ecx
   dec edi
   xor ecx, ecx

   _begin2:
   dec edi
   mov bl, [edi]
   lodsb
   cmp al, bl
   jne _false
   inc ecx
   cmp edx, ecx
   je _finish2
   jmp _begin2
   _finish2:
   mov eax, 1
   jmp _end
   _false:
   mov eax, 0

   _end:
   ret 0
@IsPalindrom@4 endp



_DeleteBracers@8 proc
    enter 0,0
    push ebx
    push edi
    push esi

    mov edi, [ebp + 8]
    mov ecx, [ebp + 12]

    cld
    mov edx, 0
    _again:
    mov eax, '('
    mov ebx, 0

    _begin2:
    cmp ecx, 0
    je _end
    dec ecx
    scasb   
    je _brackets
    inc edx
    jmp _begin2

    _brackets:
    mov eax, ')'
    inc ebx
   
   _begin3:
    cmp ecx, 0
    je _end
    dec ecx
    scasb
    je _again
    inc ebx
    cmp ecx, 0
    jne _begin3
    
    
    _end:
    add edx, ebx
    mov eax, edx

    pop esi
    pop edi
    pop ebx

    leave

   ret 8
_DeleteBracers@8 endp

end
