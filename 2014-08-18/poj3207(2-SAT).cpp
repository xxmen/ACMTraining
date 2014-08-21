#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1010;
const int MAXM = 1000010;
struct Edge
{
    int to,next;
}edge[MAXM];
int head[MAXN], tot = 0;
int Low[MAXN], DFN[MAXN], Stack[MAXN], Belong[MAXN], a[555], b[555];
int Index,top;
int scc = 0;
bool Instack[MAXN];
void addEdge(int u,int v)
{
    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot++;
}
void Dfs(int u)
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
            Dfs(v);
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
void Tarjan(int N)
{
    memset(DFN, 0, sizeof(DFN));
    memset(Instack, false, sizeof(Instack));
    Index = scc = top = 0;
    for(int i = 0; i < N; i++)
        if(!DFN[i])
            Dfs(i);
}
int main()
{
    int n, m;
    scanf("%d%d",&n, &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &a[i], &b[i]);
        if (a[i] > b[i])
            swap(a[i], b[i]);
    }
    memset(head, -1, sizeof(head));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            if ((a[i] < a[j] && b[i] > a[j] && b[j] > b[i]) || (a[i] > a[j] && a[i] < b[j] && b[i] > b[j]))
            //第i条边和第j条边会发生冲突
            {
                addEdge(2 * i, 2 * j + 1);//i在圆内则j在圆外
                addEdge(2 * j + 1, 2 * i);
                addEdge(2 * i + 1, 2 * j);//i在圆外则j在圆内
                addEdge(2 * j, 2 * i + 1);
            }
    Tarjan(2 * m);//求强联通分量
    for (int i = 0; i < 2 * m; i++)
        if(Belong[i] == Belong[i^1])//若i在圆内(2*i)和i在圆外(2*i+1)同在一个强联通分量中即矛盾
        {
            printf("the evil panda is lying again\n");
            return 0;
        }
    printf("panda is telling the truth...\n");
    return 0;
}