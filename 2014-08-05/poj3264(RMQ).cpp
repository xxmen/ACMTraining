//RMQ
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
int a[50005];
int f1[50005][20],f2[50005][20];
int main()
{
    int n,m;
    while (~scanf("%d%d", &n, &m))
    {
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            f1[i][0] = a[i];
            f2[i][0] = a[i];
        }
        for (int j = 1; j <= 20; j++)//RMQ预处理区间最值
            for (int i = 1; i <= n; i++)
            {
                if (i + (1<<j) - 1 > n) break;
                f1[i][j] = max(f1[i][j - 1], f1[i + (1<<(j-1))][j - 1]);
                f2[i][j] = min(f2[i][j - 1], f2[i + (1<<(j-1))][j - 1]);
            }
        for (int i = 0; i < m; i++)
        {
            int x, y, k , ans;
            scanf("%d%d", &x, &y);
            k = int(log(double(y - x) + 1.0)/log(2.0));
            ans = max(f1[x][k], f1[y - (1<<k) + 1][k]) - min(f2[x][k], f2[y - (1<<k) + 1][k]);//查询
            printf("%d\n", ans);
        }
    }
    return 0;
}
