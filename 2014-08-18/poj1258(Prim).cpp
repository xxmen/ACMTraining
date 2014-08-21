#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
const int INF = 0x3f3f3f;
int n, a[101][101], dis[101];
bool v[101];
int prim()
{
    memset(v, false, sizeof(v));
    memset(dis, 0x3f, sizeof(dis));
    dis[1] = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int mi = INF, k = 0;
        for (int j = 1; j <= n; j++)
            if (!v[j] && dis[j] < mi)
            {
                mi = dis[j];
                k = j;
            }
        if (!k) break;
        v[k] = true;
        ans += mi;
        for (int j = 1; j <= n; j++)
            if (!v[j] && dis[j] > a[k][j])
                dis[j] = a[k][j];
    }
    return ans;
}
int main()
{
    while (~scanf("%d", &n))
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                scanf("%d", &a[i][j]);
        printf("%d\n", prim());
    }
    return 0;
}
