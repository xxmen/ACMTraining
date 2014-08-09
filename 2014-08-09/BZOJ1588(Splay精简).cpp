#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 100000, INF = 100000000;
int n, root, nodeNum = 0, son[2][maxn], data[maxn], fa[maxn];
void AddNode(int &r, int father, int x)//插入位置,父结点，插入的值
{
    r = ++nodeNum;
    fa[r] = father;
    data[r] = x;
    son[0][r] = son[1][r] = 0;
}
void rotate(int x, int kind) //kind为1右旋,0左旋
{
    int y = fa[x];
    son[1 - kind][y] = son[kind][x];
    fa[son[kind][x]] = y;
    if (fa[y])
        son[son[1][fa[y]] == y][fa[y]] = x;
    fa[x] = fa[y];
    son[kind][x] = y;
    fa[y] = x;
}
void Splay(int x, int goal)//将根为x的子树调整为goal
{
    while (fa[x] != goal)
    {
        if (fa[fa[x]] == goal)
            rotate(x, son[0][fa[x]] == x);
        else{
            int y = fa[x];
            int kind = son[0][fa[y]] == y;
            if (son[kind][y] == x)//两次方向不同
            {
                rotate(x, !kind);
                rotate(x, kind);
            }
            else{
                rotate(y, kind);
                rotate(x, kind);
            }
        }
    }
    if (goal == 0) root = x;
}
int Insert(int x)
{
    int r = root;
    while (son[data[r] < x][r])
    {
        if (data[r] == x)//不重复插入
        {
            Splay(r, 0);
            return 0;
        }
        r = son[data[r] < x][r];
    }
    AddNode(son[data[r] < x][r], r, x);
    Splay(son[data[r] < x][r], 0);//新插入的节点旋转到根节点
    return 1;
}
int findPre(int x)
{
    int y = son[0][x];
    if (!y) return INF;
    while (son[1][y])
        y = son[1][y];
    return data[x] - data[y];
}
int findSuc(int x)
{
    int y = son[1][x];
    if (!y) return INF;
    while (son[0][y])
        y = son[0][y];
    return data[y] - data[x];
}
int main()
{
    scanf("%d", &n);
    int ans = 0;
    root = nodeNum = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        if (scanf("%d", &x) == EOF) x = 0;
        if (i == 1)
        {
            AddNode(root, 0, x);
            ans += x;
            continue;
        }
        if (Insert(x) == 0) continue;//之前已经存在的数据
        ans += min(findPre(root), findSuc(root));//root一定是当前插入的值
    }
    printf("%d\n", ans);
    return 0;
}
