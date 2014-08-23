//左侧点对应出度，右侧点对应入度建立二分图，有向无环图最小路径覆盖 = 顶点数 - 最大匹配数
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int n, m, a[121][121], c[121];
bool vis[121];
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
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        memset(a, 0, sizeof(a));
        for (int i = 0; i < m; i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            a[x][y] = 1;
        }
        m = n;
        printf("%d\n", n - hungary());
    }
    return 0;
}