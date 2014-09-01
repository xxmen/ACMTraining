#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
using namespace std;
int a[200010], b[200010];
int main()
{
    int n;
    while (scanf("%d", &n) && n)
    {
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        int sum = a[1];
        for (int i = 2; i <= n; i++)
            sum ^= a[i];
        if (!sum)
        {
            puts("No");
            continue;
        }
        puts("Yes");
        for (int i = 1; i <= n; i++)
        {
            b[i] = sum ^ a[i];
            if (b[i] < a[i])
                printf("%d %d\n", a[i], b[i]);
        }
    }
    return 0;
}
