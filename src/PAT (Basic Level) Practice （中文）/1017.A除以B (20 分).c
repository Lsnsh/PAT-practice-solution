#include <stdio.h>
#include <string.h>

int main()
{
    char A[1001], *p = A;
    int B;
    scanf("%s %d", A, &B);

    int twoDigit, remainder;
    for (int i = 0; i < strlen(A); i++)
    {
        twoDigit = remainder * 10 + (A[i] - '0');
        A[i] = twoDigit / B + '0';
        remainder = twoDigit % B;
    }

    if (A[0] == '0' && A[1] != '\0')
    {
        p++;
    }
    printf("%s %d", p, remainder);

    return 0;
}

/*
输入：
123456789050987654329 7

输出：
17636684150141093474 3

解题思路：
- 读入 A 和 B 后，使用指针 p 记录字符串 A 的初始位置
- 遍历字符串 A，余数和数字 A[i] - '0' 组合为两位数 twoDigit
- 两位数除以 B 求积、将积数转换为字符后，记录在字符串的 A[i] 位置上，第一轮可能没有积
- 两位数除以 B 求余，更新余数，用于下一轮作为两位数组合 twoDigit 的十位数
- 遍历结束后，检查并过滤（指针 p++ 向右移动一位）字符串 A 起始位置可能存在的字符 '0'
- 最后输出指针 p 和 余数
*/