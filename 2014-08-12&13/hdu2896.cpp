#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>
#include <string>
using namespace std;
string ch, str;
int n, tot = 0, ans[5], sum;
struct AC_auto
{
    int T[210 * 500][128], fail[210 * 500], a[210 * 500];
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
                    ans[sum++] = a[temp];
                temp = fail[temp];
            }
        }
        
    }
}AC;
int main()
{
    ios::sync_with_stdio(false);
    while (cin>>n)
    {
        tot = 0;
        AC.initTrie();
        for (int i = 1; i <= n; i++)
        {
            cin>>str;
            AC.insertWord(str, i);
        }
        AC.build();
        int m;
        scanf("%d", &m);
        for (int i = 1; i <= m; i++)
        {
            cin>>ch;
            memset(ans, 0, sizeof(ans));
            sum = 0;
            AC.query(ch);
            if (sum) sort(ans, ans + sum);
            if (sum)
            {
                cout<<"web "<<i<<":";
                for (int j = 0; j < sum; j++)
                    cout<<" "<<ans[j];
                cout<<endl;
                tot++;
            }
        }
        cout<<"total: "<<tot<<endl;
    }
    return 0;
}