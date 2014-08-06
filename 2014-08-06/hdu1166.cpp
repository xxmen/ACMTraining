#include <cstdio>
#include <algorithm>
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
using namespace std;
const int maxn = 50050;
int a[maxn << 2];
void pushup(int rt)
{
    a[rt] = a[rt << 1] + a[rt << 1 | 1];
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
        a[rt] += y;
        return;
    }
    int m = (l + r) >> 1;
    if (x <= m) update(x, y, lson);
    else update(x, y, rson);
    pushup(rt);
}
int query(int L, int R, int l, int r,int rt)
{
    if (L <= l && R >= r)
        return a[rt];
    int m = (l + r) >> 1, sum = 0;
    if (L <= m) sum += query(L, R, lson);
    if (R > m) sum += query(L, R, rson);
    return sum;
}
int main()
{
    int t, Case = 0;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        build(1, n, 1);
        char s[10];
        printf("Case %d:\n", ++Case);
        while (scanf("%s", s))
        {
            if (s[0] == 'E') break;
            int x, y;
            scanf("%d%d", &x, &y);
            if (s[0] == 'A')
                update(x, y, 1, n, 1);
            else if (s[0] == 'S')
                update(x, -y, 1, n, 1);
            else{
                printf("%d\n", query(x, y, 1, n, 1));
            }
        }
    }
    return 0;
}