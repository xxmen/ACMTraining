#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>
#include <string>
using namespace std;
const int maxn = 50005;
string ch, str[1010];
int n, num[1010];
struct AC_auto
{
    int T[maxn][128], fail[maxn], a[maxn];
    int root,  L;
    int addNode()
    {
        for (int i = 0; i < 128; i++)
            T[L][i] = -1;
        a[L++] = 0;
        return L - 1;
    }
    void initTrie()
    {
        L = 0;
        root = addNode();
        memset(num, 0, sizeof(num));
    }
    void insertWord(string s, int id)
    {
        int len = int(s.length());
        int now = root;
        for (int i =  0; i < len; i++)
        {
            if (T[now][s[i]] == -1)
                T[now][s[i]] = addNode();
            now = T[now][s[i]];
        }
        a[now] = id;//记录当前特征码的序号
    }
    void build()
    {
        queue<int> q;
        fail[root] = root;
        for (int i = 0; i < 128; i++)
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
            for (int i = 0; i < 128; i++)
                if (T[x][i] == -1)
                    T[x][i] = T[fail[x]][i];
                else
                {
                    fail[T[x][i]] = T[fail[x]][i];
                    q.push(T[x][i]);
                }
        }
    }
    void query(string s)
    {
        int len = int(s.length());
        int now = root;
        for (int i = 0; i < len; i++)
        {
            now = T[now][s[i]];
            int temp = now;
            while (temp != root)
            {
                if (a[temp])
                    num[a[temp]]++;
                temp = fail[temp];
            }
        }
        for (int i = 1; i <= n; i++)
            if (num[i])
                cout<<str[i]<<": "<<num[i]<<endl;
    }
}AC;
int main()
{
    ios::sync_with_stdio(false);
    while (cin>>n)
    {
        AC.initTrie();
        for (int i = 1; i <= n; i++)
        {
            cin>>str[i];
            AC.insertWord(str[i], i);
        }
        AC.build();
        cin>>ch;
        AC.query(ch);
    }
    return 0;
}