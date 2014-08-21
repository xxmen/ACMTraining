#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#define INF 0x3f3f3f
using namespace std;
const int maxn = 200;
int n, m, num, d[maxn][maxn];
int main()
{
    ios::sync_with_stdio(false);
    while(scanf("%d",&n)&& n > 0)
    {
        string s1, s2;
        map<string, int> ma;
        ma.clear();
        cin>>s1>>s2;
        memset(d, 0x3f, sizeof(d));
        num = 0;
        ma[s1] = ++num;
        ma[s2] = ++num;
        int st = ma[s1], ed = ma[s2];
        m = 0;
        for (int i = 1; i <= n; i++)
        {
            int w;
            cin>>s1>>s2>>w;
            if (ma.find(s1) == ma.end())
                ma[s1] = ++num;
            if (ma.find(s2) == ma.end())
                ma[s2] = ++num;
            int u = ma[s1], v = ma[s2];
            d[u][v] = min(d[u][v], w);
            d[v][u] = min(d[v][u], w);
        }
        for (int k = 1; k <= num; k++)
            for (int i = 1; i <= num; i++)
                for (int j = 1; j <= num; j++)
                    if (d[i][k] < INF && d[k][j] < INF)
                        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        if (st == ed)
        {
            printf("0\n");
            continue;
        }
        int ans = d[st][ed];
        if (ans < INF)
            printf("%d\n", ans);
        else puts("-1");
    }
    return 0;
}