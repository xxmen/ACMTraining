//01背包+输出取物品方案
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int a[105], ans[105];
bool b[105], used[100005][105];
int f[100005];
int main()
{
    int n, m;
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    memset(f, 0, sizeof(f));
    memset(used, false, sizeof(used));
    f[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= a[i]; j--)
        {
            if (f[j-a[i]])
                used[j][i] = true;
            f[j] += f[j-a[i]];
        }
    }
    if (f[m] == 0) { printf("%d\n", 0); return 0;}
    if (f[m] > 1)  { printf("%d\n", -1); return 0;}
    memset(b, false, sizeof(b));
    while (m > 0)
    {
        for (int i = 1; i <= n; i++)
            if (used[m][i])
            {
                m -= a[i];
                b[i] = true;
                break;
            }
    }
    bool fir = true;
    for (int i = 1; i <= n; i++)
    {
        if (!b[i])
        {
            if (fir)
            {
                printf("%d", i);
                fir = false;
            }
            else printf(" %d", i);
        }
    }
    printf("\n");
    return 0;
}
