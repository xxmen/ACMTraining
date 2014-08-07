#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
struct cow{
    int s, e;
    int id;
}a[100010];
int c[100010], ans[100010];
const int M = 100005;
bool cmp(cow x, cow y)
{
    if (x.e == y.e)
        return x.s < y.s;
    return x.e > y.e;
}
int lowbit(int x)
{
    return x & -x;
}
void add(int x)
{
    while (x <= M)
    {
        c[x]++;
        x += lowbit(x);
    }
}
int sum(int x)
{
    int s = 0;
    while (x > 0)
    {
        s += c[x];
        x -= lowbit(x);
    }
    return s;
}
int main()
{
    int n;
    while (scanf("%d", &n) && n)
    {
        memset(c, 0, sizeof(c));
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d", &a[i].s, &a[i].e);
            a[i].s++;
            a[i].e++;
            a[i].id = i;
        }
        sort(a + 1, a + n + 1, cmp);
        for (int i = 1; i <= n; i++)
        {
            if (a[i].s == a[i-1].s && a[i].e == a[i-1].e)//若s和e均相同则答案和前一个一样
                ans[a[i].id] = ans[a[i-1].id];
            else  ans[a[i].id] = sum(a[i].s);
            add(a[i].s);
        }
        for (int i = 1; i < n; i++)
            printf("%d ", ans[i]);
        printf("%d\n", ans[n]);
    }
    return 0;
}
