#include <stdio.h>
#include <stdlib.h>

struct Item
{
    int id;
    int d_score;
    int c_score;
    int group;
    int sum_score;
};
typedef struct Item *Student;

int classify(Student stu, int L, int H);
int qsortCompare(const void *a, const void *b);

int main()
{
    int N, L, H;
    scanf("%d %d %d", &N, &L, &H);

    Student stus[N];
    int i, len = 0;
    for (i = 0; i < N; i++)
    {
        Student stu = (Student)malloc(sizeof(struct Item));
        scanf("%d %d %d", &stu->id, &stu->d_score, &stu->c_score);
        // printf("-输入：%d %d %d\n", stu->id, stu->d_score, stu->c_score);

        stu->group = classify(stu, L, H);
        stu->sum_score = stu->d_score + stu->c_score;
        // printf("-输入：%d %d\n", stu->group, stu->sum_score);
        if (stu->group != 0)
        {
            // printf("-输出(%d)：%d %d %d\n", len, stu->id, stu->d_score, stu->c_score);
            stus[len++] = stu;
        }
    }

    qsort(stus, len, sizeof(Student), qsortCompare);

    printf("%d\n", len);
    for (i = 0; i < len; i++)
    {
        printf("%d %d %d\n", stus[i]->id, stus[i]->d_score, stus[i]->c_score);
        free(stus[i]);
    }

    return 0;
}

int classify(Student s0, int L, int H)
{
    int group = 0;
    if (s0->d_score < L || s0->c_score < L)
    {
        group = 0;
    }
    else if (s0->d_score >= H && s0->c_score >= H)
    {
        group = 1;
    }
    else if (s0->d_score >= H)
    {
        group = 2;
    }
    else if (s0->d_score >= s0->c_score)
    {
        group = 3;
    }
    else
    {
        group = 4;
    }

    return group;
}

int qsortCompare(const void *a, const void *b)
{
    Student s1 = *(Student *)a;
    Student s2 = *(Student *)b;

    if (s1->group != s2->group)
    {
        return s1->group - s2->group;
    }
    else
    {
        if (s1->sum_score != s2->sum_score)
        {
            return s2->sum_score - s1->sum_score;
        }
        else
        {
            if (s1->d_score != s2->d_score)
            {
                return s2->d_score - s1->d_score;
            }
            else
            {
                return s1->id - s2->id;
            }
        }
    }
}

/*
输入：
14 60 80
10000001 64 90
10000002 90 60
10000011 85 80
10000003 85 80
10000004 80 85
10000005 82 77
10000006 83 76
10000007 90 78
10000008 75 79
10000009 59 90
10000010 88 45
10000012 80 100
10000013 90 99
10000014 66 60

输出：
12
10000013 90 99
10000012 80 100
10000003 85 80
10000011 85 80
10000004 80 85
10000007 90 78
10000006 83 76
10000005 82 77
10000002 90 60
10000014 66 60
10000008 75 79
10000001 64 90

输入：
6 60 80
10000001 64 90
10000002 90 60
10000011 85 80
10000004 60 80
10000003 60 80
10000005 79 78

输出：
6
10000011 85 80
10000002 90 60
10000005 79 78
10000001 64 90
10000003 60 80
10000004 60 80

解题思路：
- 定义合适的数据结构保存学生信息，然后给学生进行分类、排序，最后输出结果

遇到的问题：
- 执行报错（两个 case 未通过）：因为没有给“德胜才”这类学生进行分类
    - 导致没有“优先按德”输出，而是同“才德兼亡”这类学生比较总分去了
        - 10000002 90 60
        - 10000005 79 78
- 段错误：qsort 函数的第三个参数传递有误
    - 将 sizeof(struct Item) 改为 => sizeof(Student) 后正常执行了
*/