.data
    fp_num: .float 6.742169

.text
    la t0, fp_num
    flw fa0, 0(t0)
    li a7, 2
    ecall

    li a7, 10
    ecall