#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int maxn = 100010;
int trie[maxn][10], a[maxn], top = 0;;
void Trie_Init()
{
    top = 0;
    memset(trie, -1, sizeof(trie));
    memset(a, 0, sizeof(a));
}
void Trie_Insert(char *s)
{
    int i;
    for (i = 0; *s >= '0' && *s <= '9'; ++s)
    {
        if (trie[i][*s - '0'] == -1)
            trie[i][*s - '0'] = ++top;
        i = trie[i][*s - '0'];
    }
    a[i] = 1;
}
int Trie_Find(char *s)
{
    int i;
    for (i = 0; *s >= '0' && *s <= '9'; ++s)
    {
        if (trie[i][*s - '0'] == -1)
            return 0;
        i = trie[i][*s - '0'];
        if (a[i]) return 1;//已经插入的串是当前串的前缀
    }
    for (int j = 0; j < 10; j++)//当前串是已经插入的串的前缀
        if (trie[i][j]) return 1;
    return 0;
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        Trie_Init();
        bool flag = false;
        for (int i = 0; i < n; i++)
        {
            char ch[15];
            scanf("%s", ch);
            if (flag) continue;
            if (Trie_Find(ch)) flag = true;
            Trie_Insert(ch);
        }
        if (flag) puts("NO");
        else puts("YES");
    }
    return 0;
}