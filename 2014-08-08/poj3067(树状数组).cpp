#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
struct cow{
    int s, e;
}a[1000010];
int c[1000010];
int M = 0;
bool cmp(cow x, cow y)
{
    if (x.s == y.s)
        return x.e < y.e;
    return x.s < y.s;
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
    int t, Case = 0;
    scanf("%d", &t);
    while (t--)
    {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        M = max(n,m);
        memset(c, 0, sizeof(c));
        for (int i = 1; i <= k; i++)
            scanf("%d%d", &a[i].s, &a[i].e);
        sort(a + 1, a + k + 1, cmp);
        long long ans = 0, now = 0;
        add(a[1].e);
        for (int i = 2; i <= k; i++)
        {
            if (a[i].s != a[i-1].s || a[i].e != a[i-1].e)
                now = i - 1 - sum(a[i].e);
            ans += now;
            add(a[i].e);
        }
        printf("Test case %d: %lld\n", ++Case, ans);
    }
    return 0;
}
