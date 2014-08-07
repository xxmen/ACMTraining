#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
struct job{
    int p,d;
}a[10005];
bool v[10005];
bool cmp(job x, job y)
{
    if (x.p == y.p)
        return x.d < y.d;
    return x.p > y.p;
}
int main()
{
    int n;
    while (scanf("%d", &n) == 1)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d", &a[i].p, &a[i].d);
        }
        sort(a, a + n, cmp);
        memset(v, false, sizeof(v));
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int j;
            for (j = a[i].d; j > 0; j--)
            {
                if (v[j]) continue;
                v[j] = true;
                ans += a[i].p;
                break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
