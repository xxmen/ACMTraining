#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
int a[210], f[210][210], head[210], n, m;////f[i][j]表示在以i为根的子树上，攻克j个结点获得的最大价值
struct edge{
    int v, next;
}e[210];
void dfs(int x)
{
    f[x][1] = a[x]; //只选一个肯定选自己
    for (int i = head[x]; i > 0; i = e[i].next)//分组背包
    {
        int son = e[i].v;
        dfs(son);
        for (int j = m; j >= 1; j--) //v <- V to 0
            for (int k = 1; k < j; k++)//循环必须是j<k，不能取等号，因为至少需要留一个点来取x
                f[x][j] = max(f[x][j], f[x][j - k] + f[son][k]);
    }
}
int main()
{
    while (scanf("%d%d", &n, &m) && n + m)
    {
        memset(head, 0, sizeof(head));
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= n; i++)
        {
            int pre;
            scanf("%d%d", &pre, &a[i]);
            e[i].v = i;
            e[i].next = head[pre];
            head[pre] = i;
        }
        a[0] = 0;
        m++;
        dfs(0);
        printf("%d\n", f[0][m]);
    }
    return 0;
}