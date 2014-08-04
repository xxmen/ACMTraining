//先贪心后背包
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
struct thing{
    int num,c,w;
}e[100005];
struct boat{
    int num, c;
}a[100005],b[100005];
int f[100005];
int bp[25];
bool cmp(boat x, boat y){
    return x.c > y.c;
}
int main()
{
    int n,v;
    scanf("%d%d", &n, &v);
    int p = 0, q = 0, tot = 0;
    for (int i = 0; i < n; i++)
    {
        int x,y;
        scanf("%d%d", &x, &y);
        tot += y;
        if (x == 1)
        {
            a[p].num = i+1;
            a[p++].c = y;
        }
        else {
            b[q].num = i+1;
            b[q++].c = y;
        }
    }
    if (p + 2 * q <= v)
    {
        printf("%d\n", tot);
        for (int i = 0; i < n-1; i++)
            printf("%d ",i+1);
        printf("%d\n", n);
        return 0;
    }
    sort(a,a+p,cmp);
    sort(b,b+q,cmp);
    int m = 0, sv = 0, ans = 0, leftv = 0;
    int tp = 0, tq = 0;
    while (tp < p || tq < q)
    {
        leftv = v - sv;
        if (leftv <= 20) break;
        if (a[tp].c * 2 > b[tq].c || (tp < p && tq == q))
        {
            sv += 1;
            f[m++] = a[tp].num;
            ans += a[tp++].c;
        }
        else{
            sv += 2;
            f[m++] = b[tq].num;
            ans += b[tq++].c;
        }
    }
    int s = 0;
    for (int i = tp; i < p; i++)
    {
        e[s].num = a[i].num;
        e[s].c = a[i].c;
        e[s++].w = 1;
    }
    for (int i = tq; i < q; i++)
    {
        e[s].num = b[i].num;
        e[s].c = b[i].c;
        e[s++].w = 2;
    }
    bp[0] = 0;
    int ss[25][100005];
    memset(ss, 0, sizeof(ss));
    for (int i = 0; i < s; i++)
        for (int j = leftv; j >= e[i].w; j--)
        {
            if (bp[j-e[i].w] + e[i].c > bp[j])
            {
                bp[j] = bp[j-e[i].w] + e[i].c;
                for (int k = 1; k <= ss[j-e[i].w][0]; k++)
                    ss[j][k] = ss[j-e[i].w][k];
                ss[j][0] = ss[j-e[i].w][0] + 1;
                ss[j][ss[j][0]] = e[i].num;
            }
        }
    ans += bp[leftv];
    for (int i = 1; i <= ss[leftv][0]; i++)
        f[m++] = ss[leftv][i];
    printf("%d\n", ans);
    if (ans == 0) return 0;
    for (int i = 0; i < m-1; i++)
        printf("%d ", f[i]);
    printf("%d\n", f[m-1]);
    return 0;
}
