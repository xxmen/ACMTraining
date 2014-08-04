//注意精度误差问题！
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
using namespace std;
int a[11] = {5,10,20,50,100,200,500,1000,2000,5000,10000};
long long f[30005];
int main()
{
    double money;
    memset(f, 0, sizeof(f));
    f[0] = 1;
    int n = 30005;
    for (int i = 0; i < 11; i++)
        for (int j = n; j >= a[i]; j--)
            for (int k = 1; j - k * a[i] >= 0; k++)
                f[j] += f[j - k * a[i]];
    while (scanf("%lf", &money))
    {
        int n = int((money+1e-5) * 100);
        if (n == 0) break;
        printf("%6.2lf%17lld\n", money, f[n]);
    }
    return 0;
}
