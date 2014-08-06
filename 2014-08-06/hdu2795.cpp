//单点修改，区间最值
#include <cstdio>
#include <algorithm>
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
using namespace std;
const int maxn = 200010;
int a[maxn << 2];
int h, w, n;
void pushup(int rt)
{
    a[rt] = max(a[rt << 1], a[rt << 1 | 1]);
}
void build(int l, int r, int rt)
{
    a[rt] = w;
    if (l == r) return;
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
}
int query(int x, int l, int r, int rt)
{
    if (l == r)
    {
        a[rt] -= x;
        return l;
    }
    int m = (l + r) >> 1;
    int res = (a[rt<<1] >= x)? query(x , lson) : query(x , rson);//先判断左子树是否符合条件
    pushup(rt);
    return res;
}
int main()
{
    while (~scanf("%d%d%d", &h, &w, &n))
    {
        h = min(h,n);
        build(1, h, 1);
        for (int i = 0; i < n; i++)
        {
            int x;
            scanf("%d", &x);
            if (a[1] < x) printf("-1\n");
            else printf("%d\n", query(x, 1, h, 1));
        }
    }
}
