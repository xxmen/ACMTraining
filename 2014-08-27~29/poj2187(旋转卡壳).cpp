#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
double pi = acos(-1.0);
struct point
{
    int x, y;
    point() {}
    point(int _x, int _y) : x(_x), y(_y) {}
    friend point operator - (point a, point b)
    {
        return point(a.x - b.x, a.y - b.y);
    }
}p[50010];
bool cmp(point a, point b)
{
    if (a.y == b.y) return a.x < b.x;
    return a.y < b.y;
}
inline int cross(point a, point b)
{
    return a.x * b.y - a.y * b.x;
}
inline int cross(point a, point b, point o)
{
    return cross(a - o, b - o);
}
int top, sta[50010];
int sqr_dis(point a, point b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
double rotating_calipers(point *c, int n)//c为凸包点集, n为凸包中点的个数
{
    int q = 1;
    int ans = 0;
    c[n] = c[0];
    for(int p = 0; p < n; p++)
    {
        while(cross(c[p + 1], c[ q + 1], c[p]) > cross(c[p + 1], c[q], c[p]))
            q = (q + 1) % n;
        ans = max(ans, max(sqr_dis(c[p], c[q]),sqr_dis(c[p + 1], c[q + 1])));
    }
    return ans;
}
point c[50010];
int Graham(int n)
{
    sort(p, p + n, cmp);
    top = 1;
    sta[0] = 0; sta[1] = 1;
    for (int i = 2; i < n; i++)
    {
        while (top >= 1 && cross(p[i], p[sta[top]], p[sta[top - 1]]) >= 0)
            top--;
        sta[++top] = i;
    }
    sta[++top] = n - 2;
    int tmp = top;
    for (int i = n - 3; i >= 0; i--)
    {
        while (top >= tmp && cross(p[i], p[sta[top]], p[sta[top - 1]]) >= 0)
            top--;
        sta[++top] = i;
    }
    for (int i = 0; i < top; i++)
        c[i] = p[sta[i]];
    return rotating_calipers(c, top);
}
int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        for (int i = 0; i < n; i++)
            scanf("%d%d", &p[i].x, &p[i].y);
        printf("%d\n", Graham(n));
    }
}