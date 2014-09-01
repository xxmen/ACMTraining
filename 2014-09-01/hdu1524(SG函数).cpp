#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
int n;
int sg[1010];
int a[1010][1010];
int getSG(int x)
{
    if (sg[x] != -1) return sg[x];
    bool v[1010] = {0};
    for (int i = 0; i < n; i++)
        if (a[x][i])
            v[getSG(i)] = 1;
    for (int i = 0; ; i++)
        if (!v[i])
            return sg[x] = i;
}
int main()
{
	while(~scanf("%d",&n))
    {
        memset(sg, -1, sizeof(sg));
        memset(a, 0, sizeof(a));
		for (int i = 0; i < n; i++)
        {
            int k;
            scanf("%d", &k);
            if (k == 0) sg[i] = 0;
            for (int j = 0; j < k; j++)
            {
                int x;
                scanf("%d", &x);
                a[i][x] = 1;
            }
        }
        int m;
        while (scanf("%d", &m) && m)
        {
            int ans = 0;
            for (int i = 0; i < m; i++)
            {
                int x;
                scanf("%d", &x);
                ans ^= getSG(x);
            }
            if (ans) puts("WIN");
            else puts("LOSE");
        }
	}
	return 0;
}






