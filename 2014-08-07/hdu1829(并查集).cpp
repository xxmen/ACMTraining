#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
int fa[4010];
int Find(int x)
{
    return fa[x] == x ? x : fa[x] = Find(fa[x]);
}
void Union(int x, int y)
{
    fa[Find(y)] = Find(x);
}
int main()
{
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas++)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= 2*n; i++)
            fa[i] = i;
        bool flag = false;
        for (int i = 0; i < m; i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            if (flag) continue;
            Union(x + n, y);
            Union(x, y + n);
            if (Find(x) == Find(y) || Find(x + n) == Find(y + n))
                flag = true;
        }
        if (flag) printf("Scenario #%d:\nSuspicious bugs found!\n", cas);
        else printf("Scenario #%d:\nNo suspicious bugs found!\n", cas);
        printf("\n");
    }
    return 0;
}
