#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;
typedef long long LL;
const int maxn = 50005;
int p[maxn], day[maxn];
LL f[maxn];
struct wm{
    LL p, day;
    wm(LL x, LL y) { p = x; day = y; }
    bool operator < (const wm & b) const
    {
        if (p == b.p) return day > b.day;
        return p > b.p;
    }
};
int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        for (int i = 1; i <= n; i++)
            scanf("%d", &p[i]);
        for (int i = 1; i <= n; i++)
            scanf("%d", &day[i]);
        memset(f, 0, sizeof(f));
        priority_queue<wm> q;
        for (int i = 1; i <= n; i++)
        {
            wm now = wm(LL(p[i] + f[i - 1]), LL(i + day[i] - 1));
            while (!q.empty() && q.top().day < i) q.pop();
            q.push(now);
            f[i] = q.top().p;
        }
        printf("%lld\n", f[n]);
    }
    return 0;
}
