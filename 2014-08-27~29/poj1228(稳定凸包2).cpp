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
int top, sta[1010];
int f[1010];
bool Graham(int n)
{
    memset(f, 0, sizeof(f));
    sort(p, p + n, cmp);
    top = 1;
    sta[0] = 0; sta[1] = 1;
    for (int i = 2; i < n; i++)
    {
        while (top >= 1 && cross(p[i], p[sta[top]], p[sta[top - 1]]) >= 0)
        {
            if (cross(p[i], p[sta[top]], p[sta[top - 1]]) == 0)
                f[sta[top - 1]]++;
            top--;
        }
        sta[++top] = i;
    }
    sta[++top] = n - 2;
    int tmp = top;
    for (int i = n - 3; i >= 0; i--)
    {
        while (top >= tmp && cross(p[i], p[sta[top]], p[sta[top - 1]]) >= 0)
        {
            if (cross(p[i], p[sta[top]], p[sta[top - 1]]) == 0)
                f[sta[top - 1]]++;
            top--;
        }
        sta[++top] = i;
    }
    if (top < 3) return false;//n点共线的情况
    for (int i = 0; i < top; i++)
        if (f[sta[i]] == 0) return false;
    return true;
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d%d", &p[i].x, &p[i].y);
        if (n < 6) puts("NO");
        else if (Graham(n)) puts("YES");
        else puts("NO");
    }
}
