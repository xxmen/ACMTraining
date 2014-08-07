/*
    第一次从左到右使用树状数组算出每个数左边比它小的个数f1[i],
    第二次从右到左算出每个数右边比它小的个数f2[i],
    f1[i]与f2[i]相乘即为以第i个数为中心的符合条件的三元组的个数
 */
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long LL;
int M, c[50010], a[50010], f1[50010], f2[50010];
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
    while (~scanf("%d", &n))
    {
        M = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            M = max(M, a[i]);
            a[i]++;
        }
        memset(c, 0, sizeof(c));
        for (int i = 0; i < n; i++)
        {
            f1[i] = sum(a[i] - 1);
            add(a[i]);
        }
        memset(c, 0, sizeof(c));
        for (int i = n - 1; i >= 0; i--)
        {
            f2[i] = sum(a[i] - 1);
            add(a[i]);
        }
        LL ans = 0;
        for (int i = 0; i < n; i++)
            ans += LL(f1[i] * f2[i]);
        printf("%lld\n", ans);
    }
    return 0;
}
