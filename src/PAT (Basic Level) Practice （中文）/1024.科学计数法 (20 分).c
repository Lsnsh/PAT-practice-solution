#include <stdio.h>

int main()
{
    int expon;
    char coef[10000], *p = coef;
    scanf("%[^E]E%d", coef, &expon);

    if (*p++ == '-')
    {
        printf("-");
    }

    if (expon > 0)
    {
        printf("%c", *p++);
        p++;

        while (expon > 0)
        {
            if (*p)
            {
                printf("%c", *p++);
            }
            else
            {
                printf("0");
            }
            expon--;
        }
        while (*p)
        {
            printf(".");
            printf("%c", *p);
            p++;
        }
    }
    else
    {
        printf("0.");
        expon++;

        while (expon < 0)
        {
            printf("0");
            expon++;
        }
        while (*p)
        {
            if (*p != '.')
            {
                printf("%c", *p);
            }
            p++;
        }
    }

    return 0;
}

/*
输入：
+1.23400E-03

输出：
0.00123400

输入：
-1.2E+10

输出：
-12000000000

解题思路：
- 读入数据时，使用正则表达式，拆分系数和指数，定义指针变量记录系数字符串的起始位置
- 根据系数的正负情况，分别处理，系数为正时：
    - 输出系数的整数部分，先不输出小数点
    - 根据指数的大小，输出系数的小数部分，不足时补 0
    - 如果指数的大小，不足以将系数的小树部分全部进位为整数时，输出系数剩余的小数部分，包含小数点
- 系数为负时：
    - 输出 「0.」，先输出小数点
    - 根据指数的大小，输出补足的 0
    - 最后输出系数部分，忽略小数点
*/