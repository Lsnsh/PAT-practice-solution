#include <stdio.h>
#include <string.h>

int checkPATStr(char *s1, int len);

int main()
{
    int N, i;
    char s1[101] = "";
    scanf("%d", &N);

    for (i = 0; i < N; i++)
    {
        scanf("%s", s1);
        if (checkPATStr(s1, strlen(s1)))
        {
            printf("YES");
        }
        else
        {
            printf("NO");
        }
        if (i < N - 1)
        {
            printf("\n");
        }
    }

    return 0;
}

int checkPATStr(char *s1, int len)
{
    int flag = 0, hasP = 0, hasT = 0, ACountBeforeP = 0, ACountAfterP = 0, ACountAfterT = 0;

    // PAT, xPATx, aPbTc, aPbATca
    for (int i = 0; i < len; i++)
    {
        // printf("-s1[%d]=%c\n", i, s1[i]);
        if (s1[i] == 'P' && !hasP)
        {
            hasP = 1;
        }
        else if (s1[i] == 'A')
        {
            if (hasP)
            {
                if (!hasT)
                {
                    ACountAfterP++;
                }
                else
                {
                    ACountAfterT++;
                }
            }
            else
            {
                ACountBeforeP++;
            }
        }
        else if (s1[i] == 'T' && ACountAfterP >= 1 && !hasT)
        {
            hasT = 1;
        }
        else
        {
            break;
        }
    }

    if (hasT && ACountBeforeP * ACountAfterP == ACountAfterT)
    {
        flag = 1;
    }

    return flag;
}

/*
输入：
10
PAT
PAAT
AAPATAA
AAPAATAAAA
xPATx
PT
Whatever
APAAATAA
APT
APATTAA

4
PAT
PAAT
AAPAAATAAAAAA
AAA

输出：
YES
YES
YES
YES
NO
NO
NO
NO
NO
NO

YES
YES
YES
NO

难点：

// PAT, xPATx, aPbTc, aPbATca
1. 寻找规律：a * b = c => 「P 之前的 a 个 A」*「P 和 T 中间的 b 个 A」=「T 之后的 c 个 A」
2. 处理边界：a, b, c 都可以为空字符串；至少要满足有 P、A、T 三个字符；并且保证其先后顺序；

遇到的问题：

1. 没有总结出规律，网上找题解文章才看懂
2. 边界情况，漏掉了 AAA 的情况
*/