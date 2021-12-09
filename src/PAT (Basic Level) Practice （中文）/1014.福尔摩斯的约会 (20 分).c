#include <stdio.h>
#include <string.h>

int main()
{
    char *week[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    char s1[61], s2[61], s3[61], s4[61];
    int i, len, flag = 0, day = 0, hour = 0, mintue = 0;

    scanf("%s", s1);
    scanf("%s", s2);
    scanf("%s", s3);
    scanf("%s", s4);

    len = strlen(s1) > strlen(s2) ? strlen(s2) : strlen(s1);
    for (i = 0; i < len; i++)
    {
        if (s1[i] == s2[i])
        {
            if (!flag && s1[i] >= 'A' && s1[i] <= 'G')
            {
                day = s1[i] - 'A';
                flag = 1;
                // printf("-输出：s1[i]=%c, day=%d\n", s1[i], day);
                continue;
            }
            else if (flag && (s1[i] >= '0' && s1[i] <= '9'))
            {
                hour = s1[i] - '0';
                // printf("-输出：s1[i]=%c, hour=%d\n", s1[i], hour);
                break;
            }
            else if (flag && (s1[i] >= 'A' && s1[i] <= 'N'))
            {
                hour = s1[i] - 'A' + 10;
                // printf("-输出：s1[i]=%c, hour=%d\n", s1[i], hour);
                break;
            }
        }
    }

    len = strlen(s3) > strlen(s4) ? strlen(s4) : strlen(s3);
    for (i = 0; i < len; i++)
    {
        if (s3[i] == s4[i] && ((s3[i] >= 'A' && s4[i] <= 'Z') || (s3[i] >= 'a' && s4[i] <= 'z')))
        {
            mintue = i;
            // printf("-输出：s3[i]=%c, mintue=%d\n", s3[i], mintue);
            break;
        }
    }

    // printf("-输出：%d, %d, %d\n", day, hour, mintue);

    printf("%s ", week[day]);
    if (hour < 10)
    {
        printf("0%d:", hour);
    }
    else
    {
        printf("%d:", hour);
    }

    if (mintue < 10)
    {
        printf("0%d", mintue);
    }
    else
    {
        printf("%d", mintue);
    }

    return 0;
}

/*
输入：
3485djDkxh4hhGE 
2984akDfkkkkggEdsb 
s&hgsfdk 
d&Hyscvnm

输出：
THU 14:04

输入：
3485djDkxh4hhG8 
2984akDfkkkkgg8dsb 
s&hgsfdk 
d&Hyscvnm

输出：
THU 08:04

输入：
3485djDkxh4hhGN 
2984akDfkkkkggNdsb 
s&hgqeZsfdk 
d&HyswZscvnm

输出：
THU 23:06


解题思路：
- 读懂题意，第一二行字符串，解码得到星期和小时的信息，第三四行字符串，解码能得到分钟的信息
    - 星期（A~G => 0~6）
    - 小时（0~9, A~N => 0~24）
    - 分钟（[A-Za-z] index）
- 因此保存输入的字符串，分为两组处理（第一组：星期+小时，第二组：分钟）
- 遍历字符串，检查每组中相同位置的字符是否相等，以及是否是特定范围内的字符
- 将满足条件的字符的相关信息收集，然后以规定格式，输出内容结果

遇到的问题：
- 执行报错（两个 case 未通过），因为没有完全看懂题意和记全字符在 ASCII 表中的大概位置
    - 在 ASCII 表中 数字 < 大写字母 < 小写字母
    - 小时的编码是由 0~9 和 A~N 组合而成
    - 分钟的编码是英文字母，意思是同时包括大写和小写字母
    - 星期获取到之后，就要开始获取小时，都只获取一次
*/