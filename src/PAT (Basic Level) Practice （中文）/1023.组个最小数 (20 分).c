#include <stdio.h>

int main()
{
    int nums[10], i = 0;

    for (i = 0; i < 10; i++)
    {
        scanf("%d", &nums[i]);

        while (i > 0 && nums[i])
        {
            printf("%d", i);
            nums[i]--;

            while (nums[0])
            {
                printf("0");
                nums[0]--;
            }
        }
    }

    return 0;
}

/*
输入：
2 2 0 0 0 3 0 0 1 0

输出：
10015558

解题思路：
- 给定 0~9 的数字若干，要组合最小数：
    - 除 0 外最小的数为首位
    - 其次为 0
    - 最后是其他数从小到大的组合
- 循环读入数字的个数 nums[i]，从 1 开始之后，输出第一个非 0 的数，然后输出所有的 0
- 继续读入并输出对应个数个其他数，直到全部读入为止
*/