#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 10010;
struct edge{
    int v, next;
}e[maxn];
int n, a, b, ans, fa[maxn], head[maxn], ru[maxn], edgeNum;
bool v[maxn];
void addEdge(int u, int v)
{
    e[++edgeNum].v = v;
    e[edgeNum].next = head[u];
    head[u] = edgeNum;
}
int Find(int x)
{
    return fa[x] == x ? x : fa[x] = Find(fa[x]);
}
void Tarjan(int x)
{
    if (x == a && v[b]) { ans = Find(b); return; }
    if (x == b && v[a]) { ans = Find(a); return; }
    v[x] = true;
    fa[x] = x;
    for (int i = head[x]; i > 0; i = e[i].next)
    {
        int y = e[i].v;
        if (v[y]) continue;
        Tarjan(y);
        fa[y] = x;
        if (ans > 0) return;
    }
}
void init()
{
    edgeNum = 0;
    memset(head, 0, sizeof(head));
    memset(ru, 0, sizeof(ru));
    memset(v, false, sizeof(v));
    ans = -1;
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        init();
        for (int i = 1; i < n; i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            addEdge(x, y);
            ru[y]++;
        }
        scanf("%d%d", &a, &b);
        int root = 0;
        for (int i = 1; i <= n; i++)
            if (!ru[i])
            {
                root = i;
                break;
            }
        Tarjan(root);
        printf("%d\n", ans);
    }
    return 0;
}