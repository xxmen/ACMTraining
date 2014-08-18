#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;
const int MOD = 100000000;
LL a[12], state[500], f[500][15];
int n, m, s;
void GetState()
{
    s = 0;
    for (int i = 0; i < (1 << n); i++)
        if (i & (i << 1)) continue;//去除相邻的情况
        else state[s++] = i;
}
int main()
{
    while (~scanf("%d%d", &m, &n))
    {
        for (int i = 0; i < m; i++)
        {
            LL x = 0;
            for (int j = 0; j < n; j++)
            {
                int p;
                scanf("%d", &p);
                x |= p << j;
            }
            a[i] = x;
        }
        GetState();
        for (int i = 0; i < s; i++)//初始化第一行的方案数
            if (~a[0] & state[i])//不符合当前行的要求
                f[i][0] = 0;
            else f[i][0] = 1;
        for (int i = 1; i < m; i++)
        {
            for (int j = 0; j < s; j++)
            {
                if (~a[i] & state[j]) continue;//不符合当前行的要求
                for (int k = 0; k < s; k++)
                {
                    if (state[j] & state[k]) continue;//和上一行冲突
                    f[j][i] += f[k][i - 1];
                    f[j][i] %= MOD;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < s; i++)
        {
            ans += f[i][m - 1];
            ans %= MOD;
        }
        printf("%d\n", ans);
    }
    return 0;
}


