#include<bits/stdc++.h>
using namespace std;
struct ac
{
    int x,y,w;
    bool operator<(const ac &b)const
    {
        if (x==b.x) return y>b.y;
        return x<b.x;
    }
}que[100005];
vector<int> v;
unordered_map<int,int> m;
int t[200005];
void add(int i,int x)
{
    while (i<200005)
    {
        t[i]=max(t[i],x);
        i+=i&-i;
    }
}
int ask(int i)
{
    int maxx=0;
    while (i)
    {
        maxx=max(maxx,t[i]);
        i-=i&-i;
    }
    return maxx;
}
int main()
{
    int T;scanf("%d",&T);
    while (T--)
    {
        memset(t,0,sizeof(t));
        v.clear();
        int n;scanf("%d",&n);
        for (int i=0;i<n;i++)
        {
            scanf("%d%d%d",&que[i].x,&que[i].y,&que[i].w);
            v.push_back(que[i].y);
        }
        /*
        sort(v.begin(),v.end());
        v.resize(unique(v.begin(),v.end())-v.begin());
        for (int i=0;i<n;i++)
        {
            que[i].x=lower_bound(v.begin(),v.end(),que[i].x)-v.begin()+1;
            que[i].y=lower_bound(v.begin(),v.end(),que[i].y)-v.begin()+1;
        }
        */

        sort(v.begin(),v.end());
        v.resize(unique(v.begin(),v.end())-v.begin());
        int sz=v.size();
        for (int i=0;i<sz;i++)
        {
            m[v[i]]=i+1;
        }
        for (int i=0;i<n;i++)
            que[i].y=m[que[i].y];
        sort(que,que+n);
        int ans=-1e9;
        for (int i=0;i<n;i++)
        {
            int tmp=ask(que[i].y-1);
            ans=max(ans,tmp+que[i].w);
            add(que[i].y,tmp+que[i].w);
        }
        printf("%d\n",ans);
    }
    return 0;
}
