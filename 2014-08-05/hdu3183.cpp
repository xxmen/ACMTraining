//贪心
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    string s;
    int n;
    while (cin>>s>>n)
    {
        if (s.length() == n)
        {
            cout<<0<<endl;
            continue;
        }
        int i;
        for (i = 0; i < s.length() - 1; )
        {
            if (s[i] <= s[i+1]) i++;
            else
            {
                s = s.erase(i, 1);
                n--;
                if (n == 0) break;
                if (i) i--;
            }
        }
        if (n) s = s.erase(s.length() - n, n);
        for (i = 0; i < s.length(); i++)
            if (s[i] > '0') break;
        s = s.erase(0, i);
        if (s.length() == 0)
            cout<<0<<endl;
        else
        {
            for (int i = 0; i < s.length(); i++)
                cout<<s[i];
            cout<<endl;
        }
    }
    return 0;
}
