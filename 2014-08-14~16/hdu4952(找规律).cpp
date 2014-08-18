#include <cstdio>
#include <cmath>
#include <iostream>
#include <cstring>
#include <algorithm>
typedef long long LL;
using namespace std;
int M;
int main()
{
    long long x, k;
    int Case = 0;
    while (scanf("%I64d%I64d", &x, &k) && x+k)
    {
        M = int(4 * pow(10.0, (log(x+0.1)/log(10.0) ) / 2.0));
        LL n = x;
        LL k1 = k;
        if (k < M)
        {
            for (int i = 1; i <= k; i++)
            {
                if (n % i)
                    n = ((n / i)+1) * i;
            }
            printf("Case #%d: %I64d\n", ++Case, n);
            continue;
        }
        for (int i = 1; i <= M; i++)
        {
            if (n % i)
                n = ((n / i)+1) * i;
        }
        long long ans = (k / M) * n;
        if (k % M)
        {
            k1 = k/M * M + 1;
            for (LL i = k1 ; i <= k; i++)
            {
                if (ans % i)
                    ans = ((ans / i)+1) * i;
            }
        }
        printf("Case #%d: %I64d\n", ++Case, ans);
    }
    return 0;
}
