#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
using namespace std;
int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) && n + m)
    {
        if (n * m % 2)
            puts("What a pity!");
        else puts("Wonderful!");
    }
    return 0;
}
