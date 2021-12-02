#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct StuNode
{
    char name[11];
    char no[11];
    int score;
};
typedef struct StuNode *Student;

int main()
{
    int N;
    scanf("%d", &N);
    // printf("-输入：%d\n", N);

    Student max = (Student)malloc(sizeof(struct StuNode)),
            min = (Student)malloc(sizeof(struct StuNode)),
            temp = (Student)malloc(sizeof(struct StuNode));
    max->score = -1;
    min->score = 101;

    for (int i = 0; i < N; i++)
    {
        scanf("%s %s %d", temp->name, temp->no, &temp->score);
        // printf("-输入（%d）：%s %s %d\n", i, temp->name, temp->no, temp->score);

        // printf("-输出（%d）：score=%d, max->score=%d, min->score=%d\n", i, temp->score, max->score, min->score);
        if (temp->score > max->score)
        {
            // printf("-输出（%d before max）：%s %s %d\n", i, max->name, max->no, max->score);
            strcpy(max->name, temp->name);
            strcpy(max->no, temp->no);
            max->score = temp->score;
        }
        if (temp->score < min->score)
        {
            // printf("-输出（%d before min）：%s %s %d\n", i, min->name, min->no, min->score);
            strcpy(min->name, temp->name);
            strcpy(min->no, temp->no);
            min->score = temp->score;
        }

        // printf("-输出（%d after max）：%s %s %d\n", i, max->name, max->no, max->score);
        // printf("-输出（%d after min）：%s %s %d\n", i, min->name, min->no, min->score);
    }

    // printf("-输出：%s %s %d\n", max->name, max->no, max->score);
    // printf("-输出：%s %s %d\n", min->name, min->no, min->score);

    printf("%s %s\n", max->name, max->no);
    printf("%s %s", min->name, min->no);

    return 0;
}

/*
输入：
3
Joe Math990112 89
Mike CS991301 100
Mary EE990830 95

输出：
Mike CS991301
Joe Math990112

难点：
1. 字符串指针-引用问题，使用 「strcpy - string.h」 方法完成赋值

遇到的问题：
1. 使用 malloc 申请内存后，需要指定返回值类型（在此之前定义的结构体指针类型 —— Student）
2. 比较成绩后更新学生姓名、学号、成绩，最后输出发现仅成绩（int）是正常赋值，姓名、学号（char[] 字符串）都是最后一名学生的信息

*/