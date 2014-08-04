#include <cstdio>
using namespace std;
int main()
{
    int n,s1 = 0, s2 = 0;
    scanf("%d", &n);
    for (int i = 0; i < n ; i++)
    {
        int x;
        scanf("%d", &x);
        if (x == 100) s1++;
        else s2++;
    }
    if (s1 % 2 != 0) { printf("NO\n"); return 0;}
    if (s1 == 0 && s2 % 2 == 1) { printf("NO\n"); return 0;}
    if (s2 == 0)
    {
        if (s1 % 2 == 0) printf("YES\n");
        else printf("NO\n");
        return 0;
    }
    printf("YES\n");
    return 0;
}
