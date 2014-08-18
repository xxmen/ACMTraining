//区间染色，统计区间颜色数
#include <cstdio>
#include <cstring>
#include <algorithm>
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
using namespace std;
const int maxn = 100010;
int ans, c[maxn << 2];
bool hash[40];
void build(int l, int r, int rt)
{
    if (l == r)
    {
        c[l] = 1;
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
}
void pushDown(int rt)
{
    if (c[rt])
    {
        c[rt << 1] = c[rt << 1 | 1] = c[rt];
        c[rt] = 0;
    }
}
void update(int col, int L, int R, int l, int r, int rt)
{
    if (L <= l && R >= r)
    {
        c[rt] = col;
        return;
    }
    pushDown(rt);
    int m = (l + r) >> 1;
    if (L <= m) update(col, L, R, lson);
    if (R > m) update(col, L, R, rson);
}
void query(int L, int R, int l, int r, int rt)
{
    if (c[rt])
    {
        if (!hash[c[rt]]) ans++;
        hash[c[rt]] = true;
        return;
    }
    int m = (l + r) >> 1;
    if (L <= m) query(L, R, lson);
    if (R > m) query(L, R, rson);
}
int main()
{
    int n, t, m;
    while (~scanf("%d%d%d", &n, &t, &m))
    {
        memset(c, 0, sizeof(c));
        build(1, n, 1);
        while (m--)
        {
            char op[5];
            int x, y, col;
            scanf("%s", op);
            if (op[0] == 'C')
            {
                scanf("%d%d%d", &x, &y, &col);
                update(col, x, y, 1, n, 1);
            }
            else
            {
                scanf("%d%d", &x, &y);
                ans = 0;
                memset(hash, false, sizeof(hash));
                query(x, y, 1, n, 1);
                printf("%d\n", ans);
            }
        }
    }
    return 0;
}

