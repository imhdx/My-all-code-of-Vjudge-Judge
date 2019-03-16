#include<bits/stdc++.h>
using namespace std;

map<int,int> M;
int vis[100003];
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
    if (ll>mid) ans=min(ans,query(mid+1,r,rt*2+1,ll,rr));
    return ans;
}

int main()
{
    int n;
    int T=1;
    while (scanf("%d",&n)!=EOF)
    {
        printf("Case %d: ",T++);
        memset(vis,0,sizeof(vis));
        M.clear();
        int i;
        for (i=1;i<=n;i++)
            scanf("%d",&a[i]);
        build(1,n,1);
        int cnt=0;
        int m=0;
        for (i=1;i<=n;i++)
        {




            if (M[a[i]]==0&&vis[i]==0)
            {
                vis[i]=1;
                cnt++;
            }
            else if (M[a[i]]!=0&&vis[M[a[i]]]==0)
            {
                if (query(1,n,1,M[a[i]],i)>=a[i])
                {
                    vis[i]=1;
                    cnt++;
                }
            }
            else if (M[a[i]]!=0&&vis[M[a[i]]]==1)
            {
                if (query(1,n,1,M[a[i]],i)>=a[i])
                {
                    vis[i]=1;
                    continue;
                }
                else
                    vis[i]=0;
            }
            M[a[i]]=i;
        }
        printf("%d\n",cnt);

    }
    return 0;
}
