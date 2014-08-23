//建图:对于同一辆车任务i完成后还能赶上任务j,则连一条i到j的边
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
using namespace std;
struct point{
    int x, y;
}st[505], ed[505];
int n, c[505], Time[505];
vector<int> a[505];
bool vis[505];
bool find(int x)
{
    for (int i = 0; i < a[x].size(); i++)
    {
        int y = a[x][i];
        if (!vis[y])
        {
            vis[y] = true;
            if (c[y] == 0 || find(c[y]))
            {
                c[y] = x;
                return true;
            }
        }
    }
    return false;
}
int hungary()
{
    int sum = 0;
    memset(c, 0, sizeof(c));
    for (int i = 1; i <= n; i++)
    {
        memset(vis, false, sizeof(vis));
        if (find(i)) sum++;
    }
    return sum;
}
bool can(int i, int j)
{
    int t1 = abs(st[i].x - ed[i].x) + abs(st[i].y - ed[i].y);
    int t2 = abs(ed[i].x - st[j].x) + abs(ed[i].y - st[j].y);
    if (Time[i] + t1 + t2 < Time[j])
        return true;
    return false;
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            int h, m;
            scanf("%d:%d %d %d %d %d", &h, &m,&st[i].x,&st[i].y,&ed[i].x,&ed[i].y);
            Time[i] = h * 60 + m;
        }
        for (int i = 1; i <=n; i++)
            a[i].clear();
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++)
                if (can(i, j))
                    a[i].push_back(j);
        printf("%d\n", n - hungary());
    }
    return 0;
}