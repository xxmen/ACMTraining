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
int Kruskal()
{
    sort(edge.begin(), edge.end(), cmp);
    int ans = 100000;
    for (int fir = 0; fir < edge.size(); fir++)
    {
        for (int i = 1; i <= n; i++)
            fa[i] = i;
        int mi = 1000000, ma = 0, tot = 0;
        for (int i = fir; i < edge.size(); i++)
        {
            int u, v, w;
            u = edge[i].u, v = edge[i].v, w = edge[i].w;
            if (Find(fa[u]) == Find(fa[v])) continue;
            Union(u, v);
            tot++;
            if (w < mi) mi = w;
            if (w > ma) ma = w;
        }
        if (tot < n - 1) continue;
        if (ma - mi < ans) ans = ma - mi;
    }
    if (ans > 10000) return -1;
    return ans;
}
int main()
{
    while (~scanf("%d%d", &n, &m) && n + m)
    {
        edge.clear();
        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            edge.push_back(node(u, v, w));
        }
        printf("%d\n", Kruskal());
    }
    return 0;
}
