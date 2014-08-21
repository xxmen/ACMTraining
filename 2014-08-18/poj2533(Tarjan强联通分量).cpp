#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 5005;
const int MAXM = 2500000;
struct Edge
{
    int to,next;
}edge[MAXM];
int head[MAXN],tot;
int Low[MAXN], DFN[MAXN], Stack[MAXN], Belong[MAXN];
bool OK[MAXN];
int Index,top;
int scc;
bool Instack[MAXN];

void addedge(int u,int v)
{
    edge[tot].to = v;edge[tot].next = head[u];head[u] = tot++;
}
void Tarjan(int u)
{
    int v;
    Low[u] = DFN[u] = ++Index;
    Stack[top++] = u;
    Instack[u] = true;
    for(int i = head[u]; i != -1; i = edge[i].next)
    {
        v = edge[i].to;
        if(!DFN[v])
        {
            Tarjan(v);
            if(Low[v] < Low[u])
                Low[u] = Low[v];
        }
        else if(Instack[v] && Low[v] < Low[u])
            Low[u] = DFN[v];
    }
    if(Low[u] == DFN[u])
    {
        scc++;
        do
        {
            v = Stack[--top];
            Belong[v] = scc;
            Instack[v] = false;
        }
        while(v != u);
    }
}
void solve(int N)
{
    memset(DFN, 0, sizeof(DFN));
    memset(Instack, false, sizeof(Instack));
    Index = scc = top = 0;
    for(int i = 1;i <= N;i++)
        if(!DFN[i])
            Tarjan(i);
}
void init()
{
    tot = 0;
    memset(head, -1, sizeof(head));
    memset(OK, true, sizeof(OK));
}
int main()
{
    int n, m;
    while(scanf("%d",&n) && n)
    {
        scanf("%d", &m);
        init();
        for(int i = 1;i <= m;i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            addedge(x, y);
        }
        solve(n);
        for(int i = 1; i <= n; i++)
        {
            for(int j = head[i]; j != -1; j = edge[j].next)
            {
                int v = edge[j].to;
                if(Belong[i] != Belong[v])
                    OK[Belong[i]] = false;
            }
        }
        bool flag = true;
        for (int i = 1; i <= n; i++)
            if (OK[Belong[i]])
            {
                if (flag) { printf("%d", i); flag = false;}
                else printf(" %d", i);
            }
        puts("");
    }
    return 0;
}