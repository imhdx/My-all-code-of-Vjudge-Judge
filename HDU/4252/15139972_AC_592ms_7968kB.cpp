#include<bits/stdc++.h>
using namespace std;

map<int,int> pos;
int last[100004];
int a[100003];
int n;
int tree[int(100000<<2)];
void build(int l,int r,int rt)
{
    if (l==r)
    {
        tree[rt]=a[l];
        return ;
    }
    int mid=(l+r)/2;
    build(l,mid,rt*2);
    build(mid+1,r,rt*2+1);
    tree[rt]=min(tree[rt*2],tree[rt*2+1]);
}
int query(int l,int r,int rt,int ll,int rr)
{
    if(ll<=l&&r<=rr)return tree[rt];
    int mid=(l+r)/2;
    int ans=1000000090;
    if (ll<=mid) ans=min(ans,query(l,mid,rt*2,ll,rr));
    if (rr>mid)ans=min(ans,query(mid+1,r,rt*2+1,ll,rr));
    return ans;
}

int main()
{
    int n;
    int T=1;
    while (scanf("%d",&n)!=EOF)
    {
        pos.clear();
        int i;
        for (i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            last[i]=pos[a[i]];
            pos[a[i]]=i;
        }
        build(1,n,1);
/*
        for (i=1;i<=n;i++)
        {
            for (int j=i;j<=n;j++)
            {
                printf("%d %d %d\n",i,j,query(1,n,1,i,j));
            }
        }
*/

        int ans=0;
        for (i=1;i<=n;i++)
        {
            if (a[i]==0) continue;
            if (last[i]==0)
                ans++;
            else
            {
                if (query(1,n,1,last[i],i)<a[i])
                    ans++;
            }
        }
        printf("Case %d: ",T++);
        printf("%d\n",ans);
    }
    return 0;
}
