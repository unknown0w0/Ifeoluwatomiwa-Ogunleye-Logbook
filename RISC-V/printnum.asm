.data
    number: .word 100

.text
    lw a0, number
    li a7, 1
    ecall
    
    li a7, 10
    ecall