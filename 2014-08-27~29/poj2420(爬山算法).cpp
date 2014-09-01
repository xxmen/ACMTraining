#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
struct point{
    double x, y;
};
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int n;
point a[100];
double dis(point a, point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
double dis_to_all(point p)
{
    double sum = 0;
    for (int i = 0; i < n; i++)
        sum += dis(p, a[i]);
    return sum;
}
int main()
{
    while (~scanf("%d", &n))
    {
        double sumx = 0, sumy = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%lf%lf", &a[i].x, &a[i].y);
            sumx += a[i].x;
            sumy += a[i].y;
        }
        point last;
        last.x = sumx / (double)n; last.y = sumy / (double)n;//选取一点作为初始点
        double step = 100, ans = dis_to_all(last);
        while (step > 0.1)
        {
            bool flag = true;
            point now;
            while (flag)
            {
                flag = false;
                for (int i = 0; i < 4; i++)//向4个方向搜索
                {
                    now.x = dx[i] * step + last.x;
                    now.y = dy[i] * step + last.y;
                    double now_dis = dis_to_all(now);
                    if (now_dis < ans)
                    {
                        ans = now_dis;
                        last = now;
                        flag = true;
                    }
                }
            }
            step /= 2.0;//减小步长
        }
        printf("%.0lf\n", ans);
    }
    return 0;
}