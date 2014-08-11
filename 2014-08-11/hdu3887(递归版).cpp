#include <cstdio>
#include <cmath>
#include <algorithm>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
const int maxn = 100005;
int n, m = 0, root, q, t, head[maxn], c[maxn], ans[maxn];
bool vis[maxn];
struct edge{
    int u,v;
    int next;
}e[2 * maxn];
inline int lowbit(int x)
{
    return x & -x;
}
void addEdge(int x, int y)
{
    e[++m].u = x;
    e[m].v = y;
    e[m].next = head[x];
    head[x] = m;
}
void add(int x, int y)
{
    while (x <= n)
    {
        c[x] += y;
        x += lowbit(x);
    }
}
int sum(int x)
{
    int s = 0;
    while (x > 0)
    {
        s += c[x];
        x -= lowbit(x);
    }
    return s;
}
void dfs(int x)
{
    int tot1 = sum(x - 1);
    vis[x] = true;
    add(x, 1);
    for(int i = head[x]; i; i = e[i].next)
    {
        int x1 = e[i].v;
        if(vis[x1]) continue;
        dfs(x1);
    }
    int tot2 = sum(x - 1);
    ans[x] = tot2 - tot1;
}
int main()
{
    while (scanf("%d%d", &n, &root) && n+root)
    {
        m = 0;
        memset(head, 0, sizeof(head));
        memset(c, 0, sizeof(c));
        for (int i = 1; i < n; i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            addEdge(x, y);
            addEdge(y, x);
        }
        t = 0;
        memset(vis, false, sizeof(vis));
        dfs(root);
        for (int i = 1; i < n; i++)
            printf("%d ", ans[i]);
        printf("%d\n",ans[n]);
    }
    return 0;
}
