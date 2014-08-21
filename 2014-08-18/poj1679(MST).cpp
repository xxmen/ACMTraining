#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 111;
struct node {
    int u, v, w;
    node() {}
    node(int _u, int _v, int _w):u(_u), v(_v), w(_w) {}
};
vector<node> edge;
int n, m, fa[N];
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
int num[111];
int Kruskal()
{
    sort(edge.begin(), edge.end(), cmp);
    for (int i = 1; i <= n; i++)
            fa[i] = i;
    int mst = 0, s = 0;
    for (int i = 0; i < edge.size(); i++)
    {
        int u = edge[i].u, v = edge[i].v, w = edge[i].w;
        if (Find(fa[u]) == Find(fa[v])) continue;
        Union(u, v);
        num[s++] = i;
        mst += w;
    }
    //求次小生成树
    int ans = mst;
    for (int i = 0; i < s; i++)//枚举删去的边
    {
        int sum = 0, tot = 0;
        for (int j = 1; j <= n; j++)
            fa[j] = j;
        for (int j = 0; j < edge.size(); j++)
        {
            if (num[i] == j) continue;
            int u = edge[j].u, v = edge[j].v, w = edge[j].w;
            if (Find(fa[u]) == Find(fa[v])) continue;
            Union(u, v);
            sum += w;
            tot++;
        }
        if (tot < n - 1) continue;//删去mst中的某条边后必须保证联通!
        if (sum == mst)
        {
            ans = -1;
            break;
        }
    }
    return ans;
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        edge.clear();
        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            edge.push_back(node(u, v, w));
        }
        int ans = Kruskal();
        if (ans < 0)
            puts("Not Unique!");
        else printf("%d\n", ans);
    }
    return 0;
}
