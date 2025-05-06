"addi %[add_cnt], %[add_cnt], 1\n\t"
"addi t0, x0, 0                         \n\t"                             

"addi %[add_cnt], %[add_cnt], 1\n\t"
"addi t1, x0, 0                         \n\t"                             

"bit_reverse_loop:\n\t"
"addi %[others_cnt], %[others_cnt], 1\n\t"
"beq t1, %[m], end_loop\n\t"              

"addi %[others_cnt], %[others_cnt], 1\n\t"
"andi t2, %[b], 1\n\t"                     

"addi %[others_cnt], %[others_cnt], 1\n\t"
"slli t0, t0, 1                         \n\t"                       


"addi %[others_cnt], %[others_cnt], 1\n\t"
"or t0, t0, t2\n\t"                       

"addi %[others_cnt], %[others_cnt], 1\n\t"
"srli %[b], %[b], 1\n\t"                   

"addi %[add_cnt], %[add_cnt], 1\n\t"
"addi t1, t1, 1\n\t"                 


"addi %[others_cnt], %[others_cnt], 1\n\t"
"jal x0, bit_reverse_loop               \n\t"

"end_loop:                              \n\t"
"addi %[add_cnt], %[add_cnt], 1\n\t"
"addi %[b], t0, 0                       \n\t"                          
