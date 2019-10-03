extern printf
extern scanf

global Compute

section .data

  intFormat db "%ld", 0

  initalMsg db 'This is Assignment 2 programmed by Christopher Bui.',0x0a
  randomComment db 'My goal is to engineer algorithms!', 10, 0

  askInt1 db 'Please input the first integer and press enter: ', 10, 0
  askInt2 db 'Please input the second integer and press enter: ', 10, 0

  outputInt db 'You entered %ld', 10, 0

  outputQuotient db 'The quotient of %ld divided by %ld is %ld with remainder %ld.', 10, 0
  outputPositive db 'The remainder is clearly positive.', 10, 0
  outputNegative db 'The remainder is clearly negative.', 10, 0
  outputZero     db 'Sorry, we do not divide by 0 as it will damage the space-time continuum.', 10, 0
  outputRepeat   db 'Please run this program again', 10, 0

section .bss
;Empty

section .text
  Compute:
push         rbp
mov          rbp, rsp

push         rdi
push         rsi
push         rdx
push         rcx
push         r8
push         r9
push         r10
push         r11
push         r12
push         r13
push         r14
push         r15
push         rbx
pushf

;Welcome Message
mov          rax, 0
mov          rdi, initalMsg
mov          rsi, randomComment
call         printf

;Ask First Int
mov          rax, 0
mov          rdi, askInt1
call         printf

;Get Int
push qword   0
push qword   99
mov          rax, 0
mov          rdi, intFormat
mov          rsi, rsp
call         scanf
pop          rbx
pop          rax

;Print Integer text
mov          rax, 0
mov          rdi, outputInt
mov          rsi, rbx
call printf

;Ask Second Int
mov          rax, 0
mov          rdi, askInt2
call         printf         ;dividend

;Get Second Int
push qword   0
push qword   99
mov          rax, 0
mov          rdi, intFormat
mov          rsi, rsp
call         scanf
pop          r15
pop          rax

;if divisior == 0, print this, jump to end.
cmp          r15, 0
je           end

;Print Second Int
mov          rax, 0
mov          rdi, outputInt
mov          rsi, r15         ;divisor
call printf


;Divide
mov          rax, rbx     ;move first digit into rax
cqo
idiv         r15          ;divide rax by r15
mov          r13, rax     ;store the quotient rax into r13
mov          r12, rdx

;Print Quotient
mov          rax, 0
mov          rdi, outputQuotient        ;text
mov          rsi, rbx                   ;dividend
mov          rdx, r15                   ;divisor
mov          rcx, r13
mov          r8,  r12                   ;remainder
call printf
jmp          continue

end:
mov          rax, 0
mov          rdi, outputZero
mov          rsi, outputRepeat
call         printf

continue:
popf
pop          rbx
pop          r15
pop          r14
pop          r13
pop          r12
pop          r11
pop          r10
pop          r9
pop          r8
pop          rcx
pop          rdx
pop          rsi
pop          rdi
pop          rbp
ret
