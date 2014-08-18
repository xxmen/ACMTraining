#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[1010], b[1010];
int main()
{
    int n;
    while (scanf("%d", &n) && n)
    {
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        for (int i = 1; i <= n; i++)
            scanf("%d", &b[i]);
        sort(a + 1, a + n + 1);
        sort(b + 1, b + n + 1);
        int p = 1, q = n, ans = 0;
        int x = 1, y = n;
        for (int i = 1; i <= n; i++)
        {
            if (a[q] < b[y])
            {
                ans -= 200;
                p++;
                y--;
            }
            else if (a[q] > b[y]){
                ans += 200;
                q--;
                y--;
            }
            else
            {
                if (a[p] > b[x])
                {
                    ans += 200;
                    p++;
                    x++;
                }
                else{
                    if (a[p] < b[y]) ans -= 200;
                    p++;
                    y--;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}