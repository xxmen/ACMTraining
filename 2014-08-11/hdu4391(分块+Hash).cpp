#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;
const int maxn = 100005;
int n, m, len, cnt, a[500], c[maxn];//a[i]标记对第i块的整体染色
map<int,int> hash[500];
void pushDown(int x)//把对整块的操作更新到每点
{
    if(a[x] > -1)
    {
        hash[x].clear();
        for(int i = x * len; i < min((x+1)*len, n); i++)
        {
            c[i]=a[x];
            hash[x][c[i]]++;
        }
        a[x] = -1;
    }
}
void update(int l, int r, int col)
{
    int x = l / len , y = r / len;
    for (int i = x + 1; i < y; i++)//完全覆盖一个块则对这个块打上标记
        a[i] = col;
    if (x != y)
    {
        pushDown(x);
        pushDown(y);
        for (int i = l; i < (x + 1) * len; i++)//更新最左边的块
        {
            hash[x][c[i]]--;
            hash[x][col]++;
            c[i] = col;
        }
        for (int i = y * len; i <= r; i++)//更新最右边的块
        {
            hash[y][c[i]]--;
            hash[y][col]++;
            c[i] = col;
        }
    }
    else
    {
        pushDown(x);
        for (int i = l; i <= r; i++)
        {
            hash[x][c[i]]--;
            hash[x][col]++;
            c[i] = col;
        }
    }
}
int query(int l,int r,int col)
{
    int x = l / len, y = r / len, ans=0;
    for(int i = x + 1; i < y; i++)
    {
        if (a[i] > -1)
        {
            if (a[i] == col)
                ans += len;
            continue;
        }
        if(hash[i].find(col) != hash[i].end()) ans += hash[i][col];
    }
    if(x != y)
    {
        pushDown(x);
        pushDown(y);
        for (int i = l; i < len * (x + 1); i++)
            if (c[i] == col) ans ++;
        for (int i = y * len; i <= r; i++)
            if (c[i] == col) ans ++;
    }
    else
    {
        pushDown(x);
        for (int i = l; i <= r; i++)
            if (c[i] == col) ans++;
    }
    return ans;
}
int main()
{
    while (scanf("%d%d", &n, &m) != EOF)
    {
        len = int(sqrt(n + 1e-6));
        cnt = (n - 1) / len + 1;
        for(int i = 0; i < cnt; i++)
        {
            a[i] = -1;
            hash[i].clear();
        }
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &c[i]);
            hash[i / len][c[i]]++;
        }
        while (m--)
        {
            int op, l, r, col;
            scanf("%d%d%d%d", &op, &l, &r, &col);
            if (op == 1) update(l, r, col);
            else printf("%d\n", query(l, r, col));
        }
    }
    return 0;
}