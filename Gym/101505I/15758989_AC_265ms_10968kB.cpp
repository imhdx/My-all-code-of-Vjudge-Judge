#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5+7;

ll sum[maxn<<2];
ll MAX[maxn<<2];
ll MIN[maxn<<2];
ll t[maxn];
ll a[maxn];
void pushup(int rt)
{
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
    MAX[rt]=max(MAX[rt<<1],MAX[rt<<1|1]);
    MIN[rt]=min(MIN[rt<<1],MIN[rt<<1|1]);
}
void MT(int l,int r,int rt)
{
    if(l==r)
    {
        sum[rt]=a[l];
        MAX[rt]=a[l];
        MIN[rt]=a[l];
        return ;
    }
    int mid = (l+r)>>1;
    MT(l,mid,rt<<1);
    MT(mid+1,r,rt<<1|1);
    pushup(rt);
}

ll query(int L,int R,int l,int r,int rt)
{
    if(L<=l&&r<=R)
        return sum[rt];
    int mid = (l+r)>>1;
    ll ans =0;
    if(L<=mid)
        ans +=query(L,R,l,mid,rt<<1);
    if(R>mid)
        ans +=query(L,R,mid+1,r,rt<<1|1);
    return ans;
}

ll querymin(int L,int R,int l,int r,int rt)
{
    if(L<=l&&r<=R)
        return MIN[rt];
    int mid = (l+r)>>1;
    ll ans= 1e12;
    if(L<=mid)
        ans = min(ans,querymin(L,R,l,mid,rt<<1));
    if(R>mid)
        ans=min(ans,querymin(L,R,mid+1,r,rt<<1|1));
    return ans;
}

ll querymax(int L,int R,int l,int r,int rt)
{
    if(L<=l&&r<=R)
        return MAX[rt];
    int mid = (l+r)>>1;
    ll ans= -1e12;
    if(L<=mid)
        ans = max(ans,querymax(L,R,l,mid,rt<<1));
    if(R>mid)
        ans=max(ans,querymax(L,R,mid+1,r,rt<<1|1));
    return ans;
}
char op1[20];
char op2[20];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        memset(op1,0,sizeof(op1));
        memset(op2,0,sizeof(op2));
        for(int i=1; i<=n; i++)
            scanf("%lld%lld",&t[i],&a[i]);
        MT(1,n,1);
        int m,x;
        scanf("%d",&m);
        while(m--)
        {
            scanf("%s%s%d",op1,op2,&x);
            if(op1[0]=='g')
            {
                if(op2[1]=='i')
                {
                    int ans=0;
                    for(int i=1; i<=n; i++)
                    {
                        if(i==1) continue;
                        long long int tt = t[i]-x;
                        int p=lower_bound(t+1,t+1+n,tt)-t;
                        int q=upper_bound(t+1,t+1+n,t[i]-1)-t;
                        q--;
                        if (p>q) continue;
                        long long int mi = querymin(p,q,1,n,1);
                        if(a[i]>mi)
                            ans++;
                    }
                    printf("%d\n",ans);
                }
                else if(op2[1]=='a')
                {
                    int ans=0;
                    for(int i=1; i<=n; i++)
                    {
                        if(i==1) continue;
                        long long int tt = t[i]-x;
                        int p = lower_bound(t+1,t+1+n,tt)-t;
                        int q=upper_bound(t+1,t+1+n,t[i]-1)-t;
                        q--;
                        if (p>q) continue;
                        long long int ma = querymax(p,q,1,n,1);
                        if(a[i]>ma)
                            ans++;
                    }
                    printf("%d\n",ans);
                }
                else if(op2[1]=='v')
                {
                    int ans=0;
                    for(int i=1; i<=n; i++)
                    {
                        if(i==1) continue;
                        long long int tt = t[i]-x;
                        int p = lower_bound(t+1,t+1+n,tt)-t;
                        int q=upper_bound(t+1,t+1+n,t[i]-1)-t;
                        q--;
                        if (p>q) continue;
                        ll sum = query(p,q,1,n,1);
                        if(a[i]*(q-p+1)>sum)
                            ans++;
                    }
                    printf("%d\n",ans);
                }
            }
            else
            {
                if(op2[1]=='i')
                {
                    int ans=0;
                    for(int i=1; i<=n; i++)
                    {
                        if(i==1) continue;
                        long long int tt = t[i]-x;
                        int p=lower_bound(t+1,t+1+n,tt)-t;
                        int q=upper_bound(t+1,t+1+n,t[i]-1)-t;
                        q--;
                        if (p>q) continue;
                        long long mi = querymin(p,q,1,n,1);
                        if(a[i]<mi)
                            ans++;
                    }
                    printf("%d\n",ans);
                }
                else if(op2[1]=='a')
                {
                    int ans=0;
                    for(int i=1; i<=n; i++)
                    {
                        if(i==1) continue;
                        long long int tt = t[i]-x;
                        int p = lower_bound(t+1,t+1+n,tt)-t;
                        int q=upper_bound(t+1,t+1+n,t[i]-1)-t;
                        q--;
                        if (p>q) continue;
                        long long int ma = querymax(p,q,1,n,1);
                        if(a[i]<ma)
                            ans++;
                    }
                    printf("%d\n",ans);
                }
                else if(op2[1]=='v')
                {
                    int ans=0;
                    for(int i=1; i<=n; i++)
                    {
                        if(i==1) continue;
                        long long int tt = t[i]-x;
                        int p = lower_bound(t+1,t+1+n,tt)-t;
                        int q=upper_bound(t+1,t+1+n,t[i]-1)-t;
                        q--;
                        if (p>q) continue;
                        ll sum = query(p,q,1,n,1);
                        if(a[i]*(q-p+1)<sum)
                            ans++;
                    }
                    printf("%d\n",ans);
                }
            }
        }
    }
    return 0;
}