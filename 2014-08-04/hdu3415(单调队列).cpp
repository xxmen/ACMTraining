#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#define INF 0x3f3f3f
using namespace std;
int a[200010], s[200010];
struct node{
    int id;
    int x;
}q[200010];
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, k, ans = -2000, st, ed, M = -2000;
        scanf("%d%d", &n, &k);
        int nn = n;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            if (a[i] > M)
            {
                M = a[i];
                st = ed = i;
            }
        }
        if (M <= 0)
        {
            printf("%d %d %d\n", M, st, ed);
            continue;
        }
        for (int i = 1; i <= k - 1; i++)
            a[n + i] = a[i];
        n += k - 1;
        s[0] = 0;
        for (int i = 1; i <= n; i++)
            s[i] = s[i-1] + a[i];
        node fir;
        fir.id = 0;fir.x = 0;
        q[0] = fir;
        int l = 0, r = 1;
        for (int i = 1; i <= n; i++)
        {
            while (l < r && q[r-1].x >= s[i]) r--;
            q[r].id = i;
            q[r++].x = s[i];
            while (q[l].id < i - k) l++;
            int nows = s[i] - s[q[l].id];
            if (nows > ans)
            {
                ans = nows;
                st = q[l].id + 1;
                ed = i;
            }
        }
        if (ed > nn) ed -= nn;
        printf("%d %d %d\n", ans, st, ed);
    }
    return 0;
}