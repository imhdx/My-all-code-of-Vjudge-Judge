#include <bits/stdc++.h>
using namespace std;

set<string>myset;
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        string t;
        cin>>t;
        myset.insert(t);
    }
    cout<<myset.size()<<endl;
    return 0;
}
