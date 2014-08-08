#include <cstdio>
#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include <set>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    map<string, string> a;
    set<string> b;
    string x, y, s;
    while (getline(cin, s))
    {
        if (s[0] < 'A') break;
        istringstream scin(s);
        scin>>x>>y;
        a[y] = x;
        b.insert(y);
    }
    while (cin>>x)
    {
        if (b.find(x) == b.end()) cout<<"eh"<<endl;
        else cout<<a[x]<<endl;
    }
    return 0;
}

