#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);

    int P1WinCount = 0, P1DrawCount = 0, P1FailCount = 0, P1CWinCount = 0, P1BWinCount = 0, P1JWinCount = 0;
    int P2CWinCount = 0, P2BWinCount = 0, P2JWinCount = 0;
    char *P1, *P2, P1MaxCount, P2MaxCount;
    int i;
    for (i = 0; i < N; i++)
    {
        scanf("%s %s", &P1, &P2);
        //printf("-输入：%c %c\n", P1, P2);

        if (P1 == P2)
        {
            P1DrawCount++;
        }
        else
        {
            if (P1 == 'C')
            {
                if (P1 < P2)
                {
                    P1WinCount++;
                    P1CWinCount++;
                }
                else
                {
                    P1FailCount++;
                    P2BWinCount++;
                }
            }
            else if (P1 == 'J')
            {
                if (P2 == 'B')
                {
                    P1WinCount++;
                    P1JWinCount++;
                }
                else
                {
                    P1FailCount++;
                    P2CWinCount++;
                }
            }
            else
            {
                if (P2 == 'C')
                {
                    P1WinCount++;
                    P1BWinCount++;
                }
                else
                {
                    P1FailCount++;
                    P2JWinCount++;
                }
            }
        }
    }

    printf("%d %d %d\n", P1WinCount, P1DrawCount, P1FailCount);
    printf("%d %d %d\n", P1FailCount, P1DrawCount, P1WinCount);

    if (P1BWinCount >= P1CWinCount && P1BWinCount >= P1JWinCount)
    {
        P1MaxCount = 'B';
    }
    else if (P1CWinCount > P1BWinCount && P1CWinCount >= P1JWinCount)
    {
        P1MaxCount = 'C';
    }
    else if (P1JWinCount > P1BWinCount && P1JWinCount > P1CWinCount)
    {
        P1MaxCount = 'J';
    }

    if (P2BWinCount >= P2CWinCount && P2BWinCount >= P2JWinCount)
    {
        P2MaxCount = 'B';
    }
    else if (P2CWinCount > P2BWinCount && P2CWinCount >= P2JWinCount)
    {
        P2MaxCount = 'C';
    }
    else if (P2JWinCount > P2BWinCount && P2JWinCount > P2CWinCount)
    {
        P2MaxCount = 'J';
    }

    printf("%c %c", P1MaxCount, P2MaxCount);

    return 0;
}

/*
输入：
10
C J
J B
C B
B B
B C
C C
C B
J B
B C
J J

输出：
5 3 2
2 3 5
B B

解题思路：
- 循环读入数据时，比较甲（玩家 1）和乙（玩家 2）的胜负
- 记录甲胜、平、负的次数，甲和乙出锤子、剪刀、布胜的次数
- 根据甲的胜负情况，反向即是乙的胜负情况，输出甲和乙胜、平、负的次数
- 甲和乙从其出锤子、剪刀、布胜的次数中，各自比较后得出并输出其获胜次数最高的出手方式（锤子、剪刀、布）

优化：
- 只记录甲和乙出锤子、剪刀、布胜的次数即可，据此计算出甲和乙胜、平、负的次数
*/