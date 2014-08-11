#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100005;
int n, m = 0, q, t, head[maxn], l[maxn], r[maxn], c[maxn], a[maxn];
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
void dfs(int x)
{
    l[x] = ++t;
    vis[x] = true;
    for(int i = head[x]; i; i = e[i].next)
    {
        int x1 = e[i].v;
        if(vis[x1]) continue;
        dfs(x1);
    }
    r[x] = t;
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
int main()
{
    while (~scanf("%d", &n))
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
        dfs(1);
        for (int i = 1; i <=n; i++)
        {
            add(i, 1);
            a[i] = 1;
        }
        scanf("%d", &q);
        while (q--)
        {
            char s[5];
            int x;
            scanf("%s%d", s, &x);
            if (s[0] == 'C')
            {
                if (a[x] == 1) { a[x] = 0; add(l[x], -1);}
                else { a[x] = 1; add(l[x], 1); }
            }
            else{
                int ans = sum(r[x]) - sum(l[x] - 1);
                printf("%d\n", ans);
            }
        }
    }
    return 0;
}