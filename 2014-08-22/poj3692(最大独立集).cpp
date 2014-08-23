//互相不认识的两个人连边，转化为补图的最大独立集
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int n, m, a[205][205], c[205];
bool vis[205];
bool find(int x)
{
    for (int i = 1; i <= m; i++)
    {
        if (a[x][i] && !vis[i])
        {
            vis[i] = true;
            if (c[i] == 0 || find(c[i]))
            {
                c[i] = x;
                return true;
            }
        }
    }
    return false;
}
int hungary()
{
    int sum = 0;
    memset(c, 0, sizeof(c));
    for (int i = 1; i <= n; i++)
    {
        memset(vis, false, sizeof(vis));
        if (find(i)) sum++;
    }
    return sum;
}
int main()
{
    int k, Case = 0;
    while (scanf("%d%d%d", &n, &m, &k) && n+m+k)
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                a[i][j] = 1;
        for (int i = 0; i < k; i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            a[x][y] = 0;
        }
        printf("Case %d: %d\n", ++Case, n + m - hungary());
    }
    return 0;
}