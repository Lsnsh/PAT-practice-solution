#include <stdio.h>

int isPrimeNumber(int x);

int main()
{
    int M, N;
    scanf("%d %d", &M, &N);
    
    int n = 1, count = 0;
    while(count < N)
    {
        n++;
        if (isPrimeNumber(n))
        {
            count++;
            if (count >= M)
            {
                printf("%d", n);
                
                if (count - M + 1 >= 10 && (count - M + 1) % 10 == 0)
                {
                    printf("\n");
                }
                else if (count < N)
                {
                    printf(" ");
                }
            }
        }
    }

    return 0;
}

int isPrimeNumber(int x)
{
    int ret = 1;
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            ret = 0;
        }
    }
    
    return ret;
}

/*
输入：
5 27

输出：
11 13 17 19 23 29 31 37 41 43
47 53 59 61 67 71 73 79 83 89
97 101 103

解题思路：
- 从 1 开始数（count++）素数，当数到第 M 个素数时（count >= M），按要求输出素数，直到数到第 N 个素数为止

遇到的问题：
- 从第 M 个素数开始，每输出 10 个素数，换一行进行输出
    - 第 M 个素数输出之后，不用输出换行
    - 第 M 个素数，是输出的第 1 个素数
*/