#include <stdio.h>
#include <string.h>

#define START_DATE "1814/09/06"
#define END_DATE "2014/09/06"
#define LEN 17
#define DATE_LEN 11

int main()
{
    int N, i, count = 0;
    char cur[LEN], eldest[LEN] = {'9'}, youngest[LEN] = {'0'};
    scanf("%d", &N);

    for (i = 0; i < N; i++)
    {
        scanf("%s %s", cur + DATE_LEN, cur);

        if (strcmp(cur, START_DATE) >= 0 && strcmp(cur, END_DATE) <= 0)
        {
            count++;
            if (strcmp(cur, eldest) <= 0)
            {
                memcpy(eldest, cur, LEN);
            }
            if (strcmp(cur, youngest) >= 0)
            {
                memcpy(youngest, cur, LEN);
            }
        }
    }

    printf("%d", count);
    if (count)
    {
        printf(" %s %s", eldest + DATE_LEN, youngest + DATE_LEN);
    }

    return 0;
}

/*
输入：
5
John 2001/05/12
Tom 1814/09/06
Ann 2121/01/30
James 1814/09/05
Steve 1967/11/20

输出：
3 Tom John

输入：
2
John 3001/05/12
Ann 2121/01/30

输出：
0

解题思路：
- 为了方便比较，用固定长度的字符数组，保存日期和姓名两个字符串
- 使用 strcmp 函数比较日期大小，使用 memcpy 函数复制字符数组（一次复制两个字符串）
- 统计有效生日数量，找到最年长、最年轻的生日后，按特定格式输出结果
*/