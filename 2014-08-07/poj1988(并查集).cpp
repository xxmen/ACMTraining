#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
int fa[100000], ans[100000], sum[100000];
int Find(int x)
{
    if (fa[x] == x)
        return x;
    else{
        int fx = fa[x];
        fa[x] = Find(fa[x]);
        ans[x] += ans[fx];
        return fa[x];
    }
}
void Union(int x, int y)
{
    ans[x] += sum[y];
    fa[x] = y;
    sum[y] += sum[x];
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
        ans[i] = 0;
        sum[i] = 1;
    }
    char s[2];
    for (int i = 0; i < n; i++)
    {
        scanf("%s", s);
        int x, y;
        if (s[0] == 'C')
        {
            scanf("%d", &x);
            Find(x);
            printf("%d\n", ans[x]);
        }
        else
        {
            scanf("%d%d", &x, &y);
            int fx = Find(x), fy = Find(y);
            if (fx != fy) Union(fx, fy);
        }
    }
    return 0;
}
