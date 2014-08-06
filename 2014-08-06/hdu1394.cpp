#include <cstdio>
#include <algorithm>
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
using namespace std;
const int maxn = 200010;
int a[5005], b[5005];
int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        memset(b, 0, sizeof(b));
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
                if (a[i] > a[j]) b[i]++;
            ans += b[i];
        }
        int s = ans;
        for (int i = 0; i < n - 1; i++)
        {
            s -= a[i];
            s += n - a[i] - 1;
            ans = min(ans, s);
        }
        printf("%d\n", ans);
    }
    return 0;
}
