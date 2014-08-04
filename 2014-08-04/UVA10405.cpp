#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
using namespace std;
int f[1050][1050];
int main()
{
    string s1,s2;
    while (getline(cin, s1))//注意读入整行!!
    {
        getline(cin, s2);
        memset(f,0,sizeof(f));
        for (int i = 1; i <= s1.length(); i++)
            for (int j = 1; j <= s2.length(); j++)
            {
                if (s1[i-1] == s2[j-1])
                    f[i][j] = f[i-1][j-1] + 1;
                else f[i][j] = max(f[i][j-1], f[i-1][j]);
            }
        printf("%d\n", f[s1.length()][s2.length()]);
    }
    return 0;
}
