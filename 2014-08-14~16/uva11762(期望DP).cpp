//f[x] = 1 + f[x] * (1-g[x]/p[x]) + ∑f[x/y] * 1 / p[x], p[x]为不超过x的素数个数，g[x]为p[x]中是因子的个数,y为x的因子
//可变成f[x]=(∑f[x/y]+p)/g
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
int prime[100000], m = 0;
double f[1000010];//f[i]表示i变成1的期望次数
bool p[1000010];
void getPrime()
{
    int M = 1000010;
    memset(p, true, sizeof(p));
    for (int i = 2; i < M; i++)
    {
        if (p[i]) prime[m++] = i;
        for (int j = 0; j < m && i * prime[j] < M; j++)
        {
            p[i * prime[j]] = false;
            if (i % prime[j] == 0) break;
        }
    }
}
double dp(int x)
{
    if (x == 1) return 0.0;
    if (f[x] >= 0.0) return f[x];
    double sum = 0.0;
    int tot = 0, sp = 0;
    for (int i = 0; i < m; i++)
    {
        if (prime[i] > x) break;
        sp++;
        if (x % prime[i] == 0)
        {
            tot++;
            sum += dp(x / prime[i]);
        }
    }
    sum = (sum + sp) / tot;
    return f[x] = sum;
}
int main()
{
    int t, Case = 0;
    scanf("%d", &t);
    getPrime();
    memset(f, -1, sizeof(f));
    while (t--)
    {
        int x;
        scanf("%d", &x);
        printf("Case %d: %.10lf\n", ++Case, dp(x));
    }
    return 0;
}