#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int maxn = 510000;
int a[maxn], b[maxn], c[maxn];
bool cmp(int x, int y)
{
    return x > y;
}
int lowbit(int x)
{
    return x & -x;
}
void add(int x)
{
    while (x <= maxn)
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
int Bin(int key,int n,int X[])
{
	int l = 1 , r = n;
	while (l <= r) {
		int m = (l + r) >> 1;
		if (X[m] == key) return m;
		if (X[m] > key) l = m + 1;
		else r = m - 1;
	}
	return -1;
}
int main()
{
    int n;
    while (scanf("%d", &n) && n)
    {
        memset(c, 0, sizeof(c));
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            a[i]++;
            b[i] = a[i];
        }
        sort(b + 1, b + n + 1, cmp);
        for (int i = 1; i <= n; i++)
        {
            int x = a[i];
            a[i] = Bin(x, n, b);
        }
        long long ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans += sum(a[i] - 1);
            add(a[i]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
