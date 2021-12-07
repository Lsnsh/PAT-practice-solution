#include <stdio.h>

int main()
{
    int coef, expon, count = 0;

    while (scanf("%d %d", &coef, &expon) != EOF)
    {
        // x^n => nx^n-1
        if (expon)
        {
            if (count++)
            {
                printf(" ");
            }
            printf("%d %d", expon * coef, expon - 1);
        }
    }

    if (!count)
    {
        printf("0 0");
    }

    return 0;
}

/*
输入：
3 4 -5 2 6 1 -2 0

输出：
12 3 -10 1 6 0

输入：
0 0

输出：
0 0

输入：
-2 0

输出：
0 0

解题思路：
- 读入系数和指数，套入到导数 x^n => nx^n-1 中，输出计算结果
- 当读入的数据中，只有零多项式和常数时，输出 "0 0"

*/