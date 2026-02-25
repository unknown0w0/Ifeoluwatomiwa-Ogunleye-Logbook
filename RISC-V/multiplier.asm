.data
num1: .word 6
num2: .word 7
result: .word 0

.text
.globl main

main:
    lw t0, num1      
    lw t1, num2      
    li t2, 0         

loop:
    beq t1, zero, done
    add t2, t2, t0   
    addi t1, t1, -1  
    j loop

done:
    sw t2, result

    # exit
    li a7, 10
    ecall