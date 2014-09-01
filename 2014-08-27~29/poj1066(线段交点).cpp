/* 围墙的端点一定在边界上，所以中途不可能绕过围墙，所以门是否开在中间无所谓，只要
   求边界上各条线段中点到终点穿过的墙的最少数量，其实只需求边界围墙上所有的线段端
   点与宝藏处相连的线段与其他墙的交点数，取最少交点个数加一即为答案。
*/
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <utility>
using namespace std;
const double eps=1e-10;
const double pi=acos(-1.0);
inline int fcmp(double x)
{
    if (fabs(x) < eps)
        return 0;
    return x > 0 ? 1 : -1;
}
struct point
{
    double x, y;
    point() {}
    point(double _x, double _y) : x(_x), y(_y) {}
    friend point operator - (point a, point b)
    {
        return point(a.x - b.x, a.y - b.y);
    }
};
inline double cross(point a, point b)
{
    return a.x * b.y - a.y * b.x;
}
inline double cross(point a, point b, point o)
{
    return cross(a - o, b - o);
}
inline double dot(point a, point b)
{
    return a.x * b.x + a.y * b.y;
}
inline double dot(point a, point b, point o)
{
    return dot(a - o, b - o);
}
inline bool segment_intersect(point a, point b, point c, point d)
{
    int d1 = fcmp( cross(a,b,c) );
    int d2 = fcmp( cross(a,b,d) );
    int d3 = fcmp( cross(c,d,a) );
    int d4 = fcmp( cross(c,d,b) );
    if((d1 * d2 < 0 && d3 * d4 < 0))
        return true;
    else if(d1 ==0 && dot(a,b,c) <= 0)
        return true;
    else if(d2 == 0 && dot(a,b,d) <= 0)
        return true;
    else if(d3 == 0 && dot(c,d,a) <= 0)
        return true;
    else if(d4==0 && dot(c,d,b) <= 0)
        return true;
    else
        return false;
}
point getPoint(point a, int d)
{
    point res;
    if (d == 0 || d == 180 || d == 360)
        return point(a.x, a.y - 5.0);
    else if (d > 0 && d < 90)
        d = 90 - d;
    else if (d == 90 || d == 270)
        return point(a.x - 5.0, a.y);
    else if (d > 90 && d < 270)
        d = 270 - d;
    else if (d > 270)
        d = 450 - d;
    double k = tan(d * (pi / 180.0));
    double b = a.y - k * a.x;
    res.x = a.x + 10.0;
    res.y = k * res.x + b;
    return res;
}
int main()
{
    int n;
    point a[35], b[35];
    while (~scanf("%d", &n))
    {
        for (int i = 0; i < n; i++)
            scanf("%lf%lf%lf%lf", &a[i].x, &a[i].y, &b[i].x, &b[i].y);
        point Treasure;
        scanf("%lf%lf", &Treasure.x, &Treasure.y);
        int ans = 100, sum;
        sum = 0;
        for (int i = 0; i < n; i++)
            if (segment_intersect(point(0.0, 0.0), Treasure, a[i], b[i])) sum++;
        ans = min(ans, sum);
        sum = 0;
        for (int i = 0; i < n; i++)
            if (segment_intersect(point(0.0, 100.0), Treasure, a[i], b[i])) sum++;
        ans = min(ans, sum);
        sum = 0;
        for (int i = 0; i < n; i++)
            if (segment_intersect(point(100.0, 0.0), Treasure, a[i], b[i])) sum++;
        ans = min(ans, sum);
        sum = 0;
        for (int i = 0; i < n; i++)
            if (segment_intersect(point(100.0, 100.0), Treasure, a[i], b[i])) sum++;
        ans = min(ans, sum);
        for (int i = 0; i < n; i++)
        {
            int sum1 = 0, sum2 = 0;
            for (int j = 0; j < n; j++)
            {
                if (i == j) continue;
                if (segment_intersect(a[i], Treasure, a[j], b[j])) sum1++;
                if (segment_intersect(b[i], Treasure, a[j], b[j])) sum2++;
            }
            ans = min(ans, min(sum1, sum2));
        }
        printf("Number of doors = %d\n", ++ans);
    }
}