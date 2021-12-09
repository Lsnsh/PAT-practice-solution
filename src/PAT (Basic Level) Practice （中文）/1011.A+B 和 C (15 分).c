#include <stdio.h>

int main()
{
    short int N, i;
    scanf("%hd", &N);

    long int A, B;
    int C;
    for (i = 0; i < N; i++)
    {
        scanf("%ld %ld %d", &A, &B, &C);

        printf("Case #%d: %s", i + 1, A + B > C ? "true" : "false");
        if (i < N - 1)
        {
            printf("\n");
        }
    }

    return 0;
}
/*
输入：
6
1 2 3
2 3 4
2147483647 0 2147483646
0 -2147483648 -2147483647
2147483647 2 2147483646
-1 -2147483648 -2147483647

输出：
Case #1: false
Case #2: true
Case #3: true
Case #4: false
Case #5: true
Case #6: false

解题思路：
- 使用 long int 类型声明变量 A 和 B，根据 A + B > C 的结果，输出特定内容即可

遇到的问题：
- 已知 A、B、C 为区间 [-2^31, 2^31] 内的整数，A、B 同为正整数或负整数时，A + B 可能会超出整型（int）取值范围，导致 A + B > C 的结果不符合预期

收获：
- 32 位-有符号整型（int/signed int）为区间 [-2^31, 2^31 - 1] 内的整数
    - #include <limits.h>
    - [INT_MIN, INT_MAX] => [-2147483648, 2147483647]
- 32 位-无符号整型（unsigned int）为区间 [0, 2^32 - 1] 内的整数
    - [0, UINT_MAX] => [0, 4294967295]
- 64 位-有符号长整型（long int/signed long int）为区间 [-2^63, 2^63 - 1] 内的整数
    - [LONG_MIN, LONG_MAX] => [-9223372036854775808, 9223372036854775807]
- 64 位-无符号长整型（unsigned long int）为区间 [0, 2^64 - 1] 内的整数
    - [0, ULONG_MAX] => [0, 18446744073709551615]
*/
