#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
using namespace std;
int n, k, mm = 200005;
int a[200005], f[200005][30];
void INIT_MAX()
{
    int M = 25;
    for (int j = 1; j <= M; j++)
        for (int i = 1; i <= n; i++)
        {
            if (i + (1<<j) - 1 > n) break;
            f[i][j] = max(f[i][j - 1], f[i + (1<<(j-1))][j - 1]);
        }
}
int Query(int x,int y)
{
    int l = (int)(log((double)(y - x + 1)) / log(2.0));
    return max(f[x][l],f[y - (1<<l)+1][l]);
}
bool check(int x)//x是最少段数
{
    int sum = 0;
    int sp = n / x; //每段人数
    for(int i = 1; i <= x; i++)
    {
        sum += Query(sp * (i-1) + 1, sp * i);
        if (sum > k) return true;
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    while (cin>>n>>k && n > 0)
    {
        int sum = 0, maxn = -1, minn=2000;
        memset(f,0,sizeof(f));
        for (int i = 1; i <= n; i++)
        {
            cin>>a[i];
            if(a[i]>maxn) maxn=a[i];
            if(a[i]<minn) minn=a[i];
            sum += a[i];
            f[i][0] = a[i];
        }
        minn = minn?minn:1;
        maxn = maxn?maxn:1;
        if(maxn > k)
        {
            printf("1\n");
            continue;
        }
        if(sum <= k)
        {
            printf("-1\n");  continue;
        }
        INIT_MAX();
        int ans = 0;
        for (int i = 1; i <= min((k / minn + 1), n); i++)
        {
            if (maxn * i < k) continue;
            if (check(i))
            {
                ans = i;
                break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
