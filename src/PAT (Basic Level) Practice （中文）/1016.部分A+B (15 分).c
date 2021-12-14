#include <stdio.h>
#include <string.h>

int count2Number(int n, int count);

int main()
{
    char As[11], Bs[11];
    int DA, DB;

    scanf("%s %d %s %d", As, &DA, Bs, &DB);
    // printf("-输出：%s %d %s %d\n", As, DA, Bs, DB);

    int i, ACount = 0, BCount = 0;
    for (i = 0; i < strlen(As); i++)
    {
        if (As[i] - '0' == DA)
        {
            ACount++;
        }
    }
    for (i = 0; i < strlen(Bs); i++)
    {
        if (Bs[i] - '0' == DB)
        {
            BCount++;
        }
    }

    // printf("-输出：%d %d\n", ACount, BCount);
    printf("%d", count2Number(DA, ACount) + count2Number(DB, BCount));

    return 0;
}

int count2Number(int n, int count)
{
    int ret = 0, x = 1, i;

    for (i = 0; i < count; i++)
    {
        ret += n * x;
        x *= 10;
    }

    return ret;
}

/*
输入：
3862767 6 13530293 3

输出：
399

输入：
3862767 1 13530293 8

输出：
0

解题思路：
- 读入数据后遍历字符串，根据「数字字符值 - '0' = 数字整型值」比对 DA、DB，统计其在 A、B 中出现的次数
- 根据出现的次数计算出数值，最后输出两者相加的值即可
*/