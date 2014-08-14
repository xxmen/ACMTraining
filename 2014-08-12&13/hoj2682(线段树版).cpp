//区间增减
#include <cstdio>
#include <algorithm>
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
using namespace std;
const int maxn = 10010;
int a[maxn << 2], c[maxn << 2];
void pushUp(int rt)
{
    a[rt] = a[rt << 1] + a[rt << 1 | 1];
}
void pushDown(int rt, int len)
{
    if (c[rt] > 0)
    {
        c[rt << 1] += c[rt];
        c[rt << 1 | 1] += c[rt];
        a[rt << 1] += (len - (len >> 1)) * c[rt];
        a[rt << 1 | 1] += (len >> 1) * c[rt];
        c[rt] = 0;
    }
}
void update(int x, int L, int R, int l, int r, int rt)
{
    if (L <= l && R >= r)
    {
        c[rt] += x;
        a[rt] += x * (r - l + 1);
        return;
    }
    pushDown(rt, r - l + 1);
    int m = (l + r) >> 1;
    if (L <= m) update(x, L, R, lson);
    if (R > m) update(x, L, R, rson);
    pushUp(rt);
}
int query(int L, int R, int l, int r, int rt)
{
    if (L <= l && R >= r)
        return a[rt];
    pushDown(rt, r - l + 1);
    int s = 0;
    int m = (l + r) >> 1;
    if (L <= m) s += query(L, R, lson);
    if (R > m) s += query(L, R, rson);
    return s;
}
int main()
{
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {
        memset(a, 0, sizeof(a));
        memset(c, 0, sizeof(c));
        while (m--)
        {
            int x,y;
            scanf("%d%d", &x, &y);
            update(1, x, y, 1, n, 1);
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
            if ((query(i, i, 1, n, 1) & 1) == 0)
                ans++;
        printf("%d\n", ans);
    }
    return 0;
}
