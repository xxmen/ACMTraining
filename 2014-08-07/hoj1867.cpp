#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#define MAXC 1000500
using namespace std;
int c[MAXC],a[MAXC];
int C,N,M;
int ini;
bool check(int x)
{
    if (x < 2) return false;
    for (int i = 2; i <= int(sqrt(x)); i++)
        if (x % i == 0)
            return false;
    return true;
}
int lowbit(int x)
{
    return x & -x;
}
void Add(int x, int y)
{
    while (x <= C)
    {
        c[x] += y;
        x += lowbit(x);
    }
}
int Sum(int x)
{
    int sum = 0;
    while (x)
    {
        sum += c[x];
        x -= lowbit(x);
    }
    return sum;
}
int main()
{
    int Case = 0;
    while (scanf("%d%d%d", &C, &N, &M) && C+N+M)
    {
        printf("CASE #%d:\n", ++Case);
        C = min(C,1000000);
        for (int i = 1; i <= C; i++)
            a[i] = M;
        ini = check(M)?1:0;
        memset(c, 0, sizeof(c));
        if (ini)
            for (int i = 1; i <= C; i++)
                Add(i, ini);
        while(N--)
        {
            int f,x,y;
            scanf("%d%d%d",&f,&x,&y);
            if (f)
            {
                printf("%d\n",Sum(y) - Sum(x - 1));
            }
            else
            {
                bool b1 = check(a[x]), b2 = check(a[x] + y);
                if (b1 && (!b2))
                    Add(x, -1);
                if ((!b1) && b2)
                    Add(x, 1);
                a[x] += y;
            }
        }
        printf("\n");
    }
    return 0;
}
