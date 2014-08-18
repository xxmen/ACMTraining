#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
    long long h,a,b,k;
    int Case = 0;
    while (cin>>h>>a>>b>>k && h+a+b+k)
    {
        if (a >= h)
        {
            printf("Case #%d: YES\n", ++Case);
            continue;
        }
        if (a <= b)
        {
            printf("Case #%d: NO\n", ++Case);
            continue;
        }
        if ((k - 1) * (a - b) + a >= h)
        {
            printf("Case #%d: YES\n", ++Case);
            continue;
        }
        long long d = (a - b) * k;
        if (d >= h)
        {
            printf("Case #%d: YES\n", ++Case);
            continue;
        }
        if (b >= d)
        {
            printf("Case #%d: NO\n", ++Case);
            continue;
        }
        else{
            printf("Case #%d: YES\n", ++Case);
            continue;
        }
    }
    return 0;
}
