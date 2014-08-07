#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int maxn = 50010;
int c[maxn], n;
int lowbit(int x)
{
    return x & -x;
}
void Add(int x, int y)
{
    while (x <= n)
    {
        c[x] += y;
        x += lowbit(x);
    }
}
int Sum(int x)
{
    int sum = 0;
    while (x)
    {
        sum += c[x];
        x -= lowbit(x);
    }
    return sum;
}
int main()
{
    int t, Case = 0;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        memset(c, 0, sizeof(c));
        for (int i = 1; i <= n; i++)
        {
            int a;
            scanf("%d", &a);
            Add(i, a);
        }
        char s[10];
        printf("Case %d:\n", ++Case);
        while (scanf("%s", s) && s[0] != 'E')
        {
            int a, b;
            scanf("%d%d", &a, &b);
            if (s[0] == 'A')
                Add(a, b);
            else if (s[0] == 'S')
                Add(a, -b);
            else  printf("%d\n", Sum(b) - Sum(a - 1));
        }
    }
    return 0;
}
