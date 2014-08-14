#include <cstdio>
#include <algorithm>
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
using namespace std;
const int maxn = 100100, INF = 0x3f3f3f;
int c[maxn << 2], a[maxn], b[maxn];
void build(int l, int r, int rt)
{
    c[rt] = INF;
    if (l == r)
    {
        c[rt] = 200000;
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
}
void pushDown(int rt, int len)
{
    if (c[rt] < INF)
    {
        c[rt << 1] = c[rt << 1 | 1] = c[rt];
        c[rt] = INF;
    }
}
void update(int x, int L, int R, int l, int r, int rt)
{
    if (L <= l && R >= r)
    {
        c[rt] = x;
        return;
    }
    pushDown(rt, r - l + 1);
    int m = (l + r) >> 1;
    if (L <= m) update(x, L, R, lson);
    if (R > m) update(x, L, R, rson);
}
int query(int L, int R, int l, int r, int rt)
{
    if(l == r)
    {
        return c[rt];
    }
    pushDown(rt, r - l + 1);
    int m = (l + r) >> 1;
    if (L <= m) return query(L, R, lson);
    else return query(L, R, rson);
}
int main()
{
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        for (int i = 1; i <= n; i++)
            scanf("%d", &b[i]);
        build(1, n, 1);
        while (m--)
        {
            int op, x,y,k;
            scanf("%d", &op);
            if (op == 1)
            {
                scanf("%d%d%d", &x, &y, &k);
                update(x - y, y, y + k - 1, 1, n, 1);
            }
            else{
                scanf("%d", &x);
                int s = query(x, x, 1, n, 1);
                if (s == 200000) printf("%d\n", b[x]);
                else printf("%d\n", a[x + s]);
            }
        }
    }
    return 0;
}
