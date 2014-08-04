#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int a[5] = {1,5,10,25,50};
int f[10005],ans[10005];
int main()
{
    int m, n = 5, M = 7489;
    memset(f, 0, sizeof(f));
    f[0] = 1;
    for (int i = 0; i < n; i++)
        for (int j = M; j >= a[i]; j--)
        {
            for (int k = 1; j - k * a[i] >= 0; k++)
                f[j] += f[j - k * a[i]];
            ans[j] = f[j];
        }
    while (~scanf("%d", &m))
        printf("%d\n", ans[m]);
    return 0;
}
