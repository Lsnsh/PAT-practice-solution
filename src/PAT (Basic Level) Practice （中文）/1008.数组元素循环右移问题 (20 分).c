#include <stdio.h>

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);

    int num[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &num[i]);
    }

    M = M % N;

    int i;
    for (i = N - M; i < N; i++)
    {
        printf("%d ", num[i]);
    }
    for (i = 0; i < N - M - 1; i++)
    {
        printf("%d ", num[i]);
    }
    printf("%d", num[N - M - 1]);

    return 0;
}

/*
输入：
6 2
1 2 3 4 5 6

输出：
5 6 1 2 3 4

输入：
7 4
1 2 3 4 5 6 7

输出：
4 5 6 7 1 2 3

解题思路：
- 方法 A：不移动数组元素，直接输出
    - 先输出后 M 个数组元素，然后输出前 N - M 个数组元素，即为满足条件的输出结果
- 方法 B：移动数组元素，直到满足条件后，遍历数组输出
    - 有 K 初始为 N - M
    - 分支1：数组中待处理元素数量 K，大于等于 M 时
        - 将数组尾部 M 个元素，与数组头部 M 个元素进行交换（swap），每次处理 M 个元素（K -= M）
    - 分支2：数组中待处理元素 K，小于 M 时，遍历将 K 个元素移动（move）到数组尾部

遇到的问题：
- 采用方法 B，报错+超时
    - 报错：在线运行测试，不输出内容
        - 将 printf("%c%d", i == 0 ? '\0' : ' ', num[i]);
        - 改为 printf("%d%c", num[i], i != N - 1 ? ' ' : '\0');
    - 超时：400ms，时间复杂度为 O(M * K)
        - 待优化：M > K 时，执行类似分支 1 中的交换操作，交换的边界值需要重新界定
- 没有想到可以不交换数组元素，直接奔着输出结果而去，即方法 A 的做法
*/

/*
得分：15分，2 个 case 超时
#include <stdio.h>

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);

    int num[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &num[i]);
    }

    M = M % N;
    int temp = 0, i = 0, j = 0, P = 0, K = N - M;
    while (K > 0)
    {
        if (K >= M)
        {
            // printf("-输出（swap）：K=%d, P=%d, M=%d\n", K, P, M);
            for (i = 0; i < M; i++)
            {
                temp = num[P + i];
                num[P + i] = num[N - M + i];
                num[N - M + i] = temp;
            }
        }
        else
        {
            // printf("-输出（move）：K=%d, P=%d, M=%d\n", K, P, M);
            for (j = 0; j < K; j++)
            {
                for (i = 0; i < M + K - 1; i++)
                {
                    temp = num[P + i];
                    num[P + i] = num[P + i + 1];
                    num[P + i + 1] = temp;
                }
                // P++;

                // printf("-输出：");
                // for (i = 0; i < N; i++)
                // {
                //     printf("%c%d", i == 0 ? '\0' : ' ', num[i]);
                // }
                // printf("\n");
            }
        }
        K -= M;
        P += M;

        // printf("-输出：");
        // for (i = 0; i < N; i++)
        // {
        //     printf("%c%d", i == 0 ? '\0' : ' ', num[i]);
        // }
        // printf("\n");
    }

    for (i = 0; i < N; i++)
    {
        printf("%d%c", num[i], i != N - 1 ? ' ' : '\0');
    }

    return 0;
}
*/