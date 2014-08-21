#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
const int INF = 0x3f3f3f;
int d[201][201];
int main()
{
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {
        memset(d, 0x3f, sizeof(d));
        for (int i = 0; i < n; i++)
            d[i][i] = 0;
        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            d[u][v] = min(d[u][v], w);//注意重边!!!
            d[v][u] = min(d[v][u], w);
        }
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    if (d[i][k] < INF && d[k][j] < INF)
                        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        int s, t;
        scanf("%d%d", &s, &t);
        if (d[s][t] < INF)
            printf("%d\n", d[s][t]);
        else printf("-1\n");
    }
    return 0;
}
