//求一遍最短路，把最短路上的边加到新图中，求最大流，判断最大流量是否为2
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int INF = 0x3f3f3f;
struct edge{
    int v, c, next;
}e[160000];
int n, m, flow, minw, edgeNum, head[500], now[500], h[500], gap[500], dis[410], map[401][401];
bool found;
void Init()
{
    memset(map, 0x3f, sizeof(map));
    memset(head, -1, sizeof(head));
    edgeNum = 0;
}
bool v[410];
void Dijkstra(int st)
{
    memset(dis, 0x3f, sizeof(dis));
    memset(v, false, sizeof(v));
    dis[st] = 0;
    for (int i = 0; i < n; i++)
    {
        int k = 0, mi = INF;
        for (int j = 1; j <= n; j++)
            if (!v[j] && dis[j] < mi)
                mi = dis[k = j];
        if (!k) break;
        v[k] = true;
        for (int j = 1; j <= n; j++)
            dis[j] = min(dis[j], dis[k] + map[k][j]);
    }
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
//沿残留网络中残量为0的正向边走到终点，顺便把残量置1，走两遍就能输出两条路径。
void PrintPath()
{
    int x = 1;
    while (1)
    {
        if(x == n)
        {
            printf("%d\n", x);
            return;
        }
        printf("%d ", x);
        for(int i = head[x]; i != -1; i = e[i].next)
            if((i & 1) == 0 && e[i].c == 0)
            {
                e[i].c = 1, x = e[i].v;
                break;
            }
    }
}
int main()
{
	while (~scanf("%d%d", &n, &m))
	{
        Init();
        for (int i = 0; i < m; i++)
        {
            int x, y, l;
            scanf("%d%d%d", &x, &y, &l);
            map[x][y] = map[y][x] = l;
        }
        Dijkstra(1);
        if(dis[n] == INF)
        {
            printf("No solution\n");
            continue;
        }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (dis[i] + map[i][j] == dis[j])
                    addEdge(i, j, 1);
        addEdge(0, 1, 2);
        MaxFlow(0, n, n + 1);
        if (flow < 2)
        {
            printf("No solution\n");
            continue;
        }
        PrintPath();
        PrintPath();
	}
	return 0;
}