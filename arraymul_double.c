"addi %[add_cnt], %[add_cnt], 1              \n\t"   
"addi t0, x0, 0                              \n\t"

"1:                                          \n\t"
    "addi %[others_cnt], %[others_cnt], 1    \n\t"   
    "bge t0, %[arr_size], 2f                 \n\t"

    "fld f0, 0(%[h])                         \n\t"
    "addi %[dlw_cnt], %[dlw_cnt], 1          \n\t"

    "fld f1, 0(%[x])                         \n\t"
    "addi %[dlw_cnt], %[dlw_cnt], 1          \n\t"

    "fmul.d f2, f0, f1                       \n\t"
    "addi %[dmul_cnt], %[dmul_cnt], 1        \n\t"
    
    "fmul.d %[result], %[result], f2         \n\t"
    "addi %[dmul_cnt], %[dmul_cnt], 1        \n\t"

    "addi %[h], %[h], 8                      \n\t"
    "addi %[x], %[x], 8                      \n\t"
    "addi t0, t0, 1                          \n\t"

    "addi %[add_cnt], %[add_cnt], 3          \n\t"
    "addi %[others_cnt], %[others_cnt], 1    \n\t"  
    "jal x0, 1b                              \n\t"


"2:                                          \n\t"
