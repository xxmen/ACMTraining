#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long LL;
const int INF = 1<<30;
const int maxn = 2555;
struct edge{
    int v, c, next;
}e[16000];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int n, m, k, ans, flow, minw, edgeNum, head[maxn], now[maxn], h[maxn], gap[maxn], a[55][55];
bool b[maxn][maxn];
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
	while (~scanf("%d%d%d", &n, &m, &k))
	{
		Init();
        int sum = 0;
        int N = n * m + 1;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                scanf("%d", &a[i][j]);
                sum += a[i][j];
            }
        memset(b, false, sizeof(b));
        for (int i = 1; i <= k; i ++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            b[x][y] = true;
        }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                if ((i + j) & 1)
                {
                    if (b[i][j]) addEdge(0, id(i, j), INF);
                    else addEdge(0, id(i, j), a[i][j]);
                    for (int dir = 0; dir < 4; dir++)
                    {
                        int x1 = i + dx[dir], y1 = j + dy[dir];
                        if (x1 < 1 || x1 > n || y1 < 1 || y1 > m) continue;
                        addEdge(id(i, j), id(x1, y1), 2 * (a[i][j] & a[x1][y1]));
                    }
                }
                else
                {
                    if (b[i][j]) addEdge(id(i, j), N, INF);
                    else addEdge(id(i, j), N, a[i][j]);
                }
            }
        memcpy(now, head, sizeof(head));
        MaxFlow(0, N, N + 1);
        printf("%d\n", sum - flow);
	}
	return 0;
}
