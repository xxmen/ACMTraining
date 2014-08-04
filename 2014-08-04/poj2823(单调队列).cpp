//单调队列
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
int a[1000010];
struct node{
    int id, x;
}q[1000010];
int main()
{
    int n,k;
    while (~scanf("%d%d", &n, &k))
    {
        for (int i = 0; i < n; i++)
            scanf("%d", a+i);
        int l = 0, r = -1;
        for (int i = 0; i < n; i++)//最小值
        {
            while (l <= r && q[r].x >= a[i]) r--;//删除队尾，保证队列单调上升
            q[++r].id = i;
            q[r].x = a[i];
            while (q[l].id  < i - k + 1) l++;//滑出了区间则将其删除
            if (i >= k - 1)
            {
                printf("%d", q[l].x);
                if (i < n - 1) printf(" ");
                else printf("\n");
            }
        }
        l = 0, r = -1;
        for (int i = 0; i < n; i++)//最大值
        {
            while (l <= r && q[r].x <= a[i]) r--;
            q[++r].id = i;
            q[r].x = a[i];
            while (q[l].id  < i - k + 1) l++;
            if (i >= k - 1)
            {
                printf("%d", q[l].x);
                if (i < n - 1) printf(" ");
                else printf("\n");
            }
        }
    }
    return 0;
}
