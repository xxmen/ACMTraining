#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <utility>
using namespace std;
int sqr(int x)
{
    return x * x;
}
int main()
{
    int a, b, c, x, y, z;
    while (scanf("%d%d%d%d%d%d", &a, &b, &c, &x, &y, &z) && a+b+c+x+y+z)
    {
        int ans = 0;
        if (x == 0 || y == 0 || z == 0)
            ans = x * x + y * y + z * z;
        else
        {
            if (x == a)
            {
                int s1 = min(sqr(z) + sqr(x + y), sqr(y) + sqr(x + z));//经过两个面
                int s2 = min(sqr(c + y) + sqr(a + c - z), sqr(b + z) + sqr(a + b - y));//经过三个面
                ans = min(s1, s2);
            }
            if (y == b)
            {
                int s1 = min(sqr(z) + sqr(b + x), sqr(x) + sqr(b + z));
                int s2 = min(sqr(a + z) + sqr(a + b - x), sqr(c + x) + sqr(b + c - z));
                ans = min(s1, s2);
            }
            if (z == c)
            {
                int s1 = min(sqr(x) + sqr(c + y), sqr(y) + sqr(c + x));
                int s2 = min(sqr(b + x) + sqr(b + c - y), sqr(a + y) + sqr(a + c - x));
                ans = min(s1, s2);
            }
        }
        printf("%d\n", ans);
    }
}