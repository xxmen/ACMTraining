#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 2000;
const double eps=1e-10;
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
point pa[maxn];
point p[maxn];
point q[maxn];
double dir = 1; //输入点的方向顺时针1, 逆时针-1
int v,top;      //v为切割之后的点数
inline int dcmp(double x)
{
    if(fabs(x)<eps)
        return 0;
    return x>0?1:-1;
}
void intersection(point x, point y, double a, double b, double c)
{
    double u = abs(a * x.x + b * x.y + c);
    double v = abs(a * y.x + b * y.y + c);
    q[++top].x = (x.x * v + y.x * u)/(u + v);
    q[top].y = (x.y * v + y.y * u)/(u + v);
}
void cut(double a, double b, double c)
{
    top = 0;
    for (int i=1; i<=v; i++)
    {
        if ((a*p[i].x+b*p[i].y+c)*dir >= 0)
        {
            q[++top]=p[i];
        }
        else
        {
            if ((a*p[i-1].x+b*p[i-1].y+c) * dir > 0)
                intersection(p[i-1], p[i], a, b, c);
            if ((a*p[i+1].x+b*p[i+1].y+c) * dir > 0)
                intersection(p[i], p[i+1], a, b, c);
        }
    }
    for (int i=1; i<=top; i++)
        p[i]=q[i];
    p[0] = p[top];
    p[top+1] = p[1];
    v=top;
}
void halfplane(point t1,point t2) //右手四指为t1->t2 拇指为半平面方向
{
    double a,b,c;
    a = t2.y - t1.y;
    b = t1.x - t2.x;
    c = t2.x * t1.y - t2.y * t1.x;
    cut(a,b,c);
}
inline double cross(point a, point b)
{
    return a.x*b.y-a.y*b.x;
}
inline double cross(point a, point b, point o)
{
    return cross(a-o,b-o);
}
inline double get_area(int n)
{
    double area=0;
    for(int i = 1; i < n-1; i++)
        area+=cross(p[i],p[i+1],p[0]);
    area/=2;
    return fabs(area);
}
int main()
{
    int n, t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%lf%lf", &pa[i].x, &pa[i].y);
        pa[n + 1] = pa[1];
        for (int i = 1; i <= n + 1; i++)
            p[i] = pa[i];
        p[0] = p[n];
        v = n;
        for (int i = 1; i <= n; i++)
            halfplane(pa[i], pa[i + 1]);
        double ans = get_area(v);
        printf("%.2lf\n", ans);
    }
}
