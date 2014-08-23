#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
using namespace std;
int a[21][210], b[10], c[210];
bool v[210];
int n, m;
bool find(int x)
{
    for (int i = 1; i <= m; i++)
        if (a[x][i] && !v[i])
        {
            v[i] = true;
            if (c[i] == 0 || find(c[i]))
            {
                c[i] = x;
                return true;
            }
        }
    return false;
}
int hungary()
{
    int sum = 0;
    memset(c, 0, sizeof(c));
    for (int i = 1; i <= n; i++)
    {
        memset(v, false, sizeof(v));
        if (find(i)) sum++;
    }
    return sum;
}
int main()
{
    ios::sync_with_stdio(false);
    map<char, int> ma;
    ma['S'] = 1;ma['M'] = 2;ma['L'] = 3;ma['X'] = 4;ma['T'] = 5;
    string s1;
    while (cin>>s1 && s1 != "ENDOFINPUT")
    {
        string s[21];
        memset(a, 0, sizeof(a));
        cin>>n;
        for (int i = 1; i <= n; i++)
            cin>>s[i];
        for (int i = 1; i <= 5; i++)
            scanf("%d", &b[i]);
        for (int i = 1; i <= n; i++)
        {
            int x = ma[s[i][0]], y = ma[s[i][1]];
            for (int j = x; j <= y; j++)
                for (int k = 1; k <= b[j]; k++)
                    a[i][(j-1) * 20 + k] = 1;
        }
        cin>>s1;
        m = 100;
        int ans = hungary();
        if (ans < n)
            puts("I'd rather not wear a shirt anyway...");
        else puts("T-shirts rock!");
    }
    return 0;
}