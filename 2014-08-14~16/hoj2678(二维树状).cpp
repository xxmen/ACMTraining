#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 1010;
struct star{
    int x, y, z;
}a[15010];
int n, m, c[maxn][maxn], ans[15010];
bool cmp(star a, star b)
{
    if (a.x == b.x)
    {
        if (a.y == b.y)
            return a.z < b.z;
        return a.y < b.y;
    }
    return a.x < b.x;
}
inline int lowbit(int x)
{
    return x & -x;
}
void add(int add, int x, int y)
{
    for (int i = x; i <= maxn; i += lowbit(i))
        for (int j = y; j < maxn; j += lowbit(j))
            c[i][j] += add;
}
int sum(int x, int y)
{
    int s = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        for (int j = y; j > 0; j -= lowbit(j))
            s += c[i][j];
    return s;
}

int main()
{
    while (~scanf("%d", &n))
    {
        memset(ans, 0, sizeof(ans));
        memset(c, 0, sizeof(c));
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].z);
            a[i].x++;a[i].y++;a[i].z++;
        }
        sort(a + 1, a + n + 1, cmp);
        for (int i = 1; i <= n; i++)
        {
            int lev = sum(a[i].y, a[i].z);
            ans[lev]++;
            add(1, a[i].y, a[i].z);
        }
        for (int i = 0; i < n - 1; i++)
            printf("%d ", ans[i]);
        printf("%d\n", ans[n - 1]);
    }
    return 0;
}