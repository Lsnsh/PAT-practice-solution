#include <stdio.h>

#define CLK_TCK 100

int main()
{
    int C1, C2, hours, minutes, seconds;
    scanf("%d %d", &C1, &C2);

    float totalSconds;
    totalSconds = (C2 - C1) * 1.0 / CLK_TCK;

    // rounding
    seconds = (int)(totalSconds + 0.5);

    // get hours
    hours = seconds / (60 * 60);
    seconds -= hours * (60 * 60);

    // get minutes
    minutes = seconds / 60;
    seconds -= minutes * 60;

    printf("%02d:%02d:%02d", hours, minutes, seconds);

    return 0;
}

/*
输入：
123 4577973

输出：
12:42:59

输入：
3 100

输出：
00:00:01

解题思路：
- 读入数据，计算出秒数后，将秒数四舍五入
- 分别计算出、小时、分钟、秒数后，按特定格式输出结果

遇到的问题：
- 没有处理四舍五入成整数的情况：(int)(floatValue + 0.5)
- 没有格式化输出：%02d
*/