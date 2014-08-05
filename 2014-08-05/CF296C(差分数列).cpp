//两次差分数列
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long LL;
struct op{
    int l, r;
    LL d;
}c[100005];
LL a[100005], ca[100005];
int b[100005], cb[100005];
int main()
{
    ios::sync_with_stdio(false);
    int n, m, k;
    cin>>n>>m>>k;
    for (int i = 1; i <= n; i++)
        cin>>a[i];
    for (int i = 1; i <= m; i++)
        cin>>c[i].l>>c[i].r>>c[i].d;
    memset(cb, 0, sizeof(cb));
    for (int i = 1; i <= k; i++)//差分数列求每种操作总共进行次数
    {
        int x,y;
        cin>>x>>y;
        cb[x]++;
        cb[y+1]--;
    }
    for (int i = 1; i <= m; i++)
        b[i] = b[i - 1] + cb[i];
    for (int i = 1; i <= m; i++)
        if (b[i]) c[i].d *= b[i];
    ca[1] = a[1];
    for (int i = 2; i <= n; i++)
        ca[i] = a[i] - a[i - 1];
    for (int i = 1; i <= m; i++)//差分数列进行每种操作
    {
        if (b[i])
        {
            ca[c[i].l] += c[i].d;
            ca[c[i].r + 1] -= c[i].d;
        }
    }
    LL sum = ca[1];
    cout<<sum;
    for (int i = 2; i <= n; i++)
    {
        sum += ca[i];
        cout<<" "<<sum;
    }
    cout<<endl;
    return 0;
i}
