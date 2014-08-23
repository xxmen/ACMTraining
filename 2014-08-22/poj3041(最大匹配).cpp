#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int n, m, a[505][505], c[505];
bool vis[505];
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
    int k;
    while (~scanf("%d%d", &n, &k))
    {
        memset(a, 0, sizeof(a));
        for (int i = 0; i < k; i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            a[x][y] = 1;
        }
        m = n;
        printf("%d\n", hungary());
    }
    return 0;
}
