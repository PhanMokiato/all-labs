.686
.model flat
public _CheckingTheTriangle@12
public _ScalarProduct@12
.data
result dword 1
rresult dword 0, 0, 0
.code
_CheckingTheTriangle@12 proc
 mov eax, [esp + 12]
 mov ebx, [esp + 8]
 mov ecx, [esp + 4]

 add eax, ebx
 jc _pair2
 cmp eax, ecx
 jng _false
        
 _pair2:
 mov eax, [esp + 12]
 add ebx, ecx
 jc _pair3
 cmp ebx, eax
 jng _false

 _pair3 :
 mov ebx, [esp + 8]
 add eax, ecx
 jc _end
 cmp eax, ebx
 jng _false
 jmp _end

 _false:
 mov result, 0

 _end:
 mov eax, result

 ret 12
 _CheckingTheTriangle@12 endp


_ScalarProduct@12 proc
mov edi, [esp + 4]
mov esi, [esp + 8]

XOR ECX, ECX;
ForBegin1:
CMP ECX, [esp + 12];
JE ForEnd1;
mov ebx, dword ptr[edi]
add edi, 4
mov eax, dword ptr[esi]; // bi
add esi, 4;         // esi[++i]
imul ebx;           // edx:eax = ai * bi
add [rresult], eax
adc [rresult+4], edx
adc [rresult+8], 0
INC ECX
JMP ForBegin1
ForEnd1:
mov eax, [rresult]

ret 12
_ScalarProduct@12 endp

end
