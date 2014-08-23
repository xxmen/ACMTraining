#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int a[210][210], c[210];
bool v[210];
int n, m;
bool find(int x)
{
    for (int i = 1; i <= m; i++)
        if (a[x][i] && !v[i])
        {
            v[i] = true;
            if (c[i] == 0 || find(c[i]))
            {
                c[i] = x;
                return true;
            }
        }
    return false;
}
int hungary()
{
    int sum = 0;
    memset(c, 0, sizeof(c));
    for (int i = 1; i <= n; i++)
    {
        memset(v, false, sizeof(v));
        if (find(i)) sum++;
    }
    return sum;
}
int main()
{
    while (~scanf("%d%d", &n, &m))
    {
        memset(a, 0, sizeof(a));
        for (int i = 1; i <= n; i++)
        {
            int k;
            scanf("%d", &k);
            for (int j = 0; j < k; j++)
            {
                int x;
                scanf("%d", &x);
                a[i][x] = 1;
            }
        }
        printf("%d\n", hungary());
    }
    return 0;
}
