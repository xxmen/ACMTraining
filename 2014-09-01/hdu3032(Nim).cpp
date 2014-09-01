#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
using namespace std;
int n, SG[110];
bool v[1010];
void init_SG()//打表找SG函数规律
{
    SG[0] = 0;
    SG[1] = 1;
    for (int i = 2; i <= 100; i++)
    {
        memset(v, false, sizeof(v));
        for (int j = 0; j < i; j++)
            v[SG[j]] = true;
        for (int j = 1; j < i && i - j > 0; j++)
        {
            int x = SG[j], y = SG[i - j];
            v[x ^ y] = true;
        }
        for (int j = 0; j <= 100; j++)
            if (!v[j])
            {
                SG[i] = j;
                break;
            }
    }
    for (int i = 1; i <= 100; i++)
    {
        printf("%d ", SG[i]);
        if (i % 10 == 0) puts("");
    }
}
//sg(4k)=4k-1;sg(4k+1)=4k+1;sg(4k+2)=4k+2;sg(4k+3)=4k+4;
int getSG(int x)
{
    if (x % 4 == 1 || x % 4 == 2)
        return x;
    if (x % 4 == 3)
        return x + 1;
    return x - 1;
}
int main()
{
    //init_SG();
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        int x, ans;
        scanf("%d", &x);
        ans = getSG(x);
        for (int i = 1; i < n; i++)
        {
            scanf("%d", &x);
            ans ^= getSG(x);
        }
        if (ans)
            puts("Alice");
        else puts("Bob");
    }
    return 0;
}