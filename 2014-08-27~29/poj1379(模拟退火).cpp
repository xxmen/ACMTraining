#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;
const double eps = 1e-3;
const double pi = acos(-1.0);
struct point{
    double x, y;
};
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int n, X, Y;
point a[1010], p[20];
double d[20];
double dis(point a, point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
double min_dis(point p)
{
    double res = 10000000;
    for (int i = 0; i < n; i++)
        res = min(res, dis(p, a[i]));
    return res;
}
void rand_pos()//随机获取初始位置
{
    for (int i = 0; i < 15; i++)//个数可调整
    {
        p[i].x=(rand() % 1000 + 1) / 1000.0 * X;
        p[i].y=(rand() % 1000 + 1) / 1000.0 * Y;
        d[i] = min_dis(p[i]);
    }
}
void work()
{
    double step = max(X, Y) / 10.0;
    while (step > eps)
    {
        for (int i = 0; i < 15; i++)
        {
            point now, pre = p[i];
            for (int j = 0; j < 30; j++)//个数可调整
            {
                double angle = (rand() % 1000+1) / 1000.0 * 2 * pi;
                now.x = pre.x + cos(angle) * step;
                now.y = pre.y + sin(angle) * step;
                if (now.x < 0 || now.x > X || now.y < 0 || now.y > Y) continue;
                double tmp = min_dis(now);
                if (tmp > d[i])
                {
                    p[i] = now;
                    d[i] = tmp;
                }
            }
        }
        step *= 0.85;//可调整
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    srand((int)time(NULL));
    while (t--)
    {
        scanf("%d%d%d", &X, &Y, &n);
        for (int i = 0; i < n; i++)
            scanf("%lf%lf", &a[i].x, &a[i].y);
        rand_pos();
        work();
        point sp;
        double ans = 0;
        for (int i = 0; i < 15; i++)
            if (d[i] > ans)
            {
                ans = d[i];
                sp = p[i];
            }
        printf("The safest point is (%.1f, %.1f).\n", sp.x, sp.y);
    }
    return 0;
}