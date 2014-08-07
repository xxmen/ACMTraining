#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
int n, c[1111][1111];
int lowbit(int x)
{
    return x & -x;
}
void Add(int x, int y, int p)
{
    for (int i = x; i <= n; i += lowbit(i))
        for (int j = y; j <= n; j += lowbit(j))
            c[i][j] += p;
}
int Sum(int x, int y)
{
    int sum = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        for (int j = y; j > 0; j -= lowbit(j))
            sum += c[i][j];
    return sum;
}
int main()
{
    int op;
    scanf("%d%d", &op, &n);
    memset(c, 0, sizeof(c));
    while (scanf("%d", &op) == 1 && op != 3)
    {
        if (op == 1)
        {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            Add(x + 1, y + 1, z);//注意x和y要+1，不能出现0！！！
        }
        else if (op == 2)
        {
            int x1, y1, x2, y2;
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
                x1++;y1++;x2++;y2++;
            printf("%d\n",Sum(x2, y2) - Sum(x1 - 1, y2) - Sum(x2, y1 - 1) + Sum(x1 - 1, y1 - 1));
        }
    }
    return 0;
}
