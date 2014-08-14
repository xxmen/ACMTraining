#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;
map<int, int> row;
map<int, int> col;
map<int, map<int, int> > fruit;
int main()
{
    int T, Case = 0;
    scanf("%d", &T);
    while (T--)
    {
        int n, m, k, q;
        scanf("%d%d%d", &n, &m, &k);
        int r = 0, c = 0;
        row.clear();
        col.clear();
        fruit.clear();
        for (int i = 0; i < k; i++)
        {
            int x, y, energy;
            scanf("%d%d%d", &x, &y, &energy);
            if (!row[x])
                row[x] = ++r;
            if (!col[y])
                col[y] = ++c;
            fruit[row[x]][col[y]] = energy;
        }
        scanf("%d", &q);
        printf("Case #%d:\n", ++Case);
        for (int i = 0; i < q; i++)
        {
            int op, x, y;
            scanf("%d%d%d", &op, &x, &y);
            if (op == 1)
            {
                int t = row[x];
                row[x] = row[y];
                row[y] = t;
            }
            else if (op == 2)
            {
                int t = col[x];
                col[x] = col[y];
                col[y] = t;
            }
            else{
                printf("%d\n", fruit[row[x]][col[y]]);
            }
        }
    }
    return 0;
}