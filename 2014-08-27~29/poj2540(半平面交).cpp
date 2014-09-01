#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const double eps = 1e-10;
const int maxn = 210;
struct point{
    double x, y;
};
struct line{
    double a, b, c;
};
string s;
int n;
point pa[maxn];
point p[maxn];
point q[maxn];
int v,top;      //v为切割之后的点数
inline int dcmp(double x)
{
    if(fabs(x)<eps)
        return 0;
    return x>0?1:-1;
}
double cross(point a,point b,point c)
{
	return (a.x-c.x)*(b.y-c.y)-(b.x-c.x)*(a.y-c.y);
}
line getLine(point p1, point p2)
{
    line temp;
    temp.a = p2.y - p1.y;
    temp.b = p1.x - p2.x;
    temp.c = p2.x * p1.y - p1.x * p2.y;
    return temp;
}
line get_mid_line(point a, point b)//求点a和b的对称轴直线
{
    line teml, midl;
    point temp;
    double dir;
    temp.x = (a.x + b.x) / 2.0;
    temp.y = (a.y + b.y) / 2.0;
    teml = getLine(a, b);
    midl.a = teml.b;
    midl.b = -teml.a;
    midl.c = (-midl.a * temp.x) + (-midl.b * temp.y);
    dir = midl.a * a.x + midl.b * a.y + midl.c;
    if (s[0] == 'C')
    {
        if (dcmp(dir) >= 0)
            return midl;
        midl.a *= -1.0;
        midl.b *= -1.0;
        midl.c *= -1.0;
        return midl;
    }
    else
    {
        if (dcmp(dir) <= 0)
            return midl;
        midl.a *= -1.0;
        midl.b *= -1.0;
        midl.c *= -1.0;
        return midl;
    }
}
point intersect(point x,point y,line k)
{
	point temp;
    double u = fabs(k.a * x.x + k.b * x.y + k.c);
    double v = fabs(k.a * y.x + k.b * y.y + k.c);
	temp.x = (x.x * v + y.x * u) / (u + v);
	temp.y = (x.y * v +y.y * u) / (u + v);
    return temp;
}
void cut(line L)
{
    double a = L.a, b = L.b, c = L.c;
    top = 0;
    for (int i = 1; i <= v; i++)
    {
        if (dcmp(a*p[i].x+b*p[i].y+c) >= 0)
            q[++top] = p[i];
        else
        {
            if (dcmp(a*p[i-1].x+b*p[i-1].y+c) > 0)
                q[++top]=intersect(p[i - 1], p[i], L);
            if(dcmp(a*p[i + 1].x + b * p[i + 1].y + c) > 0)
				q[++top] = intersect(p[i + 1], p[i], L);
        }
    }
    for (int i = 1; i <= top; i++)
        p[i] = q[i];
    p[top + 1] = q[1];
    p[0] = p[top];
    v = top;
    double ans = 0;
    for (int i = 3; i <= top; i++)
        ans += cross(p[1], p[i - 1], p[i]);
    ans = fabs(ans) / 2.0;
    printf("%.2lf\n", ans);
}
void init()
{
    pa[1].x = pa[1].y = 0.0;
    pa[2].x = 0.0; pa[2].y = 10.0;
    pa[3].x = pa[3].y = 10.0;
    pa[4].x = 10.0; pa[4].y = 0.0;
    pa[0] = pa[4];
    pa[5] = pa[1];
    v = 4;
    for (int i = 1; i <= 4; i++)
        p[i] = pa[i];
    p[0] = p[4];
    p[5] = p[1];
}
int main()
{
    line edge;
    point p_last, p_now;
    p_last.x = p_last.y = 0.0;
    init();
    bool flag = false;
    while (cin>>p_now.x>>p_now.y>>s)
    {
        if (s[0] == 'S' || flag)
        {
            flag = true;
            printf("0.00\n");
            continue;
        }
        edge = get_mid_line(p_last, p_now);
        cut(edge);
        p_last = p_now;
    }
    return 0;
}