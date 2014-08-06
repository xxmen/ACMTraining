//离散化+区间替换+根求和
#include <cstdio>
#include <algorithm>
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
using namespace std;
const int maxn = 10010;
int a[maxn << 2], c[maxn << 4], li[maxn], ri[maxn], ans;
bool hash[maxn];
void pushdown(int rt)
{
    if (c[rt] > -1)
    {
        c[rt << 1] = c[rt << 1 | 1] = c[rt];
        c[rt] = -1;
    }
}
void update(int x, int L, int R, int l, int r, int rt)
{
    if (L <= l && R >= r)
    {
        c[rt] = x;
        return;
    }
    pushdown(rt);
    int m = (l + r) >> 1;
    if (L <= m) update(x, L, R, lson);
    if (R > m) update(x, L, R, rson);
}
void query(int l, int r, int rt)
{
    if (c[rt] > -1)
    {
        if (!hash[c[rt]]) ans++;
        hash[c[rt]] = true;
        return;
    }
    if (l == r) return;
    int m = (l + r) >> 1;
    query(lson);
    query(rson);
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        int tot = 0;
        for (int i = 0;i < n; i++)
        {
            scanf("%d%d", &li[i], &ri[i]);
            a[tot++] = li[i];
            a[tot++] = ri[i];
        }
        sort(a, a + tot);
        int m = 1;
        for (int i = 1; i < tot; i++)//去重
            if (a[i] != a[i - 1]) a[m++] = a[i];
        for (int i = m - 1; i > 0; i--)
            if (a[i] != a[i - 1] + 1) a[m++] = a[i-1] + 1;
        sort(a, a + m);
        memset(c, -1, sizeof(c));
        for (int i = 0; i < n; i++)
        {
            int l = int(lower_bound(a, a + m, li[i]) - a);
            int r = int(lower_bound(a, a + m, ri[i]) - a);
            update(i, l, r, 0, m - 1, 1);
        }
        ans = 0;
        memset(hash, false, sizeof(hash));
        query(0, m - 1, 1);
        printf("%d\n", ans);
    }
    return 0;
}
