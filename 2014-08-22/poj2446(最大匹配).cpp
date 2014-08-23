#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 1111;
int n, m, a[50][50], c[maxn], e[maxn][5];
bool vis[maxn];
bool find(int x)
{
    for (int i = 1; i <= e[x][0]; i++)
    {
        int y = e[x][i];
        if (!vis[y])
        {
            vis[y] = true;
            if (c[y] == 0 || find(c[y]))
            {
                c[y] = x;
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
inline int id(int x, int y)
{
    return (x - 1) * m + y;
}
void addEdge(int u, int v)
{
    e[u][0]++;
    e[u][e[u][0]] = v;
}
void build_Graph()
{
    memset(e, 0, sizeof(e));
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j]) continue;
            int u = id(i, j);
            for (int k = 0; k < 4; k++)
            {
                int x = i + dx[k], y = j + dy[k];
                if (x < 1 || x > n || y < 1 || y > m)
                    continue;
                if (a[x][y]) continue;
                addEdge(u, id(x, y));
            }
        }
}
int main()
{
    int k;
    while (~scanf("%d%d%d", &n, &m, &k))
    {
        memset(a, 0, sizeof(a));
        for (int i = 0; i < k; i++)
        {
            int x, y;
            scanf("%d%d", &y, &x);
            a[x][y] = 1;
        }
        build_Graph();
        n *= m;
        m = n;
        if (hungary() >= n - k)
            puts("YES");
        else puts("NO");
    }
    return 0;
}
