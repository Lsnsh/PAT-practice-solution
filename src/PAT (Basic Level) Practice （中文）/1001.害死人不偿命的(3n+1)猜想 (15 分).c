#include <stdio.h>

int cut(int x);

int main()
{
    int n, count = 0;
    scanf("%d", &n);
    
    while(n != 1)
    {
        n = cut(n);
        count++;
    }
    
    printf("%d", count);
    
    return 0;
}

int cut(int x)
{
    if (x % 2 == 0)
    {
        x /= 2;
    } else {
        x = ((3 * x) + 1) / 2;
    }
    return x;
}