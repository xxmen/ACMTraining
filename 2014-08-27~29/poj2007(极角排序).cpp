#include <cstdio>
#include <algorithm>
using namespace std;
struct point{
	int x, y;
}p[10000];
bool cmp(point x, point y)  
{
	return ((x.x * y.y - x.y * y.x) > 0);
}
int main()
{
    int n = 0;
    while (~scanf("%d%d", &p[n].x, &p[n].y))
	n++;
    printf("(0,0)\n");
    sort(p + 1, p + n, cmp);
    for (int j = 1; j < n; j++) 
	printf("(%d,%d)\n", p[j].x, p[j].y);
}
