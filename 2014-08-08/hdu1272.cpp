#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
int fa[100010];
bool b[100010];
int Find(int x)
{
    return fa[x] == x ? x : fa[x] = Find(fa[x]);
}
void Union(int x, int y)
{
    fa[Find(y)] = Find(x);
}
int main()
{
    int x, y;
    bool flag = false;
    for (int i = 0; i <= 100000; i++)
        fa[i] = i;
    memset(b, false, sizeof(b));
    while (scanf("%d%d", &x, &y) && x >= 0)
    {
        if (x == 0)
        {
            if (flag) { puts("No"); memset(b, false, sizeof(b)); flag = false; continue;}
            int root;
            for (int i = 1; i <= 100000; i++)
                if (b[i])
                {
                    root = Find(i);
                    break;
                }
            for (int i = 1; i <= 100000; i++)
                if (b[i] && Find(i) != root)
                {
                    flag = true;
                    break;
                }
            if (flag) puts("No");
            else puts("Yes");
            flag = false;
            for (int i = 0; i <= 100000; i++)
                fa[i] = i;
            memset(b, false, sizeof(b));
            continue;
        }
        if (flag) continue;
        b[x] = true;
        b[y] = true;
        if (Find(x) == Find(y))
            flag = true;
        Union(x, y);
    }
    return 0;
}
