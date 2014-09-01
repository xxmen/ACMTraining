#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
using namespace std;
int n, m;
char ch[55];
int sg[55][55];
void initSG()//初始化SG函数值
{
    memset(sg, -1, sizeof(sg));
    sg[1][1] = 0;
    for (int i = 2; i <= 50; i++)
        sg[i][1] = sg[1][i] = i - 1;
}
int getSG(int x, int y)//记忆化搜索求炸弹所在点的SG值
{
    if(sg[x][y] != -1) return sg[x][y];
    bool v[2550];
    memset(v, false, sizeof(v));
    for (int i = 1; i < x; i++)
        for (int j = 1; j < y; j++)
            v[getSG(i, y) ^ getSG(x, j)] = true;
    for (int i = 0; ; i++)
        if (!v[i])
            return sg[x][y] = i;
}
int main()
{
    initSG();
    while (scanf("%d%d", &n, &m) && n + m)
    {
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%s", ch + 1);
            for (int j = 1; j <= m; j++)
            {
                if (ch[j] == '#')
                    ans ^= getSG(i, j);
            }
        }
        if (ans) puts("John");
        else puts("Jack");
    }
    return 0;
}



