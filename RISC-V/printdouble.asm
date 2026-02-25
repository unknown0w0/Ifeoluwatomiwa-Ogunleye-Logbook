.data
    dp_num: .double 2077.6769

.text
    la t0, dp_num
    fld fa0, 0(t0)
    li a7, 3
    ecall

    li a7, 10
    ecall