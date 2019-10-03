#/bin/bash

rm *.o
rm *.out

echo "Compute.asm"
nasm -f elf64 -o Compute.o -l Compute.lis ChrisBui_CPSC240_Assignment2_Compute.asm

echo "Compile driver.c"
gcc -c -Wall -m64 -std=c11 -fno-pie -no-pie -o driver.o ChrisBui_CPSC240_Assignment2_driver.c

echo "Link the object files"
gcc -m64 -fno-pie -no-pie -o running.out driver.o Compute.o

echo "Run the program Compute:"
./running.out

echo "The script file will terminate"
