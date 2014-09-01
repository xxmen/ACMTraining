#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstring>
#include <algorithm>
using namespace std;
const double eps=1e-10;
const int maxn=5005;
const double pi=acos(-1.0);
inline int dcmp(double x)
{
    if(fabs(x)<eps)
        return 0;
    return x>0?1:-1;
}
struct pt
{
    double x,y;
    pt() {}
    pt(double _x,double _y):x(_x),y(_y) {}
    friend pt operator + (pt a,pt b)
    {
        return pt(a.x+b.x,a.y+b.y);
    }
    friend pt operator - (pt a,pt b)
    {
        return pt(a.x-b.x , a.y-b.y);
    }
    friend pt operator * (pt a,double d)
    {
        return pt(a.x*d , a.y*d);
    }
    friend pt operator / (pt a,double d)
    {
        return pt(a.x/d , a.y/d);
    }
    friend bool operator == (pt a,pt b)
    {
        return dcmp(a.x-b.x)==0 && dcmp(a.y-b.y)==0;
    }
    friend bool operator != (pt a,pt b)
    {
        return dcmp(a.x-b.x)!=0 || dcmp(a.y-b.y)!=0;
    }
};
pt p[maxn];
inline bool isint(double x)
{
    return fabs(x-(int)(x+0.5))<eps;
}
inline double dis(pt a,pt b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
inline double earth_dis(pt a,pt b)
{
    double x1=pi*a.x/180.0;
    double y1=pi*a.y/180.0;
    double x2=pi*b.x/180.0;
    double y2=pi*b.y/180.0;
    return acos(cos(x1-x2)*cos(y1)*cos(y2)+sin(y1)*sin(y2));
}
inline double cross(pt a,pt b)
{
    return a.x*b.y-a.y*b.x;
}
inline double cross(pt a,pt b,pt o)
{
    return cross(a-o,b-o);
}
inline double cross(pt a,pt b,pt c,pt d)
{
    return cross(b-a,d-c);
}
inline double fabscross(pt a,pt b,pt o)
{
    return fabs(cross(a-o,b-o));
}
inline double dot(pt a,pt b)
{
    return a.x*b.x + a.y*b.y;
}
inline double dot(pt a,pt b,pt o)
{
    return dot(a-o,b-o);
}
inline double angle(pt a,pt b,pt o)
{
    double ao=atan2(a.y-o.y,a.x-o.x);
    double bo=atan2(b.y-o.y,b.x-o.x);
    return fabs(ao-bo)>=pi?(pi*2-fabs(ao-bo)):fabs(ao-bo);
}
inline double dis_pt_to_line(pt o,pt a,pt b)
{
    pt v1 = b-a;
    pt v2 = o-a;
    return fabs(cross(v1,v2))/dis(a,b);
}
inline double dis_pt_to_seg(pt o,pt a,pt b)
{
    if(a==b)
        return dis(o,a);
    pt v1 = b-a;
    pt v2 = o-a;
    pt v3 = o-b;
    if(dcmp(dot(v1,v2))<0)
        return dis(o,a);
    else if(dcmp(dot(v1,v3))>0)
        return dis(o,b);
    else
        return fabs(cross(v1,v2))/dis(a,b);
}
inline bool intersect_seg(pt a,pt b,pt c,pt d)
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
    int t;
    scanf("%d", &t);
    while (t--)
    {
        pt p1, p2;
        scanf("%lf%lf%lf%lf", &p1.x, &p1.y, &p2.x, &p2.y);
        double xl, xr, yl, yh;
        pt a, b, c, d;
        scanf("%lf%lf%lf%lf", &xl, &yh, &xr, &yl);
        if (xl > xr) swap(xl, xr);
        if (yl > yh) swap(yl, yh);
        a.x = xl; a.y = yh;
        b.x = xr; b.y = yh;
        c.x = xl; c.y = yl;
        d.x = xr; d.y = yl;
        bool flag = false;
        if (min(p1.x, p2.x) >= xl && max(p1.x, p2.x) <= xr && min(p1.y, p2.y) >= yl && max(p1.y, p2.y) <= yh)
            flag = true;
        if (intersect_seg(p1, p2, a, b)) flag = true;
        if (intersect_seg(p1, p2, a, c)) flag = true;
        if (intersect_seg(p1, p2, b, d)) flag = true;
        if (intersect_seg(p1, p2, c, d)) flag = true;
        if (flag)
            puts("T");
        else puts("F");
    }
    return 0;
}
