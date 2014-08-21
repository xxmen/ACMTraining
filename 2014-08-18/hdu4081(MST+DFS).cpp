/*
先求一棵最小生成树，然后枚举每一条最小生成树上的边，删掉后变成两个生成树，然后找两个集合中点权最大的两个连接起来。这两个点中必然有权值最大的那个点，所以直接从权值最大的点开始dfs。
 
 　　 　 求出MST后依次枚举，删去MST上的每一条边，MST变成两棵树T1和T2，然后在剩余的边（即不在MST上的边），以及这条删去的边中找到该边的两点的权值和最大以及能够连接T1和T2的边，A=删去边后的替换边的两点的权值和，B=删去该边后的MST的值，A分别是T1和T2中最大的两个点，则所有点中权值最大的点一定在A中，由此在MST上从权值最大的点作为root，开始dfs。递归求出子树中的每个最大的点并更新答案。
 */
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 1010;
int n, mst_sum, edgeNum, maxp, root, fa[maxn], p[maxn], head[maxn], X[maxn], Y[maxn];
bool v[maxn];
double sum, ans;
struct node{
    int u, v;
    double w;
    node() {}
    node(int _u, int _v, double _w):u(_u), v(_v), w(_w) {}
};
struct EDGE{
    int v;
    double w;
    int next;
}mst[2 * maxn];
vector<node> edge;
void addEdge(int u,int v,double w)
{
    mst[mst_sum].v = v;
    mst[mst_sum].w = w;
    mst[mst_sum].next = head[u];
    head[u] = mst_sum++;
}
bool cmp(const node &x, const node &y)
{
    return x.w < y.w;
}
int Find(int x)
{
    return fa[x] == x ? x : fa[x] = Find(fa[x]);
}
void Union(int x, int y)
{
    int fx = Find(x), fy = Find(y);
    fa[fx] = fy;
}
double Kruskal()
{
    sort(edge.begin(), edge.end(), cmp);
    double len = 0.0;
    for (int i = 0; i < edge.size(); i++)
    {
        int u, v;
        double w;
        u = edge[i].u, v = edge[i].v, w = edge[i].w;
        if (Find(fa[u]) == Find(fa[v])) continue;
        Union(u, v);
        len += w;
        addEdge(u, v, w);
        addEdge(v, u, w);
    }
    return len;
}
int dfs(int x)
{
    v[x] = true;
    int t_max = p[x];
    for (int i = head[x]; i != -1; i = mst[i].next)//枚举每条边
    {
        int y = mst[i].v;
        if (v[y]) continue;
        int temp = dfs(y);//子树中的最大人口数
        t_max = max(t_max, temp);
        ans = max(ans, (temp + maxp) / (sum - mst[i].w));
    }
    return t_max;
}
void init()
{
    edge.clear();//记得清空!!!
    ans = 0;
    mst_sum = edgeNum = 0;
    sum = 0;
    maxp = 0;
    memset(v, false, sizeof(v));
    memset(head, -1, sizeof(head));
    for (int i = 1; i <= n; i++)
        fa[i] = i;
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        init();
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d%d", &X[i], &Y[i], &p[i]);
            if (p[i] > maxp)
            {
                maxp = p[i];
                root = i;
            }
        }
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++)
            {
                double w = sqrt((double)((X[i]-X[j])*(X[i]-X[j])+(Y[i]-Y[j])*(Y[i]-Y[j])));
                edge.push_back(node(i, j, w));
            }
        sum = Kruskal();
        dfs(root);
        printf("%.2lf\n", ans);
    }
    return 0;
}