#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
const int N = 100010;
struct node {
    int u, v, w, c;
    node() {}
    node(int _u, int _v, int _w, int _c):u(_u), v(_v), w(_w), c(_c) {}
};
vector<node> edge[2];
bool cmp(const node &x, const node &y)
{
    return x.w < y.w;
}
int n, m, fa[N], Case = 0, f[50];
int Find(int x)
{
    return fa[x] == x ? x : fa[x] = Find(fa[x]);
}
void Union(int x, int y)
{
    int fx = Find(x), fy = Find(y);
    fa[fx] = fy;
}
int Kruskal(int k)
{
    sort(edge[k].begin(), edge[k].end(), cmp);
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    int mst = 0;
    int tot = 0;
    for (int i = 0; i < edge[k].size(); i++)
    {
        int u = edge[k][i].u, v = edge[k][i].v, w = edge[k][i].w, col = edge[k][i].c;
        if (Find(fa[u]) == Find(fa[v])) continue;
        Union(u, v);
        mst += w;
        if (col) tot++;
    }
    return tot;
}
int main()
{
    f[0] = 1; f[1] = 1;
    for (int i = 2; i <= 30; i++)
        f[i] = f[i - 1] + f[i - 2];
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        edge[0].clear();edge[1].clear();
        for (int i = 1; i <= n; i++)
            fa[i] = i;
        for (int i = 0; i < m; i++)
        {
            int x, y, col;
            scanf("%d%d%d", &x, &y, &col);
            Union(x, y);
            if (col)
            {
                edge[0].push_back(node(x, y, 0, col));
                edge[1].push_back(node(x, y, 1, col));
            }
            else {
                edge[0].push_back(node(x, y, 1, col));
                edge[1].push_back(node(x, y, 0, col));
            }
        }
        int root = Find(1), flag = 0;
        for (int i = 2; i <= n; i++)
            if (Find(i) != root)
            {
                flag = 1;
                break;
            }
        if (flag)
        {
            printf("Case #%d: No\n", ++Case);
            continue;
        }
        int high = Kruskal(0);//计算最多用到的白色边数
        int low = Kruskal(1);//计算最少用到的白色边数
        //low和high区间内的白色边数一定都存在对应的生成树
        flag = false;
        for (int i = 1; i <= 30; i++)
            if (f[i] >= low && f[i] <= high)
            {
                flag = true;
                break;
            }
        if (flag) printf("Case #%d: Yes\n", ++Case);
        else printf("Case #%d: No\n", ++Case);
    }
    return 0;
}
