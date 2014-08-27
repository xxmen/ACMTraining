#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
struct edge{
    int v, next;
}e[40010];
int n, m, edgeNum, ru[210], head[210], a[210], ans[210];
bool v[210];
void Init()
{
    memset(head, -1, sizeof(head));
    memset(ru, 0, sizeof(ru));
    edgeNum = 0;
}
void addEdge(int x, int y)
{
    e[edgeNum].v = y;e[edgeNum].next = head[x];head[x] = edgeNum++;
}
int main()
{
    int t;
    scanf("%d", &t);
	while (t--)
	{
        Init();
        scanf("%d%d", &n, &m);
		for (int i = 1; i <= m; i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            addEdge(y, x);//反向建图
            ru[x]++;
        }
        bool flag = true;
        int now = 0;
        memset(v, false, sizeof(v));
        now = n;
        while (now)//编号从大到小
        {
            int k = 0;
            for (int i = n; i >= 1; i--)
            {
                if (v[i]) continue;
                if (!ru[i])
                {
                    v[i] = true;k = i;
                    break;
                }
            }
            if (!k) { flag = false; break;}
            for (int i = head[k]; i != -1; i = e[i].next)
            {
                int y = e[i].v;
                ru[y]--;
            }
            ans[k] = now--;
        }
        if (flag)
        {
            for (int i = 1; i < n; i++)
                printf("%d ",ans[i]);
            printf("%d\n", ans[n]);
        }
        else printf("-1\n");
	}
	return 0;
}
