//区间增减，区间求和
#include <cstdio>
#include <algorithm>
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
using namespace std;
typedef long long LL;
const int maxn = 100010;
LL a[maxn << 2], c[maxn << 2];
void pushup(int rt)
{
    a[rt] = a[rt << 1] + a[rt << 1 | 1];
}
void build(int l, int r, int rt)
{
    c[rt] = 0;
    if (l == r){
        scanf("%lld", &a[rt]);
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    pushup(rt);
}
void pushdown(int rt, int len)
{
    if (c[rt])
    {
        c[rt << 1] += c[rt];
        c[rt << 1 | 1] += c[rt];
        a[rt << 1] += (len - (len>>1)) * c[rt];
        a[rt << 1 | 1] += (len >> 1) * c[rt];
        c[rt] = 0;
    }
}
void update(int x, int L, int R, int l, int r, int rt)
{
    if (L <= l && R >= r)
    {
        c[rt] += x;
        a[rt] += LL(x * (r - l + 1));
        return;
    }
    pushdown(rt, r - l + 1);
    int m = (l + r) >> 1;
    if (L <= m) update(x, L, R, lson);
    if (R > m) update(x, L, R, rson);
    pushup(rt);
}
LL query(int L, int R, int l, int r, int rt)
{
    if (L <= l && R >= r)
        return a[rt];
    pushdown(rt, r - l + 1);
    int m = (l + r) >> 1;
    LL sum = 0;
    if (L <= m) sum += query(L, R, lson);
    if (R > m) sum += query(L, R, rson);
    return sum;
}
int main()
{
    int n, q;
    while (~scanf("%d%d", &n, &q))
    {
        build(1, n, 1);
        char s[2];
        while (q--)
        {
            int x, y, z;
            scanf("%s", s);
            if (s[0] == 'C')
            {
                scanf("%d%d%d", &x, &y, &z);
                update(z, x, y, 1, n, 1);
            }
            else{
                scanf("%d%d", &x, &y);
                printf("%lld\n", query(x, y, 1, n, 1));
            }
        }
    }
    return 0;
}