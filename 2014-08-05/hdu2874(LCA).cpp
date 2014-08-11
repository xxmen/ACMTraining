//RMQ+LCA+并查集
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
using namespace std;
const int M = 10005;
struct edge{
    int u,v,d;
    int next;
}e[2 * M];
int fa[M], head[M], dis[M], dep[2 * M], a[2 * M], hash[M],fir[M], f[2 * M][20];
bool vis[M];
int n, m, c, p = 0, tot = 0;
void INIT(int n)
{
    p = 0;
    tot = 0;
    memset(hash, 0, sizeof(hash));
    memset(head, 0, sizeof(head));
    memset(vis, false, sizeof(vis));
    memset(e, 0, sizeof(e));
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= n; i++)
        fa[i] = i;
}
void Add_edge(int x, int y, int l)
{
    e[++tot].u = x;
    e[tot].v = y;
    e[tot].d = l;
    e[tot].next = head[x];
    head[x] = tot;
}
int Find(int x)
{
    if (x != fa[x]) fa[x] = Find(fa[x]);
    return fa[x];
}

void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if(x == y) return;
    if(x < y)  fa[y] = x;
    else fa[x] = y;
}
void RMQ()
{
    int N = 2 * n - 1;
    for(int i = 1; i <= N; i++)
        f[i][0] = i;
    for(int j = 1; 1 << j <= N; j++)
    {
        int k = 1 << (j-1);
        for(int i = 1; i+k < N; i++)
        {
            if(dep[f[i][j-1]] <= dep[f[i+k][j-1]])
                f[i][j] = f[i][j-1];
            else
                f[i][j] = f[i+k][j-1];
        }
    }
}
int Query(int x,int y)
{
    int len = log(double(y - x + 1)) / log(2.0);
    if(dep[f[x][len]] <= dep[f[y - (1<<len) + 1][len]])
        return f[x][len];
    else
        return f[y - (1<<len) + 1][len];
}
int LCA(int x, int y)
{
    if (fir[x] < fir[y])
        return a[Query(fir[x], fir[y])];
    else return a[Query(fir[y], fir[x])];
}
void Dfs(int x, int depth)//得到树的遍历序列
{
    a[++p] = x;
    dep[p] = depth;
    fir[x] = p;
    vis[x] = true;
    for(int i = head[x]; i; i = e[i].next)
    {
        int x1 = e[i].v;
        if(vis[x1]) continue;
        dis[x1] = dis[x] + e[i].d;;
        Dfs(x1, depth + 1);
        a[++p] = x;
        dep[p] = depth;
    }
}
int main()
{
    while (~scanf("%d%d%d", &n, &m, &c))
    {
        INIT(n);
        for (int i = 1; i <= m; i++)
        {
            int x,y,l;
            scanf("%d%d%d", &x, &y, &l);
            Add_edge(x, y, l);
            Add_edge(y, x, l);
            Union(x, y);
        }
        for(int i = 1; i <= n; i++)
            hash[Find(fa[i])] = 1;
        for(int i = 1; i <= n; i++)//添加一个超级根节点，是其成为树
        {
            if(hash[i])
            {
                Add_edge(0, i, 0);
                Add_edge(i, 0, 0);
            }
        }
        dis[0] = 0;
        Dfs(0, 0);
        RMQ();
        while (c--)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            if (Find(x) != Find(y))
            {
                printf("Not connected\n");
                continue;
            }
            int lca = LCA(x, y);
            int ans = dis[x] + dis[y] - 2 * dis[lca];
            printf("%d\n", ans);
        }
    }
    return 0;
}

