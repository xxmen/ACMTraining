#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 6010;
int head[maxn], happy[maxn], fa[maxn], tree[maxn][1000], f[maxn][2];
struct edge{
    int v, next;
}e[maxn];
int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        memset(head, 0, sizeof(head));
        memset(tree, 0, sizeof(tree));
        memset(fa, 0, sizeof(fa));
        for (int i = 1; i <= n; i++)
            scanf("%d", &happy[i]);
        for (int i = 1; i <= n; i++)
        {
            int l, k;
            scanf("%d%d", &l, &k);
            if (l + k == 0) break;
            fa[l] = k;
            e[i].v = l;
            e[i].next = head[k];
            head[k] = i;
        }
        int m = 0;
        for (int i = 1; i <= n; i++)
        {
            int x = i, dep = 1;
            while (fa[x] != 0)
            {
                dep++;
                x = fa[x];
            }
            tree[dep][0]++;
            tree[dep][tree[dep][0]] = i;
            m = max(m, dep);
        }
        for (int i = m; i >= 1; i--)
            for (int j = 1 ; j <= tree[i][0]; j++)
            {
                int now = tree[i][j];
                if (!head[now])
                {
                    f[now][0] = 0;
                    f[now][1] = happy[now];
                }
                else
                {
                    f[now][0] = 0;
                    f[now][1] = happy[now];
                    for (int k = head[now]; k > 0; k = e[k].next)
                    {
                        int son = e[k].v;
                        f[now][0] += max(f[son][0], f[son][1]);
                        f[now][1] += f[son][0];
                    }
                }
            }
        int ans = max(f[tree[1][1]][0], f[tree[1][1]][1]);
        printf("%d\n", ans);
    }
    return 0;
}