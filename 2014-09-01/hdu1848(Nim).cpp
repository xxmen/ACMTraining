#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
using namespace std;
int n, m, p, tot;
int SG[1010], f[16] = {1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597};
bool v[1010];
void init_SG()
{
    SG[0] = 0;
    SG[1] = 1;
    for (int i = 2; i <= 1000; i++)
    {
        memset(v, false, sizeof(v));
        for (int j = 0; f[j] <= i; j++)
            v[ SG[i - f[j]] ] = true;
        for (int j = 0; j <= i; j++)
            if (!v[j])
            {
                SG[i] = j;
                break;
            }
    }
}
int main()
{
    init_SG();
    while (scanf("%d%d%d", &n, &m, &p) && n + m + p)
    {
        int ans = SG[n] ^ SG[m] ^ SG[p];
        if (!ans)
            puts("Nacci");
        else puts("Fibo");
    }
    return 0;
}
