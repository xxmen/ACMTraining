#include <cstdio>
#include <cstring>
#include <algorithm>
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
using namespace std;
const int maxn = 150000;
int c[maxn << 2], Xor[maxn << 2];
bool b[maxn];
void pushDown(int rt)
{
    if (c[rt] != -1)
    {
        c[rt << 1] = c[rt << 1 | 1] = c[rt];
        Xor[rt << 1] = Xor[rt << 1 | 1] = 0;
        c[rt] = -1;
    }
    if (Xor[rt])
    {
        if (c[rt << 1] != -1)
            c[rt << 1] ^= 1;
        else Xor[rt << 1] ^= 1;
        if (c[rt << 1 | 1] != -1)
            c[rt << 1 | 1] ^= 1;
        else Xor[rt << 1 | 1] ^= 1;
        Xor[rt] = 0;
    }
}
void update(char op, int L, int R, int l, int r, int rt)
{
    if (L <= l && R >= r)
    {
        if (op == 'U')
        {
            c[rt] = 1;
            Xor[rt] = 0;
        }
        else if (op == 'D')
        {
            c[rt] = 0;
            Xor[rt] = 0;
        }
        else if (op == 'C' || op == 'S')
        {
            if (c[rt] != -1)
                c[rt] ^= 1;
            else Xor[rt] ^= 1;
        }
        return;
    }
    pushDown(rt);
    int m = (l + r) >> 1;
    if (L <= m) update(op, L, R, lson);
    else if (op == 'I' || op == 'C')
        c[rt << 1] = Xor[rt << 1] = 0;
    if (R > m) update(op, L, R, rson);
    else if (op == 'I' || op == 'C')
        c[rt << 1 | 1] = Xor[rt << 1 | 1] = 0;

}
void query(int l, int r, int rt)
{
    if (c[rt] > -1)
    {
        if (c[rt] == 1)
        {
            for (int i = l; i <= r; i++)
                b[i] = true;
        }
        return;
    }
	pushDown(rt);
	int m = (l + r) >> 1;
	query(lson);
	query(rson);
}
int main()
{
    c[1] = Xor[1] = 0;
    char op , l , r;
	int x , y;
	while (~scanf("%c %c%d,%d%c\n",&op , &l , &x , &y , &r))
    {
		x <<= 1 , y <<= 1;
		if (l == '(') x++;
		if (r == ')') y--;
		if (x > y)
        {
			if (op == 'C' || op == 'I')
				c[1] = Xor[1] = 0;
		}
        else update(op, x, y, 0, maxn, 1);
	}
	query(0, maxn, 1);
	bool flag = false;
	int st = -1 , end = 0;
	for (int i = 0 ; i <= maxn ; i ++)
    {
		if (b[i])
        {
			if (st == -1) st = i;
			end = i;
		}
        else {
			if (st != -1)
            {
				if (flag) printf(" ");
				flag = true;
				printf("%c%d,%d%c",st & 1 ?'(':'[', st>>1, (end+1)>>1 , end & 1?')':']');
				st = -1;
			}
		}
	}
	if (!flag) printf("empty set");
	printf("\n");
    return 0;
}