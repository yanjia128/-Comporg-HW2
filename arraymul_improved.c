"vsetvli t0, %[arr_size], e32, m1, ta, ma\n\t"
"addi %[others_cnt], %[others_cnt], 1     \n\t"
"addi   t0, x0, 0                         \n\t"
"add %[add_cnt], %[add_cnt], 1          \n\t"

"loop_start:                            \n\t"
"    sub t0, %[arr_size], t0            \n\t"
"    addi %[sub_cnt], %[sub_cnt], 1      \n\t"

"    vsetvli t0, t0, e32, m1, ta, ma    \n\t"
"    addi %[others_cnt], %[others_cnt], 1\n\t"
"    vle32.v v0, (%[h])                 \n\t"
"    add %[lw_cnt], %[lw_cnt], 1      \n\t"

"    vle32.v v1, (%[x])                 \n\t"
"    add %[lw_cnt], %[lw_cnt], 1      \n\t"

"    vfmul.vv v2, v0, v1                \n\t"
"    add %[fmul_cnt], %[fmul_cnt], 1  \n\t"
"    vfadd.vf v0, v2, %[id]             \n\t"
"    add %[fadd_cnt], %[fadd_cnt], 1  \n\t"

"    vse32.v v0, (%[y])                 \n\t"
"    add  %[sw_cnt], %[sw_cnt], 1      \n\t"

"    slli t0, t0, 2                     \n\t"
"    add %[h], %[h], t0                 \n\t"
"    add %[y], %[y], t0                 \n\t"
"    add %[x], %[x], t0                 \n\t"
"    srli t0, t0, 2                     \n\t"
"    addi %[others_cnt], %[others_cnt], 2\n\t"
"    addi %[add_cnt], %[add_cnt], 3      \n\t"


"    sub %[arr_size], %[arr_size], t0   \n\t"
"    addi %[sub_cnt], %[sub_cnt], 1      \n\t"

"    addi %[others_cnt], %[others_cnt], 1\n\t"
"    bnez %[arr_size], loop_start       \n\t"