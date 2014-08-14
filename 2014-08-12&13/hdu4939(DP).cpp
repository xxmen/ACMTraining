#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;
const int maxn = 1600;
LL f[maxn][maxn];//f[i][j]表示前i个格子建了j座蓝塔的最大伤害
LL x,y,z,t;
int main()
{
    int T, Case = 0, n;
    scanf("%d", &T);
    while (T--)
    {
        cin>>n>>x>>y>>z>>t;
        memset(f, 0, sizeof(f));
        LL ans = n * t * x;
        for(int i = 1; i <= n; i++)
            for(int j = 0; j <= i; j++)
            {
                LL p = 0;
                if (j) p = f[i - 1][j - 1] + (i - j) * y * (t + (j - 1) * z);
                LL q = f[i - 1][j] + (i - j - 1) * y * (t + j * z);
                f[i][j] = max(p, q);
                LL now = f[i][j] + (n - i) * (x + (i - j) * y) * (t + j * z);
                ans = max(ans, now);
            }
        cout<<"Case #"<<++Case<<": "<<ans<<endl;
    }
    return 0;
}