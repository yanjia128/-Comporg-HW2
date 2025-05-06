"addi %[add_cnt], %[add_cnt], 1\n\t"
"addi t1, zero, 1                       \n\t"               
"addi %[add_cnt], %[add_cnt], 1\n\t"
"addi t2, zero, 1\n\t"                // t2 = 1 (用於分子)
"addi %[add_cnt], %[add_cnt], 1\n\t"
"addi t3, zero, 1\n\t"                // t3 = 1 (用於分母)

"addi %[others_cnt], %[others_cnt], 1\n\t"
"fcvt.s.w f1, t2\n\t"                 // f1 = 1.0 (浮點分子)
"addi %[others_cnt], %[others_cnt], 1\n\t"
"fcvt.s.w f2, t3\n\t"                 // f2 = 1.0 (浮點分母)

"addi %[fdiv_cnt], %[fdiv_cnt], 1\n\t"
"fdiv.s %[pi], f1, f2\n\t"            // pi = 1.0/1.0 = 1.0 (初始項)

"addi %[add_cnt], %[add_cnt], 1\n\t"
"addi t4, zero, -1\n\t"               // t4 = -1 (符號交替因子)

"addi %[others_cnt], %[others_cnt], 1\n\t"
// 檢查迭代次數是否為零
"addi %[others_cnt], %[others_cnt], 1\n\t"
"beq %[N], zero, end                    \n\t"             // 如果 N == 0，跳到結束


"loop:                                  \n\t"
"addi %[others_cnt], %[others_cnt], 1\n\t"
// 更新分母 (t3 += 2)
"addi %[add_cnt], %[add_cnt], 1\n\t"
"addi t3, t3, 2                         \n\t"                  // t3 += 2 (下一個奇數)

"addi %[others_cnt], %[others_cnt], 1\n\t"
// 轉換為浮點數
"addi %[others_cnt], %[others_cnt], 1\n\t"
"fcvt.s.w f2, t3                        \n\t"                 // f2 = float(t3)

"addi %[others_cnt], %[others_cnt], 1\n\t"
// 計算項值 = 1/t3
"addi %[fdiv_cnt], %[fdiv_cnt], 1       \n\t"
"fdiv.s f2, f1, f2                      \n\t"               // f2 = 1.0/t3

"addi %[others_cnt], %[others_cnt], 1   \n\t"
// 應用符號
"addi %[others_cnt], %[others_cnt], 1   \n\t"
"fcvt.s.w f1, t4                        \n\t"                 // f1 = float(t4) = -1.0 或 1.0

"addi %[others_cnt], %[others_cnt], 1       \n\t"
"fsgnj.s f2, f2, f1                     \n\t"              // f2 = f2 * 符號

"addi %[others_cnt], %[others_cnt], 1\n\t"
// 累加到 pi
"addi %[fadd_cnt], %[fadd_cnt], 1\n\t"
"fadd.s %[pi], %[pi], f2                \n\t"         // pi += f2

"addi %[others_cnt], %[others_cnt], 1\n\t"
// 反轉符號
"addi %[sub_cnt], %[sub_cnt], 1\n\t"
"sub t4, zero, t4                       \n\t"                // t4 = -t4

"addi %[others_cnt], %[others_cnt], 1\n\t"
// 恢復 f1 = 1.0
"addi %[add_cnt], %[add_cnt], 1\n\t"
"addi t2, zero, 1                       \n\t"                // t2 = 1

"addi %[others_cnt], %[others_cnt], 1\n\t"
"fcvt.s.w f1, t2\n\t"                 // f1 = 1.0

"addi %[others_cnt], %[others_cnt], 1\n\t"
// 增加計數器
"addi %[add_cnt], %[add_cnt], 1\n\t"
"addi t1, t1, 1                         \n\t"                  // t1++

"addi %[others_cnt], %[others_cnt], 1\n\t"
// 檢查迭代次數
"addi %[others_cnt], %[others_cnt], 1\n\t"
"bne t1, %[N], loop                     \n\t"              // 如果 t1 != N，繼續循環


"end:\n\t"