#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
struct point{
    double x, y;
}p[111], q[111];
int n, m, s, v, a[111][111], c[111];
bool vis[111];
bool find(int x)
{
    for (int i = 1; i <= m; i++)
        if (a[x][i] && !vis[i])
        {
            vis[i] = true;
            if (c[i] == 0 || find(c[i]))
            {
                c[i] = x;
                return true;
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
    while (~scanf("%d%d%d%d", &n, &m, &s, &v))
    {
        for (int i = 1; i <= n; i++)
            scanf("%lf%lf", &p[i].x, &p[i].y);
        for (int i = 1; i <= m; i++)
            scanf("%lf%lf", &q[i].x, &q[i].y);
        memset(a, 0, sizeof(a));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                double dis = sqrt((p[i].x - q[j].x)*(p[i].x - q[j].x) + (p[i].y - q[j].y)*(p[i].y - q[j].y));
                if (double(v * s) >= dis)
                    a[i][j] = 1;
            }
        printf("%d\n", n - hungary());
    }
    return 0;
}
