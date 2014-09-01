#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        if (n % 3)
            puts("Kiki");
        else puts("Cici");
    }
    return 0;
}
