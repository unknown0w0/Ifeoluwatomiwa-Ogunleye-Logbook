.data
    message: .asciz "Hello Ifeoluwatomiwa Ogunleye. Welcome to RISC-V Assembler programming"

.text
    la a0, message
    li a7, 4
    ecall

    li a7, 10
    ecall