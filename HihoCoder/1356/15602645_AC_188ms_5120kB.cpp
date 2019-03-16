#include<bits/stdc++.h>
using namespace std;
map<int,int> m;
set<pair<int,int>> s;
int a[100010];
vector<pair<int,int>> v;
int main()
{
    int n;
    scanf("%d",&n);
    int i,j;
    for (i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        m[x]++;
        if (m[x]*2-1>n)
        {
            printf("-1\n");
            return 0;
        }
    }
    for (auto t=m.begin();t!=m.end();t++)
    {
        s.insert({t->second,t->first});
    }
    int last=-1;
    for (i=1;i<=n;i++)
    {
        if ((s.rbegin()->first)*2-1==n-i+1)
        {
            a[i]=s.rbegin()->second;
            last=a[i];
        }
        else
        {
            auto t=m.begin();
            if (t->first==last) t++;
            a[i]=t->first;
            last=a[i];
        }

        s.erase({m[a[i]],a[i]});
        m[a[i]]--;
        if (m[a[i]]==0)
        {
            m.erase(a[i]);
        }
        else
        {
            s.insert({{m[a[i]],a[i]}});
        }
    }
    for (i=1;i<=n;i++)
        printf("%d%c",a[i]," \n"[i==n]);
    return 0;
}
