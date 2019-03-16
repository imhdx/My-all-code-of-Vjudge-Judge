#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
int pre[10010];
int a[10010];
int getx(int x)
{
    if (pre[x]==x) return x;
    return pre[x]=getx(pre[x]);
}

void nian(int x,int y)
{
    int xx=getx(x);
    int yy=getx(y);
    if (xx!=yy)
    {
        if (a[xx]==a[yy])
        {
            pre[max(xx,yy)]=min(xx,yy);
        }
        else
        {
            if (a[xx]<a[yy])
                pre[xx]=yy;
            else
                pre[yy]=xx;
        }
    }
}


set<pair<int,int> >s;
vector<pair<int,int> > v;
vector<int> ans;
int main()
{
    int n;
    int t=0;
    while (scanf("%d",&n)!=EOF)
    {
        if (t++) printf("\n");
        s.clear();
        v.clear();
        ans.clear();
        int i;
        for (i=0;i<=n;i++) pre[i]=i;
        for (i=0;i<n;i++)
            scanf("%d",&a[i]);
        int m;
        scanf("%d",&m);
        for (i=0;i<m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            s.insert({min(x,y),max(x,y)});
        }
        int q;
        scanf("%d",&q);
        for (i=0;i<q;i++)
        {
            getchar();
            char str[10];
            scanf("%s",str);
            if (str[0]=='q')
            {
                int x;
                scanf("%d",&x);
                v.push_back({x,x});
            }
            else if (str[0]=='d')
            {
                int x,y;
                scanf("%d%d",&x,&y);
                s.erase({min(x,y),max(x,y)});
                v.push_back({x,y});
            }
        }
        for (auto j=s.begin();j!=s.end();j++)
        {
            nian(j->fi,j->se);
        }

        for (i=v.size()-1;i>=0;i--)
        {
            if (v[i].fi==v[i].se)
            {
                if (a[v[i].fi]<a[getx(v[i].fi)])
                    ans.push_back(getx(v[i].fi));
                else
                    ans.push_back(-1);
            }
            else
            {
                nian(v[i].fi,v[i].se);
            }
        }
        for (i=ans.size()-1;i>=0;i--)
            printf("%d\n",ans[i]);
    }

    return 0;
}
