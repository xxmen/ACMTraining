#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;
int main()
{
    int T, Case = 0;
    scanf("%d", &T);
    while (T--)
    {
        LL n, ans = 0;
        scanf("%I64d", &n);
        if (n >= 3 && n <= 6)//a0 = n 的情况只有无穷个的时候才会符合条件
        {
            printf("Case #%d: -1\n", ++Case);
            continue;
        }
        for (int i = 3; i <= 6; i++)//a0 + a1*x = n的情况
            for (int j = 3; j <= 6; j++)
            {
                LL x = (n - i) / j;
                if ((n - i) % j == 0 && x > max(i, j))
                    ans++;
            }
        for (int i = 3; i <= 6; i++)//a0+a1*x+a2*x^2 = n的情况
            for (int j = 3; j <= 6; j++)
                for (int k = 3; k <= 6; k++)
                {
                    LL a = i, b = j, c = k - n;
                    LL d = (b * b) - 4 * a * c;
                    LL x = abs((-b + sqrt(d+0.1)) / (a * 2));
                    if (a * x * x + b * x + c)//不是整数解
                        continue;
                    if (x > max(i, max(j, k)))//保证x进制中有i，j，k这几个数字
                        ans++;
                }
        for (LL i = 4; i * i * i <= n; i++)
        {
            LL x = n;
            while (x)
            {
                if (x % i < 3 || x % i > 6)
                    break;
                x /= i;
            }
            if (!x) ans++;
        }
        printf("Case #%d: %I64d\n", ++Case, ans);
    }
    return 0;
}