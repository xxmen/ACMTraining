#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 110;
struct point
{
    int x, y;
    point() {}
    point(int _x, int _y) : x(_x), y(_y) {}
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
void intersection(point x, point y, int a, int b, int c)
{
    int u = abs(a * x.x + b * x.y + c);
    int v = abs(a * y.x + b * y.y + c);
    q[++top].x = (x.x * v + y.x * u)/(u + v);
    q[top].y = (x.y * v + y.y * u)/(u + v);
}
void cut(int a, int b, int c)
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
    int a,b,c;
    a = t2.y - t1.y;
    b = t1.x - t2.x;
    c = t2.x * t1.y - t2.y * t1.x;
    cut(a,b,c);
}
int main()
{
    int n, Floor = 0;
    while (scanf("%d", &n) && n)
    {
        for (int i = 1; i <= n; i++)
            scanf("%d%d", &pa[i].x, &pa[i].y);
        pa[n + 1] = pa[1];
        for (int i = 1; i <= n + 1; i++)
            p[i] = pa[i];
        p[0] = p[n];
        v = n;
        for (int i = 1; i <= n; i++)
            halfplane(pa[i], pa[i + 1]);
        printf("Floor #%d\n", ++Floor);
        if (v)
            puts("Surveillance is possible.");
        else puts("Surveillance is impossible.");
        puts("");
    }
}