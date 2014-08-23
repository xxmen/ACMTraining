//建图:横向或者纵向连续的*标上同一个编号,ch[i][j]为*,则在这个*所属的横向编号和纵向编号间连一条边
//最大匹配
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int n, m, map[1000][1000], a[105][105], b[105][105], c[1000];
char ch[100][100];
bool vis[1000];
bool find(int x)
{
    for (int i = 1; i <= m; i++)
    {
        if (map[x][i] && !vis[i])
        {
            vis[i] = true;
            if (c[i] == 0 || find(c[i]))
            {
                c[i] = x;
                return true;
            }
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
        memset(vis, false, sizeof(vis));
        if (find(i)) sum++;
    }
    return sum;
}
int main()
{
    int r, c;
    while (~scanf("%d%d", &r, &c))
    {
        for (int i = 0; i < r; i++)
            scanf("%s", ch[i]);
        memset(a, 0, sizeof(a));
        int id = 1;
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                if (ch[i][j] == '*')
                {
                    a[i][j] = id;
                    if(j == c - 1 || ch[i][j+1] != '*')
                        id++;
                }
        n = id;
        memset(b, 0, sizeof(b));
        id = 1;
        for (int i = 0; i < c; i++)
            for (int j = 0; j < r; j++)
                if (ch[j][i] == '*')
                {
                    b[j][i] = id;
                    if(j == r - 1 || ch[j + 1][i] != '*')
                        id++;
                }
        m = id;
        memset(map, 0, sizeof(map));
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                if (ch[i][j] == '*')
                    map[a[i][j]][b[i][j]] = 1;
        printf("%d\n", hungary());
    }
    return 0;
}