#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
const int N = 1025;
vector<int> map[N];
int n, m, num[N], s = 0, tot = 0, match[N];
bool a[N], vis[N];
bool find(int x)
{
    for (int i = 0; i < map[x].size(); i++)
    {
        int y = map[x][i];
        if (!vis[y])
        {
            vis[y] = true;
            if (match[y] == 0 || find(match[y]))
            {
                match[y] = x;
                return true;
            }
        }
    }
    return false;
}
int hungary()
{
    int sum = 0;
    memset(match, 0, sizeof(match));
    for (int i = 1; i <= tot; i++)
    {
        memset(vis, false, sizeof(vis));
        if (find(i)) sum++;
    }
    return sum;
}
bool check(int x,int y)//判断两个数是否只差一位
{
    int t = x ^ y;
    if (t && (t & (t - 1)) == 0) return true;
    return false;
}
int main()
{
	while ( scanf("%d %d",&n, &m) && (m+n) )
	{
		memset(a, false, sizeof(a));
		for (int i = 1; i <= m; i++ )
		{
            char ch[15];
			scanf("%s", ch);
            int k = -1, Num = 0;
			for (int j = 0; j < n; j++ )
			{
				if (ch[j] == '*' ) k = j;
				else Num |= ((ch[j] - '0') << j);
			}
            a[Num] = true;
			if (k != -1)
            {
				Num |= (1 << k);
                a[Num] = true;
            }
		}
        tot = 0;
		for (int i = 0; i <= (1 << n); i++)
            if (a[i]) num[++tot] = i;
        for (int i = 1; i <= tot; i++)
            map[i].clear();
		for (int i = 1; i <= tot; i++ )
			for (int j = 1; j <= tot; j++ )
			{
                if (check(num[i], num[j]))
				    map[i].push_back(j);
			}
		printf("%d\n",tot - hungary() / 2);
	}
	return 0;
}
