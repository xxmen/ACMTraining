#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
const int maxn = 40010;
vector< pair<int, int> > query[40010];
struct edge{
    int v, w, next;
}e[2 * maxn];
int n, m, fa[maxn], head[maxn], dis[maxn], edgeNum, ans[10010];
bool v[maxn];
void addEdge(int u, int v, int w)
{
    e[++edgeNum].v = v;
    e[edgeNum].w = w;
    e[edgeNum].next = head[u];
    head[u] = edgeNum;
}
int Find(int x)
{
    return fa[x] == x ? x : fa[x] = Find(fa[x]);
}
void Tarjan(int x)
{
    for (int i = 0; i < query[x].size(); i++)
    {
        int y = query[x][i].first;
        if (v[y])
        {
            int lca = Find(y);
            ans[query[x][i].second] = dis[x] + dis[y] - 2 * dis[lca];
        }
    }
    v[x] = true;
    fa[x] = x;
    for (int i = head[x]; i > 0; i = e[i].next)
    {
        int y = e[i].v;
        if (v[y]) continue;
        dis[y] = dis[x] + e[i].w;
        Tarjan(y);
        fa[y] = x;
    }
}
void init()
{
    edgeNum = 0;
    memset(head, 0, sizeof(head));
    memset(v, false, sizeof(v));
    for (int i = 1; i <= n; i++)
        query[i].clear();
}
int main()
{
    while (~scanf("%d%d", &n, &m))
    {
        init();
        for (int i = 1; i <= m; i++)
        {
            int x, y, l;
            char ch[2];
            scanf("%d%d%d%s", &x, &y, &l, ch);
            addEdge(x, y, l);
            addEdge(y, x, l);
        }
        int k;
        scanf("%d", &k);
        for (int i = 0; i < k; i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            query[x].push_back(make_pair(y, i));
            query[y].push_back(make_pair(x, i));
        }
        dis[1] = 0;
        Tarjan(1);
        for (int i = 0; i < k; i++)
            printf("%d\n", ans[i]);
    }
    return 0;
}

