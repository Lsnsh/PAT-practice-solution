#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *Int2String(int num, char *str);

int main()
{
    char n[100];
    char *ret = (char *)malloc(sizeof(char) * 100);
    char *numPinyin[11] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    int x = 0, sum = 0, flag = 0, i = 0;

    scanf("%s", n);
    // printf("\ns=%s", n);

    for (i = 0; i < strlen(n); i++)
    {
        sum += (n[i] - '0');
    }
    // printf("\ns=%d", sum);

    Int2String(sum, n);

    // printf("nlen=%lu\n", strlen(n));
    for (i = 0; i < strlen(n); i++)
    {
        if (!flag)
        {
            flag = 1;
        }
        else
        {
            printf(" ");
        }
        printf("%s", numPinyin[n[i] - '0']);
    }

    return 0;
}

// https://www.runoob.com/w3cnote/c-int2str.html
char *Int2String(int num, char *str) //10进制
{
    int i = 0;   //指示填充str
    if (num < 0) //如果num为负数，将num变正
    {
        num = -num;
        str[i++] = '-';
    }
    //转换
    do
    {
        str[i++] = num % 10 + 48; //取num最低位 字符0~9的ASCII码是48~57；简单来说数字0+48=48，ASCII码对应字符'0'
        num /= 10;                //去掉最低位
    } while (num);                //num不为0继续循环

    str[i] = '\0';

    //确定开始调整的位置
    int j = 0;
    if (str[0] == '-') //如果有负号，负号不用调整
    {
        j = 1; //从第二位开始调整
        ++i;   //由于有负号，所以交换的对称轴也要后移1位
    }
    //对称交换
    for (; j < i / 2; j++)
    {
        //对称交换两端的值 其实就是省下中间变量交换a+b的值：a=a+b;b=a-b;a=a-b;
        str[j] = str[j] + str[i - 1 - j];
        str[i - 1 - j] = str[j] - str[i - 1 - j];
        str[j] = str[j] - str[i - 1 - j];
    }

    return str; //返回转换后的值
}

/*
输入；
1234567890987654321123456789

输出：
yi san wu

难点：

1. 读入数据，整数 n 很大，[1, 10^100)
2. 输出结果，求和之后，要根据映射关系输出字符串

解题思路：

1. 读入数据

- 作为字符串读入
- 作为单个整数，循环读入

2. 输出结果

- 求和后，整数转为字符串，遍历字符串，根据映射关系输出字符串
    整数转为字符串：1. 自定义方法A 2. 自定义方法B：每位上的数字 + '0'，插入到字符数组中，最后拼接成字符串
- 求和后，求余+除法运算，逆序得到数字，根据映射关系得到部分字符串，逆序拼接成正序字符串输出
    很笨的方法

收获：

- char* 定义字符串常量
- char[] 定义固定长度的伪字符串变量，不能参与计算，只能通过下标修改字符
- char* 配合 malloc 定义可变长度，字符串变量
*/