#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
using namespace std;
typedef long long LL;
LL a[200005], ans = 0;
int b[200005] = {0};
int main()
{
    ios::sync_with_stdio(false);
    int n, m;
    cin>>n>>m;
    for (int i = 1; i <= n; i++)
        cin>>a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= m; i++)//统计每个位置的数取的次数
    {
        int x,y;
        cin>>x>>y;
        b[x]++;b[y+1]--;
    }
    for (int i = 1; i <= n; i++)
        b[i] += b[i - 1];
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; i++)
        ans += a[i] * LL(b[i]);
    cout<<ans<<endl;
    return 0;
}
