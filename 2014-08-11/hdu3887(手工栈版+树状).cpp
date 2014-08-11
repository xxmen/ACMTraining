#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;
const int maxn = 100005;
int n, m = 0, root, q, head[maxn], c[maxn], ans[maxn];
bool vis[maxn];
stack<int> sta;
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
void dfs(int root)
{
    sta.push(root);
    while (!sta.empty())
    {
        int x = sta.top();
        if (vis[x])
        {
            ans[x] = sum(x - 1) - ans[x];
            sta.pop();
        }
        else{
            vis[x] = true;
            ans[x] = sum(x - 1);
            add(x, 1);
            for (int i = head[x]; i; i = e[i].next)
                if (!vis[e[i].v]) sta.push(e[i].v);
        }
    }
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
        memset(vis, false, sizeof(vis));
        while (!sta.empty()) sta.pop();
        dfs(root);
        for (int i = 1; i < n; i++)
            printf("%d ", ans[i]);
        printf("%d\n",ans[n]);
    }
    return 0;
}