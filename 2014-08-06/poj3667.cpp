//区间合并
#include <cstdio>
#include <algorithm>
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
using namespace std;
const int maxn = 50010;
int lsum[maxn << 2], msum[maxn << 2], rsum[maxn << 2], c[maxn << 2];
void build(int l, int r, int rt)
{
    lsum[rt] = msum[rt] = rsum[rt] = r - l + 1;
    c[rt] = -1;
    if (l == r) return;
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
}
void pushdown(int rt, int m)
{
    if (c[rt] > -1)
    {
        c[rt << 1] = c[rt << 1 | 1] = c[rt];
        msum[rt << 1] = lsum[rt << 1] = rsum[rt << 1] = c[rt]? 0:m-(m >> 1);
        msum[rt << 1 | 1] = lsum[rt << 1 | 1] = rsum[rt << 1 | 1] = c[rt]?0:m>>1;
        c[rt] = -1;
    }
}
void pushup(int rt, int m)
{
    lsum[rt] = lsum[rt << 1];
    rsum[rt] = rsum[rt << 1 | 1];
    if (lsum[rt] == m - (m >> 1)) lsum[rt] += lsum[rt << 1 | 1];
    if (rsum[rt] == (m >> 1)) rsum[rt] += rsum[rt << 1];
    msum[rt] = max(lsum[rt << 1 | 1] + rsum[rt << 1], max(msum[rt << 1], msum[rt << 1 | 1]));
}
void update(int col, int L, int R, int l, int r, int rt)
{
    if (L <= l && R >= r)
    {
        msum[rt] = lsum[rt] = rsum[rt] = col ? 0 : r - l + 1;
        c[rt] = col;
        return;
    }
    pushdown(rt, r - l + 1);
    int m = (l + r) >> 1;
    if (L <= m) update(col, L, R, lson);
    if (R > m) update(col, L, R, rson);
    pushup(rt, r - l + 1);
}
int query(int len, int l, int r, int rt)
{
    if (l == r) return l;
    pushdown(rt, r - l + 1);
    int m = (l + r) >> 1;
    if (msum[rt << 1] >= len) return query(len, lson);
    else if (rsum[rt << 1] + lsum[rt << 1 | 1] >= len) return m - rsum[rt << 1] + 1;
    return query(len, rson);
}
int main()
{
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {
        build(1, n, 1);
        while (m--)
        {
            int op, x, y;
            scanf("%d", &op);
            if (op == 1)
            {
                scanf("%d", &x);
                if (msum[1] < x) printf("0\n");
                else {
                    int p = query(x, 1, n, 1);
                    printf("%d\n",p);
                    update(1, p, p + x - 1, 1, n, 1);
                }
            }
            else{
                scanf("%d%d", &x, &y);
                update(0, x, x + y - 1, 1, n, 1);
            }
        }
    }
    return 0;
}
