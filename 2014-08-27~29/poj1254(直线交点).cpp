#include <cstdio>
#include <cmath>
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
inline point line_intersect(point a, point b, point c, point d)
{
    point res = a;
    double t = cross(a - c, c - d) / cross(a - b, c - d);
    res.x += (b.x - a.x) * t;
    res.y += (b.y - a.y) * t;
    return res;
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
    int t;
    scanf("%d", &t);
    while (t--)
    {
        point p1, p2, q1, q2;
        int d1, d2;
        scanf("%lf%lf%d", &p1.x, &p1.y, &d1);
        scanf("%lf%lf%d", &q1.x, &q1.y, &d2);
        p2 = getPoint(p1, d1);
        q2 = getPoint(q1, d2);
        point ans = line_intersect(p1, p2, q1, q2);
        printf("%.4lf %.4lf\n", ans.x, ans.y);
    }
}