#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 101000;
const double eps = 1e-10;
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
int n;
point p[maxn], q[maxn];
int ans[1010];
inline int dcmp(double x)
{
    if(fabs(x)<eps)
        return 0;
    return x>0?1:-1;
}
inline double dot(point a, point b)
{
    return a.x*b.x + a.y*b.y;
}
inline double dot(point a, point b, point o)
{
    return dot(a-o,b-o);
}
inline double cross(point a, point b)
{
    return a.x*b.y-a.y*b.x;
}
inline double cross(point a, point b, point o)
{
    return cross(a-o,b-o);
}
inline bool intersect_seg(point a, point b, point c, point d)
{
    int d1 = dcmp( cross(a,b,c) );
    int d2 = dcmp( cross(a,b,d) );
    int d3 = dcmp( cross(c,d,a) );
    int d4 = dcmp( cross(c,d,b) );
    if((d1*d2<0&&d3*d4<0))
        return true;
    else if(d1==0&&dot(a,b,c)<=0)
        return true;
    else if(d2==0&&dot(a,b,d)<=0)
        return true;
    else if(d3==0&&dot(c,d,a)<=0)
        return true;
    else if(d4==0&&dot(c,d,b)<=0)
        return true;
    else
        return false;
}
int main()
{
    while (scanf("%d", &n) && n)
    {
        for (int i = 1; i <= n; i++)
            scanf("%lf%lf%lf%lf", &p[i].x, &p[i].y, &q[i].x, &q[i].y);
        int m = 0;
        for (int i = 1; i <= n; i++)
        {
            bool flag = true;
            for (int j = i + 1; j <= n; j++)
                if (intersect_seg(p[i], q[i], p[j], q[j]))
                {
                    flag = false;
                    break;
                }
            if (flag) ans[m++] = i;
        }
        printf("Top sticks:");
        for (int i = 0; i < m - 1; i++)
            printf(" %d,", ans[i]);
        printf(" %d.\n", ans[m - 1]);
    }
}
