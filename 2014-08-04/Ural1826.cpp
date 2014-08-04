//过河问题
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int a[105];
int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        sort(a+1, a + n + 1);
        int ans = 0, i;
        for (i = n; i > 2; i -= 2)
            ans += min(2*a[1] + a[i] + a[i-1], a[2] + a[1] + a[i] + a[2]);
        if (i == 2) ans += a[2];
        else ans -= a[1];
        printf("%d\n", ans);
    }
    return 0;
}
