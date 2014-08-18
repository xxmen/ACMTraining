#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <stack>
using namespace std;
int ans = 0;
struct node
{
    node *next[53];
    node()
    {
        for (int i = 0; i < 53; i++)
            next[i] = NULL;
    }
};
node *root, *now;
void Inset(int x)
{
    if (now->next[x] == NULL)
    {
        now->next[x] = new node();
        ans++;
    }
    now = now->next[x];
}
void Delete(node *x)
{
    for (int i = 0; i < 53; i++)
    {
        if (x->next[i] != NULL)
            Delete(x->next[i]);
        x->next[i] = NULL;
    }
    delete x;
}

int work(string s)
{
    int res = 0, len = int(s.length());
    if(s[len - 1]=='D') res += 13;
    if(s[len - 1]=='H') res += 26;
    if(s[len - 1]=='S') res += 39;
    
    if (len == 3) return res + 10;
    
    if (s[0] == 'A') res += 1;
    else if (s[0] == 'J') res += 11;
    else if (s[0] == 'Q') res += 12;
    else if (s[0] == 'K') res += 13;
    else res += s[0] - '0';
    return res;
}
int main()
{
    int n;
    stack<string> sta;
    while (scanf("%d", &n) && n)
    {
        ans = 0;
        root = new node();
        for (int i = 0; i < n; i++)
        {
            int m;
            scanf("%d", &m);
            for (int j = 0; j < m; j++)
            {
                string s;
                cin>>s;
                sta.push(s);
            }
            now = root;
            while (!sta.empty())
            {
                Inset(work(sta.top()));
                sta.pop();
            }
        }
        printf("%d\n", ans);
        Delete(root);
    }
    return 0;
}