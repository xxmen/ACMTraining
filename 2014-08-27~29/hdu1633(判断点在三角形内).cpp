#include <cstdio>
#include <cmath>
#include <cstring>
#include <utility>
using namespace std;
const double eps=1e-10;
const double pi=acos(-1.0);
inline int dcmp(double x)
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
int main()
{
    point a, b, c;
    while (1)
    {
        scanf("%lf%lf%lf%lf%lf%lf", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y);
        if (dcmp(a.x) == 0 && dcmp(a.y) == 0 && dcmp(b.x) == 0 && dcmp(b.y) == 0
        && dcmp(c.x) == 0 && dcmp(c.y) == 0)
            break;
        double area = fabs(cross(a, b, c));
        int ans = 0;
        for (int i = 1; i <= 99; i++)
            for (int j = 1; j <= 99; j++)
            {
                point tree;
                tree.x = i; tree.y = j;
                if (dcmp(fabs(cross(a, b, tree)) + fabs(cross(a, c, tree)) + fabs(cross(b, c, tree)) - area) == 0)
                    ans++;
            }
        printf("%4d\n", ans);
    }
}
