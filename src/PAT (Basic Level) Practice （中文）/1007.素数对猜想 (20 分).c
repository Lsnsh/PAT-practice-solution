#include <stdio.h>

int isPrimeNum(int n);

int main()
{
    int N;
    scanf("%d", &N);

    int i, prevPrime = 2, count = 0;
    for (i = 2; i <= N; i++)
    {
        if (isPrimeNum(i))
        {
            // printf("-输出：素数：%d\n", i);
            if (prevPrime && i - prevPrime == 2)
            {
                count++;
                // printf("-输出：素数对：%d %d\n", prevPrime, i);
            }
            prevPrime = i;
        }
    }

    printf("%d", count);

    return 0;
}

int isPrimeNum(int n)
{
    int ret = 1;

    // 某某筛法，只判断 n 平方根内的数即可，i^2 免去引入库函数给 n 开方
    for (int i = 2; i * i <= n; i++)
    {
        // 能被 1，和自身以外的数，整除的数，就不是素数
        if (n % i == 0)
        {
            ret = 0;
            break;
        }
    }

    return ret;
}

/*
输入：
20

输出：
4

输入：
100000

输出：
1224

解题思路：
- 逐个找到范围内的素数，将这个素数记录下来，当下一个素数与上一个记录的素数的差为 2 时，即是一对满足猜想的素数对

遇到的问题：
- 执行报错，自己划定的素数定义：能整除（2,3,5,7）的数就不是素数，不能满足所有 case
    - 回顾之前写过的素数判断方法，改为逐个判断不能被1和自身以外的数（i <= n）整除的数，才是素数
- 执行超时（时间限制：200ms）
    - 优化：i <= n 改为 i * i <= n，是某某筛法（好像是埃氏筛法的简易版）
    - 因为如果它不是质数，那么它一定可以表示成两个数（除了1和它本身）相乘，这两个数必然有一个小于等于它的平方根。只要找到小于或等于的那个就行了
    - https://blog.csdn.net/lzxlovegyd/article/details/71340090
    - 只判断 n 平方根内的数即可，i^2 免去引入库函数给 n 开方
*/