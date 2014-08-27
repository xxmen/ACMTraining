#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long LL;
const int INF = 1<<30;
const int maxn = 1000;
struct edge{
    int v, c, next;
}e[50000];
int n, m, flow, minw, edgeNum, head[maxn], now[maxn], h[maxn], gap[maxn];
char a[21][21];
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
        return;    }
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
    int d;
	while (~scanf("%d%d%d%*c", &n, &m, &d))
	{
		Init();
        int M = n * m;
        int N = 2 * M + 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                scanf("%c", &a[i][j]);
                if (a[i][j] > '0')
                {
                    int high = a[i][j] - '0';
                    addEdge(id(i, j), id(i, j) + M, high);
                }
            }
            scanf("%*c");
        }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                if (a[i][j] == '0') continue;
                for (int x1 = max(1, i - d); x1 <= min(i + d, n); x1++)
                    for (int y1 = max(1, j - d); y1 <= min(j + d, m); y1++)
                    {
                        if (a[x1][y1] == '0') continue;
                        int dis = abs(x1 - i) + abs(y1 - j);
                        if (!dis || dis > d) continue;
                        addEdge(id(i, j) + M, id(x1, y1), INF);
                    }
                if (i <= d || j <= d || i > n - d || j > m - d)
                    addEdge(id(i, j) + M, N, INF);
            }
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            char ch;
            for (int j = 1; j <= m; j++)
            {
                scanf("%c", &ch);
                if (ch == 'L')
                {
                    sum++;
                    addEdge(0, id(i, j), 1);
                }
            }
            scanf("%*c");
        }
        memcpy(now, head, sizeof(head));
        MaxFlow(0, N, N + 1);
        printf("%d\n", sum - flow);
	}
	return 0;
}
