#include <cstdio>
#include <cstring>
#include <algorithm>
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
using namespace std;
typedef long long LL;
const int maxn = 100010;
LL a[maxn << 2], d[maxn << 2];
LL c[maxn << 2];
void pushUp(LL l, LL r, LL rt)
{
    a[rt] = a[rt << 1] + a[rt << 1 | 1] + LL(d[rt] * (LL)(r - l + 1));
}
void build(int l, int r, int rt)
{
    if(l == r)
    {
        c[rt] = l;
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
}
void pushDown(int rt)
{
    if (c[rt] > 0)
    {
        c[rt << 1] = c[rt << 1 | 1] = c[rt];
        c[rt] = 0;
    }
}
void work(int x, int l, int r, int rt)
{
    if (c[rt] > 0)
    {
        d[rt] += abs(x - c[rt]);
        a[rt] += LL((r - l + 1) * LL(abs(x - c[rt])));
    }
    else{
        int m = (l + r) >> 1;
        work(x, lson);
        work(x, rson);
        pushUp(l, r, rt);
    }
    c[rt] = x;
}
void update(int x, int L, int R, int l, int r, int rt)
{
    if (L <= l && R >= r)
    {
        work(x, l, r, rt);
        return;
    }
    pushDown(rt);
    int m = (l + r) >> 1;
    if (L <= m) update(x, L, R, lson);
    if (R > m) update(x, L, R, rson);
    pushUp(l, r, rt);
}
LL query(int L, int R, int l, int r, int rt)
{
    if (L <= l && R >= r)
        return a[rt];
    LL sd = LL(d[rt] * (LL)(R - L + 1));
    int m = (l + r) >> 1;
    if(R <= m)
        return LL(query(L, R, lson) + sd);
    else if(L > m)
        return LL(query(L, R, rson) + sd);
    else
        return LL(query(L, m , lson) + query(m + 1, R, rson) + sd);
}
int main()
{
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {
        memset(a, 0, sizeof(a));
        memset(c, 0, sizeof(c));
        memset(d, 0, sizeof(d));
        build(1, n, 1);
        while (m--)
        {
            int op, x, y, z;
            scanf("%d", &op);
            if (op == 1)
            {
                scanf("%d%d%d", &x, &y, &z);
                update(z, x, y, 1, n, 1);
            }
            else
            {
                scanf("%d%d", &x, &y);
                printf("%lld\n", query(x, y, 1, n, 1));
            }
        }
    }
    return 0;
}
