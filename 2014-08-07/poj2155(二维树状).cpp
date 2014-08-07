#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
int n, c[1111][1111];
int lowbit(int x)
{
    return x & -x;
}
void Update(int x, int y)
{
    for (int i = x; i <= n; i += lowbit(i))
        for (int j = y; j <= n; j += lowbit(j))
            c[i][j]++;
}
int Sum(int x, int y)
{
    int sum = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        for (int j = y; j > 0; j -= lowbit(j))
            sum += c[i][j];
    return sum;
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        memset(c, 0, sizeof(c));
        int m;
        scanf("%d%d", &n, &m);
        while(m--)
		{
            char ch[2];
			scanf("%s",ch);
			if( ch[0] == 'C' )
			{
                int x1, y1, x2, y2;
				scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
				x1++; y1++; x2++; y2++;
				Update(x2, y2);
				Update(x1-1, y1-1);
				Update(x1-1, y2);
				Update(x2, y1-1);
			}
			else
			{
                int x, y;
				scanf("%d%d",&x,&y);
				printf("%d\n",Sum(x,y) & 1);
			}
		}
        printf("\n");
    }
    return 0;
}
