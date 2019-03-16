#include<bits/stdc++.h>
using namespace std;
set<pair<int,int> >s;
int a[10004];
int main()
{
    int t=1;
    int T;
    scanf("%d",&T);
    while (T--){
    s.clear();
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        s.insert({a[i],i});
    }
    int m;
    scanf("%d",&m);
    for (int i=0;i<m;i++)
    {
        int op,x;
        scanf("%d%d",&op,&x);
        if (op!=0)
        {
            s.erase({a[op],op});
            a[op]+=x;
            s.insert({a[op],op});
        }
        else{
            auto it=s.begin();
            int pos=it->second;
            s.erase(it);
            a[pos]+=x;
            s.insert({a[pos],pos});
        }
    }
    auto it=s.begin();
    printf("Case %d: %d %d\n",t++,it->second,it->first);}
    return 0;
}