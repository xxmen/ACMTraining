#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 20010, INF = 0x3f3f3f3f;
struct edge{
    int u, v, c, next;
}e[4000010];
int n, m, s, t, flow, edgeNum, head[maxn], d[maxn], cur[maxn], fa[maxn], num[maxn];
bool found;
void Init()
{
    memset(head, -1, sizeof(head));
    edgeNum = 0;
}
void addEdge(int x, int y, int c)
{
    e[edgeNum].u = x;e[edgeNum].v = y;e[edgeNum].next = head[x];e[edgeNum].c = c;head[x] = edgeNum++;
    e[edgeNum].u = y;e[edgeNum].v = x;e[edgeNum].next = head[y];e[edgeNum].c = 0;head[y] = edgeNum++;
}
int augment()
{
    int x = t,a = INF;
    while(x != s)
    {
        a = min(a,e[fa[x]].c);
        x = e[fa[x]].u;
    }
    x = t;
    while(x != s)
    {
        e[fa[x]].c -= a;
        e[fa[x]^1].c += a;
        x=e[fa[x]].u;
    }
    return a;
}

void isap()
{
    int x,ok,Min;
    flow=0;
    memset(d, 0, sizeof(d));
    memset(num, 0, sizeof(num));
    num[0] = n;
    for(int i = 0;i < n; i++)
        cur[i] = head[i];
    x = s;
    while(d[s] < n)
    {
        if(x == t)
        {
            flow += augment();
            x = s;
        }
        ok = 0;
        for(int i = cur[x];i!=-1;i= e[i].next)
        {
            if(e[i].c && d[x] == d[e[i].v] + 1)
            {
                ok = 1;
                fa[e[i].v] = i;
                cur[x] = i;
                x = e[i].v;
                break;
            }
        }
        if(!ok)
        {
            Min = n-1;
            for(int i = head[x]; i != -1; i = e[i].next)
                if(e[i].c && d[e[i].v] < Min)
                    Min = d[e[i].v];
            if(--num[d[x]] == 0) break;
            num[d[x] = Min + 1]++;
            cur[x] = head[x];
            if(x != s)
                x = e[fa[x]].u;
        }
    }
}
int main()
{
	while (~scanf("%d%d", &n, &m))
	{
        Init();
        int N = n + 1;
        for (int i = 1; i <= n; i++)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            addEdge(0, i, a);
            addEdge(i, N, b);
        }
        for (int i = 1; i <= m; i++)
        {
            int x, y, c;
            scanf("%d%d%d", &x, &y, &c);
            addEdge(x, y, c);
            addEdge(y, x, c);
        }
        s = 0;t = N;
        n += 2;
        isap();
        printf("%d\n", flow);
	}
	return 0;
}
