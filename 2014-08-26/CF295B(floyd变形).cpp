#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long LL;
int n, a[505][505], x[505];
LL ans[505];
bool v[505];
int main()
{
	while (~scanf("%d", &n))
	{
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                scanf("%d", &a[i][j]);
        for (int i = 1; i <= n; i++)
            scanf("%d", &x[i]);
        memset(v, false, sizeof(v));
        for (int k = n; k >= 1; k--)
        {
            int now = x[k];
            v[now] = true;
            LL sum = 0;
            for (int i = 1; i <= n; i++)
            {
                if (v[i])
                {
                    //更新当前新加入的点到其他点的最短路
                    for (int j = 1; j <= n; j++)
                        if (v[j])
                        {
                            a[now][j] = min(a[now][j], a[now][i] + a[i][j]);
                            a[j][now] = min(a[j][now], a[j][i] + a[i][now]);
                        }
                }
            }
            //通过当前点更新最短路
            for (int i = 1; i <= n; i++)
                if (v[i])
                    for (int j = 1; j <= n; j++)
                        if (v[j])
                        {
                            a[i][j] = min(a[i][j], a[i][now] + a[now][j]);
                            sum += a[i][j];
                        }
            ans[k] = sum;
        }
        for (int i = 1; i < n; i++)
            cout<<ans[i]<<" ";
        cout<<ans[n]<<endl;
	}
	return 0;
}
