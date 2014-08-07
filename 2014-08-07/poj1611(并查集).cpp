#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
int fa[30010];
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
    int n, m;
    while (scanf("%d%d", &n, &m) && n + m)
    {
        for (int i = 0; i < n; i++)
            fa[i] = i;
        for (int i = 0; i < m; i++)
        {
            int k, x, y;
            scanf("%d", &k);
            if (k) scanf("%d", &x);
            for (int j = 1; j < k; j++)
            {
                scanf("%d", &y);
                Union(x, y);
            }
        }
        int root = Find(0), ans = 0;
        for (int i = 0; i < n; i++)
            if (Find(i) == root)
                ans++;
        printf("%d\n", ans);
    }
    return 0;
}
