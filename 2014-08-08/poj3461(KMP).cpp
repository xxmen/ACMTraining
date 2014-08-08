#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int n, m, ans = 0, next[10010];
char a[10010], b[1000010];
void cal_next()
{
    next[0] = -1;
    int j = -1;
    for (int i = 1; i < n; i++)
    {
        while (j > -1 && a[j+1] != a[i]) j = next[j];
        if (a[j+1] == a[i]) j++;
        next[i] = j;
    }
}
void kmp()
{
    int j = -1;
    for (int i = 0; i < m; i++)
    {
        while (j > -1 && a[j+1] != b[i]) j = next[j];
        if (a[j+1] == b[i]) j++;
        if (j == n - 1)
        {
            ans++;
            j = next[j];
        }
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%s", a);
        scanf("%s", b);
        n = int(strlen(a));
        m = int(strlen(b));
        ans = 0;
        cal_next();
        kmp();
        printf("%d\n", ans);
    }
    return 0;
}