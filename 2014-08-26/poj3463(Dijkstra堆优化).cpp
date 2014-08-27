//计算最短路和比最短路长1的路径数
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
struct Node{
    int d, u, flag;
    Node (int _d, int _u, int _flag) {d = _d;u = _u;flag = _flag;}
    bool operator < (const Node &x) const{
        return d > x.d;
    }
};
struct edge{
    int v, w, next;
}e[10010];
int n, m, edgeNum, dis[1111][2], head[1111], c[1111][2];
void Init()
{
    memset(head, -1, sizeof(head));
    edgeNum = 0;
}
void addEdge(int x, int y, int w)
{
    e[edgeNum].v = y;e[edgeNum].next = head[x];e[edgeNum].w = w;head[x] = edgeNum++;
}
int Dijkstra(int st, int ed)
{
    priority_queue<Node> q;
    memset(dis, 0x3f, sizeof(dis));
    dis[st][0] = dis[st][1] = 0;
    c[st][0] = c[st][1] = 1;
    Node x = Node(0, st, 0);
    q.push(x);
    while (!q.empty())
    {
        x = q.top();
        q.pop();
        int u = x.u, dis_now = x.d, kind = x.flag;
        if (dis_now != dis[u][kind]) continue;
        for (int i = head[u]; i != -1; i = e[i].next)
        {
            int v = e[i].v, w = e[i].w;
            if (dis_now + w < dis[v][0])//更新最短路
            {
                c[v][1] = c[v][0];
                c[v][0] = c[u][0];
                dis[v][1] = dis[v][0];
                dis[v][0] = dis_now + w;
                q.push(Node(dis[v][0], v, 0));
                q.push(Node(dis[v][1], v, 1));
            }
            else if (dis_now + w == dis[v][0]) c[v][0] += c[u][0];//累加路径数
            else if (dis_now + w < dis[v][1])//更新次短路
            {
                dis[v][1] = dis_now + w;
                c[v][1] = c[u][kind];
                q.push(Node(dis[v][1], v, 1));
            }
            else if (dis_now + w == dis[v][1]) c[v][1] += c[u][kind];//累加路径数
        }
    }
    int sum = c[ed][0];
    if (dis[ed][1] == dis[ed][0] + 1) sum += c[ed][1];
    return sum;
}
int main()
{
	int t;
    scanf("%d", &t);
    while (t--)
    {
        memset(head, -1, sizeof(head));
        edgeNum = 0;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < m; i++)
        {
            int x, y, l;
            scanf("%d%d%d", &x, &y, &l);
            addEdge(x, y, l);
        }
        int s, f;
        scanf("%d%d", &s, &f);
        printf("%d\n", Dijkstra(s, f));
    }
	return 0;
}
