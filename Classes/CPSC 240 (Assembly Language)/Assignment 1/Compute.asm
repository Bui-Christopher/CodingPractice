extern printf
extern scanf

global Compute

section .data

  intFormat db "%ld", 0

  initalMsg db 'This program was built by Christopher Bui', 10, 0

  askInt1 db 'Please input the first Integer: ', 10, 0
  askInt2 db 'Please input the second Integer: ', 10, 0

  outputInt db 'You entered %ld', 10, 0

  outputSum db 'The sum of these two integers is %ld', 10, 0
  outputProduct db 'The product of these two integers is %ld', 10, 0

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
call         printf

;Ask First Int
mov          rax, 0
mov          rdi, askInt1
call         printf

;Get Int
mov          rax, 0
mov          rdi, intFormat
mov          rsi, rsp
call         scanf
pop          rbx
push qword   rbx

;Print Integer text
mov          rax, 0
mov          rdi, outputInt
mov          rsi, rbx
call printf

;Ask Second Int
mov          rax, 0
mov          rdi, askInt2
call         printf

;Get Second Int
mov          rax, 0
mov          rdi, intFormat
mov          rsi, rsp
call         scanf
pop          r15
push         r15

;Print Second Int
mov          rax, 0
mov          rdi, outputInt
mov          rsi, r15
call printf

;Add
mov          rax, rbx
add          rax, r15
mov          r14, rax

;Print Sum
mov          rax, 0
mov          rdi, outputSum
mov          rsi, r14
call printf

;Currently working on Multiply
mov          rax, rbx     ;move first digit into rax
mul          r15          ;multiply rax by r15

mov          r13, rax     ;store the product rax into r13

;Print Product
mov          rax, 0
mov          rdi, outputProduct
mov          rsi, r13
call printf

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
