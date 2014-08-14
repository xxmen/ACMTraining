//区间替换
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
void build(int l, int r, int rt)
{
    c[rt] = -1;
    if (l == r)
    {
        a[rt] = 0;
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    pushUp(rt);
}
void pushDown(int rt, int len)
{
    if (c[rt] > -1)
    {
        c[rt << 1] = c[rt << 1 | 1] = c[rt];
        a[rt << 1] = (len - (len >> 1)) * c[rt];
        a[rt << 1 | 1] = (len >> 1) * c[rt];
        c[rt] = -1;
    }
}
void update(int x, int L, int R, int l, int r, int rt)
{
    if (L <= l && R >= r)
    {
        c[rt] = x;
        a[rt] = x * (r - l + 1);
        return;
    }
    pushDown(rt, r - l + 1);
    int m = (l + r) >> 1;
    if (L <= m) update(x, L, R, lson);
    if (R > m) update(x, L, R, rson);
    pushUp(rt);
}
int main()
{
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {
        build(1, n, 1);
        while (m--)
        {
            int x,y,z;
            scanf("%d%d%d", &x, &y, &z);
            update(z, x, y, 1, n, 1);
        }
        printf("%d\n", n - a[1]);
    }
    return 0;
}