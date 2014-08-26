#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
struct edge{
    int v, c, next;
}e[50000];
int n, m, f, d, flow, minw, edgeNum, head[500], now[500], h[500], gap[500];
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
int main()
{
	while (~scanf("%d%d%d", &n, &f, &d))
	{
        int N = 420;
		Init();
        for (int i = 1; i <= f; i++)
            addEdge(1, 1 + i, 1);
        for (int i = 1; i <= d; i++)
            addEdge(301 + i, N, 1);
        for (int i = 1; i <= n; i++)
        {
            int tf, td;
            scanf("%d%d", &tf, &td);
            int F, D;
            for (int j = 1; j <= tf; j++)
            {
                scanf("%d", &F);
                addEdge(1 + F, 101 + i, 1);
            }
            addEdge(101 + i, 201 + i, 1);
            for (int j = 1; j <= td; j++)
            {
                scanf("%d", &D);
                addEdge(201 + i, 301 + D, 1);
            }
        }
        memcpy(now, head, sizeof(head));
        MaxFlow(1, N, N);
        printf("%d\n", flow);
	}
	return 0;
}