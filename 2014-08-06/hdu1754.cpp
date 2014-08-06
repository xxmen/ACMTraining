//单点替换，区间最值
#include <cstdio>
#include <algorithm>
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
using namespace std;
const int maxn = 200010;
int a[maxn << 2];
void pushup(int rt)
{
    a[rt] = max(a[rt << 1], a[rt << 1 | 1]);
}
void build(int l, int r, int rt)
{
    if (l == r)
    {
        scanf("%d", &a[rt]);
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    pushup(rt);
}
void update(int x, int y, int l, int r, int rt)
{
    if (l == r)
    {
        a[rt] = y;
        return;
    }
    int m = (l + r) >> 1;
    if (x <= m) update(x, y, lson);
    else update(x, y, rson);
    pushup(rt);
}
int query(int L, int R, int l, int r, int rt)
{
    if (L <= l && R >= r)
        return a[rt];
    int res = 0, m = (l + r) >> 1;
    if (L <= m) res = query(L, R, lson);
    if (R > m) res = max(res, query(L, R, rson));
    return res;
}
int main()
{
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {
        build(1, n, 1);
        char s[5];
        int x, y;
        for (int i = 0; i < m; i++)
        {
            scanf("%s%d%d", s, &x, &y);
            if (s[0] == 'U')
                update(x, y, 1, n, 1);
            else printf("%d\n", query(x, y, 1, n, 1));
        }
    }
    return 0;
}
