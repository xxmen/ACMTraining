#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 10010;
int n, m, c[maxn];
inline int lowbit(int x)
{
    return x & -x;
}
void add(int x, int y)
{
    while (x > 0)
    {
        c[x] += y;
        x -= lowbit(x);
    }
}
int sum(int x)
{
    int s = 0;
    while (x <= n)
    {
        s += c[x];
        x += lowbit(x);
    }
    return s;
}

int main()
{
    while (~scanf("%d%d", &n, &m))
    {
        memset(c, 0, sizeof(c));
        for (int i = 0; i < m; i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            add(x - 1, -1);
            add(y, 1);
        }
        int w = 0, r = 0, b = 0;
        for (int i = 1; i <= n; i++)
        {
            int col = sum(i);
            if (col % 3 == 0) w++;
            else if (col % 3 == 1) r++;
            else b++;
        }
        printf("%d %d %d\n", w, r, b);
    }
    return 0;
}