#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int n, m, a[1111][1111], c[1111], p[1111];
bool b[1111];
bool vis[1111];
bool find(int x)
{
    for (int i = 1; i <= m; i++)
        if (a[x][i] && !vis[i])
        {
            vis[i] = true;
            if (c[i] == 0 || find(c[i]))
            {
                c[i] = x;
                return true;
            }
        }
    return false;
}
void hungary()
{
    int sum = 0;
    memset(c, 0, sizeof(c));
    for (int i = 1; i <= n; i++)
    {
        memset(vis, false, sizeof(vis));
        if (find(i)) sum++;
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        memset(a, 0, sizeof(a));
        for (int i = 1; i <= m; i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            p[i] = x;
            a[x][i] = 1;
            a[y][i] = 1;
        }
        hungary();
        for (int i = 1; i <= m; i++)
            if (!c[i]) c[i] = p[i];
        memset(b, false, sizeof(b));
        for (int i = 1; i <= m; i++)
            b[c[i]] = true;
        bool flag = false;
        for (int i = 1; i <= n; i++)
            if (!b[i])
            {
                flag = true;
                break;
            }
        if (flag)
        {
            printf("NO\n");
            continue;
        }
        for (int i = 1; i < m; i++)
            printf("%d ", c[i]);
        printf("%d\n", c[m]);
    }
    return 0;
}
