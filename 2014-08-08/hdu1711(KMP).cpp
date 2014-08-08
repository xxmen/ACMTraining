#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int n, m, ans = 0, next[10010];
int a[10010], b[1000010];
void cal_next()
{
    next[1] = 0;
    int j = 0;
    for (int i = 2; i <= n; i++)
    {
        while (j > 0 && a[j+1] != a[i]) j = next[j];
        if (a[j+1] == a[i]) j++;
        next[i] = j;
    }
}
int kmp()
{
    int j = 0;
    for (int i = 1; i <= m; i++)
    {
        while (j > 0 && a[j+1] != b[i]) j = next[j];
        if (a[j+1] == b[i]) j++;
        if (j == n) return i;
    }
    return  -1;
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &m, &n);
        for (int i = 1; i <= m; i++)
            scanf("%d", &b[i]);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        cal_next();
        int ans = kmp();
        if (ans > 0) ans -= n - 1;
        printf("%d\n", ans);
    }
    return 0;
}
