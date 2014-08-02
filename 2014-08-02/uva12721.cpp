#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
using namespace std;
int p[30][15], c[30][15], a[105][205];
int f[105][105];
int main()
{
    int t,Case = 0;
    scanf("%d", &t);
    while (t--)
    {
        string s;
        int n;
        cin>>s>>n;
        for (int i = 1; i <= 26; i++)
        {
            scanf("%d", &p[i][0]);
            c[i][0] = p[i][0];
            for (int j = 1; j <= p[i][0]; j++)
                scanf("%d%d", &p[i][j], &c[i][j]);
        }
        int len = int(s.length());
        for (int i = 0; i < len; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                int sum = 0;
                int now = s[i] - 'a' + 1;
                for (int k = 1; k <= p[now][0]; k++)
                {
                    if (j % p[now][k] == 0)
                        sum += j / p[now][k] * c[now][k];
                }
                a[i+1][j] = sum;
            }
        }
        for (int i = 0; i <= len; i++)
            for (int j = 0; j <= n; j++)
                f[i][j] = 10000000;
        for (int i = 0; i <= len; i++)
            f[i][0] = 0;
        for (int i = 1; i <= len; i++)
            for (int j = 1; j <= n; j++)
            {
                f[i][j] = min(f[i][j], f[i-1][j]);
                f[i][j] = min(f[i][j], f[i - 1][j-1] + a[i][j]);
            }
        printf("Case #%d: %d\n", ++Case, f[len][n]);
    }
    return 0;
}
