#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
const int N = 1010;
int n, q;
double a[N][N], d[N];
bool vis[N];
double Dijkstra(int s, int t)
{
    for (int i = 1; i <= n; i++)
        d[i] = 0;
    memset(vis, false, sizeof(vis));
    d[s] = a[s][s];
    for (int i = 1; i <= n; i++)
    {
        int k = 0;
        double ma = 0.0;
        for (int j = 1; j <= n; j++)
            if (!vis[j] && d[j] > ma)
                ma = d[j], k = j;
        if (k == 0) break;
        vis[k] = true;
        for (int j = 1; j <= n; j++)
            if (!vis[j] && d[j] < d[k] * a[k][j])
                d[j] = d[k] * a[k][j];
    }
    return d[t];
}
int main()
{
    while (~scanf("%d", &n))
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                scanf("%lf", &a[i][j]);
        scanf("%d", &q);
        for (int i = 0; i < q; i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            double ans = Dijkstra(x, y);
            if (ans < 1e-7) puts("What a pity!");
            else printf("%.3lf\n", ans);
        }
    }
    return 0;
}
