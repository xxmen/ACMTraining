#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
int c[32010], lev[15555];
const int m = 32005;
int lowbit(int x)
{
    return x & -x;
}
void Add(int x)
{
    while (x <= m)
    {
        c[x]++;
        x += lowbit(x);
    }
}
int Sum(int x)
{
    int sum = 0;
    while (x > 0)
    {
        sum += c[x];
        x -= lowbit(x);
    }
    return sum;
}
int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        memset(lev, 0, sizeof(lev));
        memset(c, 0, sizeof(c));
        for (int i = 0; i < n; i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            x++;//保证x大于0
            lev[Sum(x)]++;
            Add(x);
        }
        for (int i = 0; i < n; i++)
            printf("%d\n", lev[i]);
    }
    return 0;
}