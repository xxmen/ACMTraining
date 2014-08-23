#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int a[210][210], col[210];
int n, m;
bool bfs(int st)
{
    col[st] = 1;
    queue<int> q;
    q.push(st);
    while (!q.empty())
    {
        int f = q.front();
        q.pop();
        for (int i = 0; i < n; i++)
            if (a[f][i])
            {
                if (!col[i])
                {
                    col[i] = 3 - col[f];
                    q.push(i);
                    continue;
                }
                else
                {
                    if (col[i] != 3 - col[f])
                        return false;
                }
            }
    }
    return true;
}
int main()
{
    while (scanf("%d", &n) && n)
    {
        scanf("%d", &m);
        memset(a, 0, sizeof(a));
        memset(col, 0, sizeof(col));
        for (int i = 0; i < m; i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            a[x][y] = 1;
            a[y][x] = 1;
        }
        bool ans = bfs(0);
        if (ans) puts("BICOLORABLE.");
        else puts("NOT BICOLORABLE.");
    }
    return 0;
}