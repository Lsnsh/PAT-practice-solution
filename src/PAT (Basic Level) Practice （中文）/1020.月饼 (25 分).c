#include <stdio.h>
#include <stdlib.h>

struct ItemNode
{
    float stock;
    float amount;
    float sales;
};
typedef struct ItemNode *Item;

int cmp(const void *a, const void *b)
{
    Item item1 = *(Item *)a;
    Item item2 = *(Item *)b;
    return item2->sales > item1->sales;
}

int main()
{
    int N, i;
    float M, result = 0;
    scanf("%d %f", &N, &M);

    Item YB[N];
    for (i = 0; i < N; i++)
    {
        Item item = (Item)malloc(sizeof(struct ItemNode));
        scanf("%f", &item->stock);
        YB[i] = item;
    }
    for (i = 0; i < N; i++)
    {
        scanf("%f", &YB[i]->amount);
        YB[i]->sales = YB[i]->amount / YB[i]->stock;
        // printf("-输出：%.2f %.2f %.2f\n", YB[i]->stock, YB[i]->amount, YB[i]->sales);
    }

    qsort(YB, N, sizeof(Item), cmp);

    i = 0;
    while (M > 0 && i < N)
    {
        if (M >= YB[i]->stock)
        {
            result += YB[i]->amount;
            M -= YB[i]->stock;
            YB[i]->stock = 0;
            i++;
        }
        else
        {
            result += M * YB[i]->sales;
            YB[i]->stock -= M;
            M = 0;
        }
        // printf("-输出(while)：%d %.2f %d\n", M, result, YB[i]->stock);
    }

    printf("%.2f", result);

    return 0;
}

/*
输入：
3 20
18 15 10
75 72 45

输出：
94.50

输入：
3 40
18 10 10
75 72 72

输出：
219.00

解题思路：
- 以结构体数组的形式，保存读入的数据
- 将读入的数据，按每万吨的单价降序排列
- 循环“卖出”月饼，记录收益，直到满足市场需求或库存为 0 为止

遇到的问题：
- 结构体数组变量 YB，申请动态大小的内存失败，改为循环读入数据时，申请单个结构体内存
- qsort compare 函数中，对浮点数排序，返回相减的值不生效，改为返回判断大小后的结果
    - return item2->sales - item1->sales;
    - return item2->sales > item1->sales;
- 整型和浮点数混合计算问题，统一改为浮点数计算
- 月饼库存为 0 后，没有终止执行，导致段错误
*/