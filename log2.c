"addi %[others_cnt], %[others_cnt], 1\n\t"
"bne %[N], zero, not_zero               \n\t"                
"addi %[others_cnt], %[others_cnt], 1\n\t"
"jal zero, endlog2                      \n\t"    

"not_zero:                              \n\t"

"addi %[add_cnt], %[add_cnt], 1\n\t"
"addi t0, zero, 1                       \n\t"         
"addi %[others_cnt], %[others_cnt], 1\n\t"
"slli t0, t0, 31                        \n\t"    
"addi %[add_cnt], %[add_cnt], 1\n\t"
"addi t1, zero, 31                      \n\t"



"find_msb:                              \n\t"
"addi %[others_cnt], %[others_cnt], 1\n\t"
"and t0, %[N], t0                       \n\t" 
"addi %[others_cnt], %[others_cnt], 1\n\t"
"bne t0, zero, found_msb                \n\t" 
"addi %[add_cnt], %[add_cnt], 1\n\t"
"addi t0, zero, 1                       \n\t"                      
"addi %[add_cnt], %[add_cnt], 1\n\t"
"addi t1, t1, -1                        \n\t"                         
"addi %[others_cnt], %[others_cnt], 1\n\t"
"sll t0, t0, t1                        \n\t"                        

"addi %[others_cnt], %[others_cnt], 1\n\t"
"jal zero, find_msb                     \n\t"                     



"found_msb:\n\t"
"addi %[add_cnt], %[add_cnt], 1\n\t"
"add %[log], zero, t1\n\t"                   


"endlog2:                               \n\t"