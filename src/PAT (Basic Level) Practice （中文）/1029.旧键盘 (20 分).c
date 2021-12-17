#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char input[81], tempc;
    int output[128] = {0}, i;
    scanf("%s", input);

    while (scanf("%c", &tempc) != EOF)
    {
        output[toupper(tempc)]++;
    }

    for (i = 0; i < strlen(input); i++)
    {
        tempc = toupper(input[i]);
        if (output[(int)tempc] == 0)
        {
            putchar(tempc);
            output[(int)tempc] = -1;
        }
    }

    return 0;
}

/*
输入：
7_This_is_a_test
_hs_s_a_es

输出：
7TI

输入：
7_This_is_a_test_123_hello_world
_hs_s_a_es_3_he_

输出：
7TI12LOWRD

解题思路：
- 定义字符串保存「应该输入的文字」，整型数组保存「实际被输出的文字」
    - 字符的 ASCII 码值作为数组索引值，数组元素值表示字符出现的次数
    - 使用 toupper 函数将小写转换为大写，大小写字符出现的次数合并统计
- 遍历「应该输入的文字」字符串：
    - 字符经大写转换后，ASCII 码值作为数组索引值
    - 找到并按特定格式输出「实际未输出的字符」
*/