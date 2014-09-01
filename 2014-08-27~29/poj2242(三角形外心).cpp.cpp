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
    friend point operator + (point a, point b)
    {
        return point(a.x + b.x, a.y + b.y);
    }
    friend point operator - (point a, point b)
    {
        return point(a.x - b.x, a.y - b.y);
    }
    friend point operator * (point a, double d)
    {
        return point(a.x * d, a.y * d);
    }
    friend point operator / (point a, double d)
    {
        return point(a.x / d, a.y / d);
    }
};
inline double dis(point a,point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
inline double cross(point a, point b)
{
    return a.x * b.y - a.y * b.x;
}
inline pair<point, int> line_intersect(point a, point b, point c, point d)
{
    point res = a;
    if (fcmp(cross(a - b, c - d)) == 0)
    {
        if (fcmp(cross(c - a, d - a) == 0))//两直线重合
            return make_pair(res, 0);
        else return make_pair(res, 1);//平行
    }
    double t = cross(a - c, c - d) / cross(a - b, c - d);
    res.x += (b.x - a.x) * t;
    res.y += (b.y - a.y) * t;
    return make_pair(res, 2);
}
int main()
{
    point a, b, c;
    while (~scanf("%lf%lf%lf%lf%lf%lf", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y))
    {
        point p1 = (a + b) / 2.0;
        point p2;
        if (fcmp(a.x - b.x) == 0)
        {
            p2.y = p1.y;
            p2.x = p1.x + 1.0;
        }
        else
        {
            double k = (b.y - a.y) / (b.x - a.x);
            if (fcmp(k) == 0)
            {
                p2.x = p1.x;
                p2.y = p1.y + 1.0;
            }
            else{
                double k1 = -1.0 / k;
                double t = p1.y - k1 * p1.x; //y = k1 * x + t
                p2.x = p1.x + 1.0;
                p2.y = k1 * p2.x + t;
            }
        }
        point q1 = (a + c) / 2.0;
        point q2;
        if (fcmp(a.x - c.x) == 0)
        {
            q2.y = q1.y;
            q2.x = q1.x + 1.0;
        }
        else
        {
            double k = (c.y - a.y) / (c.x - a.x);
            if (fcmp(k) == 0)
            {
                q2.x = q1.x;
                q2.y = q1.y + 1.0;
            }
            else{
                double k1 = -1.0 / k;
                double t = q1.y - k1 * q1.x; //y = k1 * x + t
                q2.x = q1.x + 1.0;
                q2.y = k1 * q2.x + t;
            }
        }
        point center = line_intersect(p1, p2, q1, q2).first;
        double r = dis(center, a);
        printf("%.2lf\n", 2.0 * pi * r);
    }
}