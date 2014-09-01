#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
using namespace std;
typedef long long LL;
const int maxn = 1000010;
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
string s;
int n;
point p[maxn];
inline LL cross(point a, point b)
{
    return (LL)a.x * (LL)b.y - (LL)a.y * (LL)b.x;
}
inline LL cross(point a, point b, point o)
{
    return cross(a-o,b-o);
}
inline LL get_area(int m)
{
    LL area = 0;
    for(int i = 1; i < m - 1; i++)
        area += cross(p[i],p[i+1],p[0]);
    return area >= 0 ? area : -area;
}
pair<int, int> dir(int x)
{
    if (x == 8)
        return make_pair(0, 1);
    if (x == 2)
        return make_pair(0, -1);
    if (x == 6)
        return make_pair(1, 0);
    if (x == 4)
        return make_pair(-1, 0);
    if (x == 9)
        return make_pair(1, 1);
    if (x == 7)
        return make_pair(-1, 1);
    if (x == 3)
        return make_pair(1, -1);
    if (x == 1)
        return make_pair(-1, -1);
}
int main()
{
    int t;
    ios::sync_with_stdio(false);
    cin>>t;
    while (t--)
    {
        cin>>s;
        int n = (int)s.length();
        if (n < 3)
        {
            printf("0\n");
            continue;
        }
        int m = 0;
        p[0] = point(0, 0);
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '5') break;
            pair<int, int> d = dir(s[i] - '0');
            if (i && s[i] == s[i - 1])
            {
                p[m].x += d.first;
                p[m].y += d.second;
                continue;
            }
            p[m + 1].x = p[m].x + d.first;
            p[m + 1].y = p[m].y + d.second;
            m++;
        }
        p[++m] = point(0, 0);
        LL area = get_area(m);
        if (area & 1)
            cout<<area / 2<<".5"<<endl;
        else cout<<area / 2<<endl;
    }
}
