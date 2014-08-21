#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int M = 500010;
int col = 0, fa[M], d[M];
struct Node{
    bool flag;
    int id;
    Node *next[26];
    Node()
    {
        flag = false;
        id = 0;
        memset(next, 0, sizeof(next));
    }
}root;
int Find(int x)
{
    return fa[x] == x ? x : fa[x] = Find(fa[x]);
}
void Union(int x, int y)
{
    int fx = Find(x), fy = Find(y);
    fa[fx] = fy;
}
int Trie_word(char *s)
{
    Node *p = &root;
    int len = 0;
    while (s[len] != '\0')
    {
        int x = s[len++] - 'a';
        if (!p->next[x])
            p->next[x] = new Node();
        p = p->next[x];
    }
    if (p->flag)
        return p->id;
    else
    {
        p->flag = true;
        p->id = ++col;
        return p->id;
    }
}
int main()
{
    for (int i = 1; i < M; i++)
        fa[i] = i;
    char s1[15], s2[15];
    memset(d, 0, sizeof(d));
    while (~scanf("%s%s", s1, s2))
    {
        int u = Trie_word(s1), v = Trie_word(s2);
        d[u]++;d[v]++;
        Union(u, v);
    }
    int father = Find(1), sum = 0;
    for (int i = 1; i <= col; i++)
    {
        if (Find(i) != father)
        {
            puts("Impossible");
            return 0;
        }
        if (d[i] & 1) sum++;
    }
    if (sum > 2)
        puts("Impossible");
    else puts("Possible");
    return 0;
}