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
        s.insert(make_pair(a[i],i));
    }
    int m;
    scanf("%d",&m);
    for (int i=0;i<m;i++)
    {
        int op,x;
        scanf("%d%d",&op,&x);
        if (op!=0)
        {
            s.erase(make_pair(a[op],op));
            a[op]+=x;
            s.insert(make_pair(a[op],op));
        }
        else{
            set<pair<int,int> >::iterator it=s.begin();
            int pos=it->second;
            s.erase(it);
            a[pos]+=x;
            s.insert(make_pair(a[pos],pos));
        }
    }
    set<pair<int,int> >::iterator it=s.begin();
    printf("Case %d: %d %d\n",t++,it->second,it->first);}
    return 0;
}
