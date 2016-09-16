; Copyright (c) Microsoft Corporation.  All rights reserved.

.386
.model flat, c

; Custom Build Step, including a listing file placed in intermediate directory
; but without Source Browser information
; debug:
; ml -c -Zi "-Fl$(IntDir)\$(InputName).lst" "-Fo$(IntDir)\$(InputName).obj" "$(InputPath)"
; release:
; ml -c "-Fl$(IntDir)\$(InputName).lst" "-Fo$(IntDir)\$(InputName).obj" "$(InputPath)"
; outputs:
; $(IntDir)\$(InputName).obj

; Custom Build Step, including a listing file placed in intermediate directory
; and Source Browser information also placed in intermediate directory
; debug:
; ml -c -Zi "-Fl$(IntDir)\$(InputName).lst" "-FR$(IntDir)\$(InputName).sbr" "-Fo$(IntDir)\$(InputName).obj" "$(InputPath)"
; release:
; ml -c "-Fl$(IntDir)\$(InputName).lst" "-FR$(IntDir)\$(InputName).sbr" "-Fo$(IntDir)\$(InputName).obj" "$(InputPath)"
; outputs:
; $(IntDir)\$(InputName).obj
; $(IntDir)\$(InputName).sbr

.code

; Euclid's algorithm finds the greatest common divisor by repeatedly
; subtracting the smaller number from the larger number until zero
; is reached. The number remaining is the greatest common divisor.

euclid PROC x:SDWORD, y:SDWORD
  mov ecx, x
  mov eax, y
@@:
  cmp ecx, eax
  jge noswap
  xchg eax, ecx
noswap:
  sub ecx, eax
  jnz @B
; return value already in eax
  RET
euclid ENDP

end
