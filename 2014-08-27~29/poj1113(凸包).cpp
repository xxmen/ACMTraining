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
}p[1010];
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
inline double dis(point a, point b)
{
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y) + 1e-6);
}
int top, sta[1010];
double Graham(int n, int l)
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
    double sum = 0;//凸包长度加上半径为l的圆周长
    for (int i = 0; i < top; i++)
        sum += dis(p[sta[i]], p[sta[i + 1]]);
    sum += 2 * pi * l;
    return sum;
}
int main()
{
    int n, l;
    while (~scanf("%d%d", &n, &l))
    {
        for (int i = 0; i < n; i++)
            scanf("%d%d", &p[i].x, &p[i].y);
        printf("%.0lf\n", Graham(n, l));
    }
}