#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
using namespace std;
int n, m, k, tot;
int SG[10010], f[110];
bool v[10100];
void init_SG()
{
    memset(SG, -1, sizeof(SG));
    SG[0] = 0;
    for (int i = 1; i <= 10001; i++)
    {
        memset(v, false, sizeof(v));
        for (int j = 0; f[j] <= i && j < k; j++)
            v[ SG[i - f[j]] ] = true;
        for (int j = 0; ; j++)
            if (!v[j])
            {
                SG[i] = j;
                break;
            }
    }
}
int main()
{
    while (scanf("%d", &k) && k)
    {
        for (int i = 0; i < k; i++)
            scanf("%d", &f[i]);
        sort(f, f + k);
        init_SG();
        scanf("%d", &m);
        for (int i = 0; i < m; i++)
        {
            scanf("%d", &n);
            int x, ans;
            scanf("%d", &x);
            ans = SG[x];
            for (int j = 1; j < n; j++)
            {
                scanf("%d", &x);
                ans ^= SG[x];
            }
            if (ans) printf("W");
            else printf("L");
        }
        puts("");
    }
    return 0;
}