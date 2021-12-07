#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);

    int n1 = N / 100, n2 = (N % 100) / 10, n3 = N % 10;

    int i = 0;
    for (i = 0; i < n1; i++)
    {
        printf("B");
    }

    for (i = 0; i < n2; i++)
    {
        printf("S");
    }

    for (i = 0; i < n3; i++)
    {
        printf("%d", i + 1);
    }

    return 0;
}
/*
输入：
234

输出：
BBSSS1234

输入：
23

输出：
SS123

解题思路：
- 通过除法会自动取整的特点、结合求余数运算，计算出百位、十位、个位的数
- 遍历百位、十位、个位，按要求输出对应的替代字符
*/