#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 1010;
double p[maxn][maxn][3], f[maxn][maxn];
int main()
{
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {
        memset(p, 0, sizeof(p));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                scanf("%lf%lf%lf", &p[i][j][0], &p[i][j][1], &p[i][j][2]);
        f[n][m] = 0;
        for (int i = n; i >= 1; i--)
            for (int j = m; j >= 1; j--)
            {
                if (i == n && j == m) continue;
                if (1.0 - p[i][j][0] < 1e-6)
                    f[i][j] = 0;
                else f[i][j] = (f[i][j + 1] * p[i][j][1] + f[i + 1][j] * p[i][j][2] + 2.0) / (1.0 - p[i][j][0]);
            }
        printf("%.3lf\n", f[1][1]);
    }
    return 0;
}