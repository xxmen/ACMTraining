#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 100000, MI = -100000000, MA = 100000000;
int n, root, nodeNum = 0, size[maxn], son[2][maxn], data[maxn], fa[maxn];
void updateSize(int x)
{
    size[x] = size[son[0][x]] + size[son[1][x]];
}
void rotate(int w, int x) //w为0左旋,1右旋
{
    int y = fa[x];
    son[1 - w][y] = son[w][x];//若右旋把x的右子树接到y的左子树，左旋则把x左子树接到y的右子树
    if (son[w][x])
        fa[son[w][x]] = y;
    fa[x] = fa[y];
    if (fa[y]) //y不是根节点
    {
        if (y == son[0][fa[y]]) //y是父结点的左子树
            son[0][fa[y]] = x; //x变为y父结点的左子树
        else son[1][fa[y]] = x;//x变为y父结点的右子树
    }
    son[w][x] = y;//左旋则x的左子树为y
    fa[y] = x;
    updateSize(y);
    updateSize(x);
}
void Splay(int x, int y)
{
    while (fa[x] != y)
    {
        if (fa[fa[x]] == y)
        {
            if (x == son[0][fa[x]])
                rotate(1, x);
            else rotate(0, x);
        }
        else
        {
            if (fa[x] == son[0][fa[fa[x]]])
            {
                if (x == son[0][fa[x]])
                {
                    rotate(1, fa[x]);
                    rotate(1, x);
                }
                else
                {
                    rotate(0, x);
                    rotate(1, x);
                }
            }
            else{
                if (x == son[1][fa[x]])
                {
                    rotate(0, fa[x]);
                    rotate(0, x);
                }
                else
                {
                    rotate(1, x);
                    rotate(0, x);
                }
            }
        }
    }
    if (y == 0) root = x;
}
void addNode(int x, int y, int z)//x插入位置，y父结点，z插入的值
{
    data[x] = z;
    fa[x] = y;
    son[0][x] = 0;
    son[1][x] = 0;
    size[x] = 1;
}
void Insert(int x)
{
    int y = root;
    while (1)
    {
        size[y]++;
        if (x < data[y])//插在左子树
        {
            if (son[0][y])
                y = son[0][y];
            else{
                nodeNum++;
                addNode(nodeNum, y, x);
                son[0][y] = nodeNum;
                y = nodeNum;
                break;
            }
        }
        else// 插入右子树
        {
            if (son[1][y])
                y = son[1][y];
            else{
                nodeNum++;
                addNode(nodeNum, y, x);
                son[1][y] = nodeNum;
                y = nodeNum;
                break;
            }
        }
    }
    Splay(y, 0);
}
int findPlace(int x)
{
    int y = root;
    while (1)
    {
        if (data[y] == x) break;
        if (x < data[y])
        {
            if (son[0][y] == 0) break;
            else y = son[0][y];
        }
        else{
            if (son[1][y] == 0) break;
            else y = son[1][y];
        }
    }
    Splay(y, 0);
    return y;
}
int findPre(int x)
{
    if (root == 0)  return 0;
    int y = findPlace(x);
    Splay(y, 0);
    if (data[y] > x)
    {
        y = son[0][y];
        if (y == 0)
            return MI;
        while (son[1][y])
            y = son[1][y];
    }
    return data[y];
}
int findSuc(int x)
{
    if (root == 0)  return 0;
    int y = findPlace(x);
    Splay(y, 0);
    if (data[y] < x)
    {
        y = son[1][y];
        if (y == 0)
            return MA;
        while (son[0][y])
            y = son[0][y];
    }
    return data[y];
}
int main()
{
    scanf("%d", &n);
        long long ans = 0;
        root = 0;
        nodeNum = 0;
        for (int i = 1; i <= n; i++)
        {
            int x;
            if (scanf("%d", &x) == EOF) x = 0;
            if (i == 1)
            {
                root = 1;
                nodeNum = 1;
                addNode(1, 0, x);
                ans += x;
                continue;
            }
            int pre = findPre(x), suc = findSuc(x);
            if (suc == MA) ans += x - pre;
            else if (pre == MI) ans += suc - x;
            else if (x - pre < suc - x) ans += x - pre;
            else ans += suc - x;
            Insert(x);
        }
        printf("%lld\n", ans);
    return 0;
}
