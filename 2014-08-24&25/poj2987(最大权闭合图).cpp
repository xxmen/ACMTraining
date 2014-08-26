//最大权闭合图,从源点向每个正收益点连边，容量为收益，从每个负收益点向汇点连边，容量为收益的绝对值。
//最大收益=正收益点权和-最小割=正收益点权和-最大流
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long LL;
const int INF = 1<<30;
struct edge{
    int v, c, next;
}e[120000];
int n, m, ans, minw, edgeNum, head[5010], now[5010], h[5010], gap[5010];
LL flow;
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
bool v[5010];
void dfs(int x)//从源点出发进行dfs,当遇到某个割无法继续dfs时，当前经过的点数即为S集的最小点数
{
    v[x] = true;
    ans++;
    for (int i = head[x]; i != -1; i = e[i].next)
    {
        if (e[i].c == 0) continue;
        int y = e[i].v;
        if (!v[y])
            dfs(y);
    }
}
int main()
{
	while (~scanf("%d%d", &n, &m))
	{
		Init();
        LL sum = 0;
        for (int i = 1; i <= n; i++)
        {
            int x;
            scanf("%d", &x);
            if (x > 0) { sum += x; addEdge(0, i, x);}
            if (x < 0) addEdge(i, n + 1, -x);
        }
        for (int i = 0; i < m; i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            addEdge(x, y, INF);
        }
        memcpy(now, head, sizeof(head));
        MaxFlow(0, n + 1, n + 2);
        ans = -1;
        memset(v, false, sizeof(v));
        dfs(0);
        printf("%d %lld\n", ans, sum - flow);
	}
	return 0;
}
