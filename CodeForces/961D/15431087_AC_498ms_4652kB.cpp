#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
vector<pair<ll,ll> > p;

ll cross(pair<ll,ll> a ,pair<ll,ll> b ,pair<ll,ll> c)
{
    b.first-=a.first,b.second-=a.second;
    c.first-=a.first,c.second-=a.second;
    return b.first*c.second-b.second*c.first;
}
void tt(pair<ll,ll> a,pair<ll,ll> b)
{
    vector<pair<ll,ll> > z;
    for (auto x: p) if (cross(a,b,x)!=0) z.push_back(x);
    for (int i=2;i<z.size();i++) if (cross(z[0],z[1],z[i])!=0) return ;
    printf("yes\n");
    exit(0);
}

int main()
{
    scanf("%d",&n); p.resize(n);
    for (int i=0;i<n;i++)
        cin>>p[i].first>>p[i].second;
    if (n<3)
    {
        printf("YES\n");
        return 0;
    }
    tt(p[0],p[1]);
    tt(p[0],p[2]);
    tt(p[1],p[2]);
    printf("NO\n");
    return 0;
}
