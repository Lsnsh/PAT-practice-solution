#include <stdio.h>

int main()
{
    int N;
    char sample;
    scanf("%d %c", &N, &sample);
    
    int copyN = N - 1, height = 1, count = 1;
    while (copyN > 0)
    {
        if (copyN - (count + 2) * 2 >= 0)
        {
            copyN -= (count + 2) * 2;
            height++;
            count += 2;
        }
        else
        {
            break;
        }
    }
    // printf("-输出：copyN=%d, %d, %d\n", copyN, height, count);
    
    int i, j, copyCount = count;
    for (i = 0; i < height - 1; i++)
    {
        for (j = 0; j < (count - copyCount) / 2; j++)
        {
            putchar(' ');
        }
        for (j = copyCount; j > 0; j--)
        {
            putchar(sample);
        }
        printf("\n");
        copyCount -= 2;
    }
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < (count - copyCount) / 2; j++)
        {
            putchar(' ');
        }
        for (j = 0; j < copyCount; j++)
        {
            putchar(sample);
        }
        printf("\n");
        copyCount += 2;
    }
    printf("%d", copyN);
    
    return 0;
}

/*
输入：
19 *

输出：
*****
 ***
  *
 ***
*****
2

解题思路：
- 读入数据 N 后，循环减去两倍奇数，找到沙漏的高度和最大一行用的符号数
- 遍历沙漏高度，根据最大一行的符号数，将沙漏分为上、下两部分输出
*/