#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
const int N = 2010;
struct node {
    int u, v, w;
    node() {}
    node(int _u, int _v, int _w):u(_u), v(_v), w(_w) {}
};
vector<node> edge;
int n, m, fa[N];
string s[N];
int Dis(int x, int y)
{
    int d = 0;
    for (int i = 0; i < 7; i++)
        if (s[x][i] != s[y][i]) d++;
    return d;
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
int Kruskal()
{
    sort(edge.begin(), edge.end(), cmp);
    for (int i = 1; i <= n; i++)
            fa[i] = i;
    int mst = 0;
    for (int i = 0; i < edge.size(); i++)
    {
        int u = edge[i].u, v = edge[i].v, w = edge[i].w;
        if (Find(fa[u]) == Find(fa[v])) continue;
        Union(u, v);
        mst += w;
    }
    return mst;
}
int main()
{
    ios::sync_with_stdio(false);
    while (scanf("%d", &n) && n)
    {
        edge.clear();
        for (int i = 1; i <= n; i++)
            cin>>s[i];
        for (int i = 1; i <= n; i++)
            for (int j = 1; j < i; j++)
            {
                int w = Dis(i, j);
                edge.push_back(node(i, j, w));
            }
        int ans = Kruskal();
        printf("The highest possible quality is 1/%d.\n", ans);
    }
    return 0;
}
