//最小点覆盖
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int n, m, a[105][105], c[105];
bool vis[105];
bool find(int x)
{
    for (int i = 0; i < m; i++)
    {
        if (a[x][i] && !vis[i])
        {
            vis[i] = true;
            if (c[i] == -1 || find(c[i]))
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
    memset(c, -1, sizeof(c));
    for (int i = 0; i < n; i++)
    {
        memset(vis, false, sizeof(vis));
        if (find(i)) sum++;
    }
    return sum;
}
int main()
{
    int k;
    while (scanf("%d", &n) && n)
    {
        scanf("%d%d", &m, &k);
        memset(a, 0, sizeof(a));
        for (int i = 0; i < k; i++)
        {
            int num, x, y;
            scanf("%d%d%d", &num, &x, &y);
            if (!x || !y) continue;//机器刚开始处于0，无需重启，不用加边！
            a[x][y] = 1;
        }
        printf("%d\n", hungary());
    }
    return 0;
}