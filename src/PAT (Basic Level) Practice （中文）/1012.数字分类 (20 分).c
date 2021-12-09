#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);
    
    int A1 = 0, A2 = 0, A3 = 0, A4 = 0, A5 = 0;
    int i, n, A2Sign = 0, A4Count = 0;

    for (i = 0; i < N; i++)
    {
        scanf("%d", &n);

        if (n % 5 == 0 && n % 2 == 0)
        {
            A1 += n;
        }
        else if (n % 5 == 1)
        {
            if (A2Sign == 0)
            {
                A2Sign = 1;
            }
            A2 += A2Sign * n;
            A2Sign = -A2Sign;
        }
        else if (n % 5 == 2)
        {
            A3++;
        }
        else if (n % 5 == 3)
        {
            A4 += n;
            A4Count++;
            // printf("-输出：%d %d\n", A4, A4Count);
        }
        else if (n % 5 == 4)
        {
            A5 = n > A5 ? n : A5;
        }
    }

    if (A1 != 0)
    {
        printf("%d ", A1);
    }
    else
    {
        printf("N ");
    }

    if (A2Sign != 0)
    {
        printf("%d ", A2);
    }
    else
    {
        printf("N ");
    }

    if (A3 != 0)
    {
        printf("%d ", A3);
    }
    else
    {
        printf("N ");
    }

    if (A4Count != 0)
    {
        printf("%.1f ", A4 * 1.0 / A4Count);
    }
    else
    {
        printf("N ");
    }

    if (A5 != 0)
    {
        printf("%d", A5);
    }
    else
    {
        printf("N");
    }

    return 0;
}

/*
输入：
13 1 2 3 4 5 6 7 8 9 10 20 16 18

输出：
30 11 2 9.7 9

输入：
8 1 2 4 5 6 7 9 16

输出：
N 11 2 N 9

解题思路：
- 认真读题
- 读入数字，根据求余结果分类整合数字，最后输出分类结果

遇到的问题：
- 读题不认真，没看到第一个数字 M，表示的是后续会输入 M 个数字
- 执行报错，因为想节省空间，使用 short int 声明变量，遇到最大边界值时 1000 * 1000 > 2^16 - 1，数值溢出

收获：
- 在预设内存空间充裕的情况下，不做“无意义”的“内存优化”操作
- 或者做内存优化时，必须明确知道自己在做什么，设想好报错时 fallback 的操作
*/