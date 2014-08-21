#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
int f[5000000], w[11], v[11], n;
int backpack(int m)
{
    m /= 1000;
    for (int i = 0; i < n; i++)
        for (int j = w[i]; j <= m; j++)
            f[j] = max(f[j], f[j - w[i]] + v[i]);
    return f[m];
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        memset(f, 0, sizeof(f));
        int money, year;
        scanf("%d%d", &money, &year);
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d", &w[i], &v[i]);
            w[i] /= 1000;
        }
        int ans = money;
        for (int i = 0; i < year; i++)
            ans += backpack(ans);
        printf("%d\n", ans);
    }
    return 0;
}
