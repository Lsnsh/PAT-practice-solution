#include <stdio.h>
#include <string.h>

int main()
{
    char N[1001];
    scanf("%s", N);

    int len = strlen(N);
    int i, map[10];

    for (i = 0; i < 10; i++)
    {
        map[i] = 0;
    }
    for (i = 0; i < len; i++)
    {
        map[N[i] - '0']++;
    }

    for (i = 0; i < 10; i++)
    {
        if (map[i])
        {
            printf("%d:%d", i, map[i]);
            if (i < 9)
            {
                printf("\n");
            }
        }
    }

    return 0;
}

/*
输入：
100311

输出：
0:2
1:3
3:1

解题思路：
- 以字符串形式读入正整数 N，因为 N 可能为 1000 位
- 定义长度为 10 的数组，用数组索引值表示 0～9
- 遍历字符串 N，逐个字符串减去 '0' 后得到其数值，保存在此前定义的数组中
- 遍历数组，按要求格式输出结果
*/