#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numSort(int n, int ifDesc);
int descCmp(const void *a, const void *b);
int ascCmp(const void *a, const void *b);

int main()
{
    int N;
    scanf("%d", &N);

    int descN, ascN;
    do
    {
        descN = numSort(N, 1);
        ascN = numSort(N, 0);

        N = descN - ascN;
        printf("%04d - %04d = %04d\n", descN, ascN, N);
    } while (N != 0 && N != 6174);

    return 0;
}

int numSort(int n, int ifDesc)
{
    int nums[4] = {n / 1000, n % 1000 / 100, n % 100 / 10, n % 10};
    qsort(nums, 4, sizeof(int), ifDesc ? descCmp : ascCmp);
    return nums[0] * 1000 + nums[1] * 100 + nums[2] * 10 + nums[3];
}

int descCmp(const void *a, const void *b)
{
    return *(int *)b - *(int *)a;
}

int ascCmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

/*
输入：
6767

输出：
7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174

输入：
2222

输出：
2222 - 2222 = 0000

输入：
9998

输出：
9998 - 8999 = 0999
9990 - 0999 = 8991
9981 - 1899 = 8082
8820 - 0288 = 8532
8532 - 2358 = 6174

解题思路：
- 读入正整数 N，将正整数 N 的各位数逆序、升序排列后得到两个新的数字，将两数相减的结果赋值给 N
- 循环输出两数相减的过程和结果，直到相减结果为 0 或 6174

遇到的问题：
- 每个数字按 4 位格式输出（不足补 0）
    - 举例：int n1 = 999; printf("%04d", n1);
    - 输出：0999
- 每个数字的各位数逆序排序时，补的 0 也要参与排序
    - 举例：将 0999 逆序、升序排列后，输出相减的过程和结果
    - 输出：9990 - 0999 = 8991
*/