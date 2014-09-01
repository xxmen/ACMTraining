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
    int n;
    while (~scanf("%d", &n))
    {
        puts("INTERSECTING LINES OUTPUT");
        for (int i = 0; i < n; i++)
        {
            point p[4];
            for (int j = 0; j < 4; j++)
                scanf("%lf%lf", &p[j].x, &p[j].y);
            pair<point, int> ans = line_intersect(p[0], p[1], p[2], p[3]);
            if (ans.second == 0)
                puts("LINE");
            else if (ans.second == 1)
                puts("NONE");
            else printf("POINT %.2lf %.2lf\n", ans.first.x, ans.first.y);
        }
        puts("END OF OUTPUT");
    }
}