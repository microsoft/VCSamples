; Copyright (c) Microsoft Corporation.  All rights reserved.

.386
.model flat, c

EXTERN p:PTR SBYTE
EXTERN sz:DWORD

; Custom Build Step (for sieve.asm/sieve.obj), including a listing file placed in intermediate directory
; but without Source Browser information
; Command Line (debug):
;  ml -c -Zi "-Fl$(IntDir)\$(InputName).lst" "-Fo$(IntDir)\$(InputName).obj" "$(InputPath)"
; Command Line (release):
;  ml -c "-Fl$(IntDir)\$(InputName).lst" "-Fo$(IntDir)\$(InputName).obj" "$(InputPath)"
; Outputs:
;  $(IntDir)\$(InputName).obj

; Custom Build Step (for sieve.asm/sieve.obj), including a listing file placed in intermediate directory
; and Source Browser information also placed in intermediate directory
; Command Line (debug):
;  ml -c -Zi "-Fl$(IntDir)\$(InputName).lst" "-FR$(IntDir)\$(InputName).sbr" "-Fo$(IntDir)\$(InputName).obj" "$(InputPath)"
; Command Line (release):
;  ml -c "-Fl$(IntDir)\$(InputName).lst" "-FR$(IntDir)\$(InputName).sbr" "-Fo$(IntDir)\$(InputName).obj" "$(InputPath)"
; Outputs:
;  $(IntDir)\$(InputName).obj;$(IntDir)\$(InputName).sbr

.code

; The Sieve of Eratosthenes uses an array of an integral type to 
; track prime numbers where the index into the array represents the 
; number and the value stored is its 'prime-ness' -- 0 for prime, 
; 1 for not prime.  Non-primes are calculated by exhaustively 
; multiplying pairs of integers together from 2 to N, N being chosen 
; based on range of primes desired, to calculate non-primes. This 
; implementation uses an array of chars to reduce memory usage.

; Step 1 C source for sieve of Eratosthenes
;  for (i=2; i<=sz/2; i++)
;    for (j=2; j<=sz/i; j++)
;      p[i*j-1]=1;

; Modify j loop and array index to eliminate div by i
;  for (i=2; i<=sz/2; i++)
;    for (j=2*i; j<=sz; j+=i)
;      p[j-1]=1;

sieve PROC uses ebx
  mov edx, p
  push 2
  pop eax                      ;  for (i=2;...
iloop:
  mov ecx, eax
  shl ecx, 1                   ;    for (j=2*i;...
jloop:
  mov ebx, sz
  cmp ecx, ebx                 ;    ... j<=sz;
  ja @F
  mov BYTE PTR [edx+ecx-1], 1  ;      p[j-1]=1;
  add ecx, eax                 ;    ... j+=i)
  jmp jloop
@@:
  inc eax                      ;  ... i++)
  shr ebx, 1
  cmp eax, ebx                 ;  ...i<=sz/2;
  jb iloop
  RET
sieve ENDP

end
