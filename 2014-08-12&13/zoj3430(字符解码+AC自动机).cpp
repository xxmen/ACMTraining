#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
#include <queue>
using namespace std;
const int maxn = 520*64;
int n, m, tot, b[10000];
unsigned char str[5000], s[5000];
char ch[5000];
struct AC_auto
{
    int T[maxn][256], fail[maxn], end[maxn];
    bool v[520];
    int root,  L;
    int addNode()
    {
        for (int i = 0; i < 256; i++)
            T[L][i] = -1;
        end[L++] = -1;
        return L - 1;
    }
    void initTrie()
    {
        L = 0;
        root = addNode();
    }
    void insertWord(unsigned char s[], int len, int id)
    {
        int now = root;
        for (int i =  0; i < len; i++)
        {
            if (T[now][s[i]] == -1)
                T[now][s[i]] = addNode();
            now = T[now][s[i]];
        }
        end[now] = id;
    }
    void build()
    {
        queue<int> q;
        fail[root] = root;
        for (int i = 0; i < 256; i++)
            if (T[root][i] == -1)
                T[root][i]  = root;
            else
            {
                fail[T[root][i]] = root;
                q.push(T[root][i]);
            }
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            for (int i = 0; i < 256; i++)
                if (T[x][i] == -1)
                    T[x][i] = T[fail[x]][i];
                else
                {
                    fail[T[x][i]] = T[fail[x]][i];
                    q.push(T[x][i]);
                }
        }
    }
    int query(unsigned char s[], int len)
    {
        int now = root;
        int ans = 0;
        memset(v, false, sizeof(v));
        for (int i = 0; i < len; i++)
        {
            now = T[now][s[i]];
            int temp = now;
            while (temp != root)
            {
                if (end[temp] != -1)
                    v[end[temp]] = true;
                temp = fail[temp];
            }
        }
        for (int i = 0; i < n; i++)
            if (v[i])
                ans++;
        return ans;
    }
}AC;
unsigned char Get(char c)
{
    if (c >= 'A' && c <= 'Z') return c - 'A';
    if (c >= 'a' && c <= 'z') return c - 'a' + 26;
    if (c >= '0' && c <='9') return c - '0' + 52;
    if (c == '+') return 62;
    else return 63;
}
void Change(unsigned char s[], int len)
{
    int t = 0;
    for (int i = 0; i < len; i += 4)
    {
        str[t++] = ((s[i] << 2) | (s[i + 1] >> 4));
        if(i + 2 < len)
            str[t++] = ((s[i + 1] << 4) | (s[i + 2] >> 2));
        if(i + 3 < len)
            str[t++] = ((s[i + 2] << 6) | s[i + 3]);
    }
    tot = t;
}
int main()
{
    while (~scanf("%d", &n))
    {
        AC.initTrie();
        for (int i = 0; i < n; i++)
        {
            scanf("%s", ch);
            int len = int(strlen(ch));
            while (ch[len - 1] == '=') len--;
            for (int j = 0; j < len; j++)
                s[j] = Get(ch[j]);
            Change(s, len);
            AC.insertWord(str, tot, i);
        }
        AC.build();
        scanf("%d", &m);
        for (int i = 0; i < m; i++)
        {
            scanf("%s", ch);
            int len = int(strlen(ch));
            while (ch[len - 1] == '=') len--;
            for (int j = 0;j < len;j++)
                s[j] = Get(ch[j]);
            Change(s,len);
            printf("%d\n", AC.query(str, tot));
        }
        printf("\n");
    }
    return 0;
}
