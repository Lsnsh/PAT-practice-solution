#include <stdio.h>

void ten2x(int C, int D);

int main()
{
    int A, B, C, D;
    scanf("%d %d %d", &A, &B, &D);

    C = A + B;
    if (D == 10)
    {
        printf("%d", C);
    }
    else
    {
        ten2x(C, D);
    }

    return 0;
}

void ten2x(int C, int D)
{
    if (C == 0)
    {
        printf("0");
        return;
    }

    int len = 32, count = 0, Y = 0;
    char ret[len + 1];

    while (C > 0)
    {
        Y = C % D;
        ret[count++] = Y + '0';
        C = C / D;
    }

    // printf("-输出：ret=%s\n", ret);

    for (count--; count >= 0; count--)
    {
        printf("%c", ret[count]);
    }
}

/*
输入：
123 456 8

输出：
1103

输入：
0 0 8

输出：
0

解题思路：
- 读入整数 A、B 和目标进制 D，计算得到两数之和 C
- 从 C 的末位开始处理进制转换，直到 C 小于等于 0
    - 将 C % D 的余数，保存在字符串 ret 中
    - 将 C / D 的积，再赋值给 C
- 所有余数的字符组合，倒序输出即是进制的值

遇到的问题：
- 没有处理 A + B 的结果为 0 的情况
*/