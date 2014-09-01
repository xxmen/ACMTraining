#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
int n, cnt;
int sg[1010];
int a[110], c[110];
int getSG(int x)
{
    if (sg[x] != -1) return sg[x];
    bool v[5000];
    memset(v, false, sizeof(v));
    for (int i = 0; i < cnt && a[i] <= x; i++)
        for (int j = 0; j <= (x - a[i]); j++)
            v[getSG(j) ^ getSG(x - j - a[i])] = true;
    for (int i = 0; ; i++)
        if (!v[i])
            return i;
}
int main()
{
	while(~scanf("%d",&n))
    {
		for(int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		sort(a, a + n);
		cnt = 1;
		for(int i = 1; i < n; i++)
			if(a[i] != a[cnt - 1])
				a[cnt++] = a[i];
		memset(sg,-1,sizeof(sg));
        int m;
		scanf("%d", &m);
        while (m--)
        {
            int x;
            scanf("%d", &x);
            sg[x] = getSG(x);
            if (sg[x])
                puts("1");
            else puts("2");
        }
	}
	return 0;
}






