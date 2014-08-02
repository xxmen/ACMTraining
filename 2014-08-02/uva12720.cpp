#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#define MOD 1000000007
using namespace std;
int p[100005];
int main()
{
    int t,Case = 0;
    p[0] = 1;
    for (int i = 1; i <= 100000; i++)
        p[i] = 2 * p[i-1] % MOD;
    ios::sync_with_stdio(false);
    cin>>t;
    while (t--)
    {
        string s;
        int ans = 0;
        cin>>s;
        int n = int(s.length()), m = n;
        if (n % 2 == 1)
        {
            ans = (s[n / 2] - '0') * p[--m];
            string s1 = "";
            for (int i = 0; i < n; i++)
                if (i == n/2) continue;
                else s1 += s[i];
            s = s1;
            n -= 1;
        }
        for (int i = 0; i < n / 2; i++)
        {
            int x = s[n / 2 - i - 1] - '0';
            int y = s[n / 2 + i] - '0';
            if (x > y)
            {
                ans += x * p[--m];
                ans %= MOD;
                ans += y * p[--m];
                ans %= MOD;
            }
            else{
                ans += y * p[--m];
                ans %= MOD;
                ans += x * p[--m];
                ans %= MOD;
            }
        }
        cout<<"Case #"<<++Case<<": "<<ans<<endl;
    }
    return 0;
}
