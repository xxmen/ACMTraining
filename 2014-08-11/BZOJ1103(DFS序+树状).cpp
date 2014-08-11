//DFS序+树状数组更新区间，单点求和
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;
const int maxn = 250005;
int n, m = 0, root, q, t, head[maxn], l[maxn], r[maxn], c[maxn], dis[maxn];
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
    while (x > 0)
    {
        c[x] += y;
        x -= lowbit(x);
    }
}
int sum(int x)
{
    int s = 0;
    while (x <= n)
    {
        s += c[x];
        x += lowbit(x);
    }
    return s;
}

void dfs(int x)
{
    l[x] = ++t;
    vis[x] = true;
    for(int i = head[x]; i; i = e[i].next)
    {
        int x1 = e[i].v;
        if(vis[x1]) continue;
        dis[x1] = dis[x] + 1;
        dfs(x1);
    }
    r[x] = t;
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
        while (!sta.empty()) sta.pop();
        dis[1] = 0;
        dfs(1);
        for (int i = 2; i <= n; i++)
        {
            add(l[i] - 1, -dis[i]);
            add(l[i], dis[i]);
        }
        scanf("%d", &q);
        for (int i = 0; i < n + q - 1; i++)
        {
            char s[5];
            int x, y;
            scanf("%s", s);
            if (s[0] == 'W')
            {
                scanf("%d", &x);
                printf("%d\n", sum(l[x]));
            }
            else{
                scanf("%d%d", &x, &y);
                add(l[y] - 1, 1);
                add(r[y], -1);
            }
        }
        
    }
    return 0;
}