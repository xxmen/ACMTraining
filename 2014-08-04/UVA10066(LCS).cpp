#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
int a[105],b[105];
int f[105][105];
int main()
{
    int n,m,Case = 0;
    while (scanf("%d%d", &n, &m) && n+m)
    {
        memset(f,0,sizeof(f));
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        for (int i = 1; i <= m; i++)
            scanf("%d", &b[i]);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                if (a[i] == b[j])
                    f[i][j] = f[i-1][j-1] + 1;
                else f[i][j] = max(f[i][j-1], f[i-1][j]);
            }
        printf("Twin Towers #%d\n", ++Case);
        printf("Number of Tiles : %d\n\n", f[n][m]);
    }
    return 0;
}
