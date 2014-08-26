/*  
 求最小割，但是由于给出的是每个点的容量，所以需要将每个点拆为两个点，之间连边，容量为点的容量，
 两个城市如果相连则容量置为无穷大。然后求最大流看是否大于已有警察数。拆点的时候将点i拆为i和i+n。
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long LL;
const int INF = 1<<30;
const int maxn = 210;
struct edge{
    int v, c, next;
}e[50000];
int n, m, k, s, f, ans, flow, minw, edgeNum, head[maxn], now[maxn], h[maxn], gap[maxn];
bool found;
void Init()
{
    memset(head, -1, sizeof(head));
    edgeNum = 0;
}
void addEdge(int x, int y, int c)
{
    e[edgeNum].v = y;e[edgeNum].next = head[x];e[edgeNum].c = c;head[x] = edgeNum++;
    e[edgeNum].v = x;e[edgeNum].next = head[y];e[edgeNum].c = 0;head[y] = edgeNum++;
}
void SAP(int x, int st, int ed, int n)
{
    if (x == ed)
    {
        found = true;
        flow += minw;
        return;
    }
    int p = now[x], minh = n - 1, mw = minw;
    while (p != -1)
    {
        if (e[p].c > 0 && h[x] == h[e[p].v] + 1)
        {
            minw = min(minw, e[p].c);
            SAP(e[p].v, st, ed, n);
            if (h[st] >= n) return;
            if (found) break;
            minw = mw;
        }
        p = e[p].next;
    }
    if (found)
    {
        e[p].c -= minw;
        e[p ^ 1].c += minw;
    }
    else
    {
        for (p = head[x]; p != -1; p = e[p].next)
        {
            if (e[p].c > 0 && h[e[p].v] < minh)
            {
                minh = h[e[p].v];
                now[x] = p;
            }
        }
        gap[h[x]]--;
        if (!gap[h[x]]) h[st] = n;
        h[x] = minh + 1;
        gap[h[x]]++;
    }
}
void MaxFlow(int st, int ed, int n)
{
    memset(h, 0, sizeof(h));
    memset(gap, 0, sizeof(gap));
    gap[0] = n;
    flow = 0;
    while (h[st] < n)
    {
        found = false;
        minw = 1 << 30;
        SAP(st, st, ed, n);
    }
}
int id(int i, int j)
{
    return (i - 1) * m + j;
}
int main()
{
	while (~scanf("%d", &k))
	{
        scanf("%d%d%d%d", &n, &m, &s, &f);
        Init();
        for (int i = 1; i <= n; i++)
        {
            int R;
            scanf("%d", &R);
            if (i != s && i != f)
                addEdge(i, n + i, R);
        }
        for (int i = 1; i <= m; i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            addEdge(x + n, y, INF);
            addEdge(y + n, x, INF);
        }
        if (s == f)
        {
            puts("NO");
            continue;
        }
        memcpy(now, head, sizeof(head));
        MaxFlow(f + n, s, 2 * n);
        if (flow > k) puts("NO");
        else puts("YES");
	}
	return 0;
}
