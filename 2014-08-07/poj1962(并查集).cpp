#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
int fa[20010], dis[20010];
int Find(int x)
{
    if (fa[x] == x)
        return x;
    else{
        int root = Find(fa[x]);
        dis[x] += dis[fa[x]];
        fa[x] = root;
        return fa[x];
    }
}
void Union(int x, int y)
{
    dis[x] = abs(x - y) % 1000;
    fa[x] = y;
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            fa[i] = i;
            dis[i] = 0;
        }
        char s[2];
        while (scanf("%s", s) && s[0] != 'O')
        {
            int x, y;
            if (s[0] == 'E')
            {
                scanf("%d", &x);
                Find(x);
                printf("%d\n", dis[x]);
            }
            else{
                scanf("%d%d", &x, &y);
                Union(x, y);
            }
        }
    }
    return 0;
}
