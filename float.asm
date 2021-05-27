.686
.model flat

public _ShowArcsine@4
public _CalculateSh@8

.data
zero dw 0
.code

_ShowArcsine@4 proc
   FINIT
   fld dword ptr [esp + 4]
   fld dword ptr [esp + 4]
   fmul st(0), st(1)
   fld1
   fsub st(0), st(1)
   fsqrt
   fxch 
   fxch st(2)
   fxch
   fpatan
   FRNDINT
   ret 4
_ShowArcsine@4 endp

_CalculateSh@8 proc
   FINIT
   fld1
   fld dword ptr [esp + 4]
   ficom zero
   FSTSW ax
   SAHF
   je _zero
   FSTSW ax
   SAHF
   jna _for_negative
   fld dword ptr [esp + 4]
   fld dword ptr [esp + 4]
   fld dword ptr [esp + 8]
   fld1
   fld1
   fld dword ptr [esp + 4]
   fcom st(3)
   FSTSW ax
   SAHF
   jna _end
   _begin:
   fmul st(0), st(4)
   fmul st(0), st(4)
   fst st(5)
   fxch st(2)
   fadd st(0), st(7)
   fmul st(1), st(0)
   fadd st(0), st(7)
   fmul st(1), st(0)
   fxch st(2)
   fdiv st(0), st(1)
   fcom st(3)
   FSTSW ax
   SAHF
   jna _end
   fadd st(6), st(0)
   fxch st(5)
   fst st(5)
   FSTSW ax
   SAHF
   jmp _begin 

   _end:

   fxch st(6)
   FSTSW ax
   SAHF
   jmp FINAL

   _for_negative:
   fchs
   fld dword ptr [esp + 4]
   fchs
   fld dword ptr [esp + 4]
   fchs
   fld dword ptr [esp + 8]
   fld1
   fld1
   fld dword ptr [esp + 4]
   fchs
   fcom st(3)
   FSTSW ax
   SAHF
   jna _end1
   _begin1:
   fmul st(0), st(4)
   fmul st(0), st(4)
   fst st(5)
   fxch st(2)
   fadd st(0), st(7)
   fmul st(1), st(0)
   fadd st(0), st(7)
   fmul st(1), st(0)
   fxch st(2)
   fdiv st(0), st(1)
   fcom st(3)
   FSTSW ax
   SAHF
   jna _end1
   fadd st(6), st(0)
   fxch st(5)
   fst st(5)
   FSTSW ax
   SAHF
   jmp _begin1

   _zero:
   fild zero
   FSTSW ax
   SAHF
   jmp FINAL

   _end1:
   fxch st(6)
   fchs

   FINAL:
   ret 8

_CalculateSh@8 endp

end