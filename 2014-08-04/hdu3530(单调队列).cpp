#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
int a[100010];
struct node{
    int id,x;
}Qmin[100010],Qmax[100010];
int main()
{
    int n,m,k;
    while (~scanf("%d%d%d", &n, &m, &k))
    {
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        int lmin = 0, lmax = 0, rmin = -1, rmax = -1, ans = 0, st = 1;
        for (int i = 1; i <= n; i++)
        {
            while (lmin <= rmin && Qmin[rmin].x >= a[i]) rmin--;
            while (lmax <= rmax && Qmax[rmax].x <= a[i]) rmax--;
            Qmin[++rmin].x = a[i];Qmin[rmin].id = i;
            Qmax[++rmax].x = a[i];Qmax[rmax].id = i;
            while(Qmax[lmax].x - Qmin[lmin].x > k)
            {
                if(Qmax[lmax].id > Qmin[lmin].id) st = Qmin[lmin].id + 1, lmin++;
                else st = Qmax[lmax].id + 1, lmax++;
            }
            if (Qmax[lmax].x - Qmin[lmin].x >= m && Qmax[lmax].x - Qmin[lmin].x <= k)
                ans = max(i - st + 1, ans);
        }
        printf("%d\n", ans);
    }
    return 0;
}
