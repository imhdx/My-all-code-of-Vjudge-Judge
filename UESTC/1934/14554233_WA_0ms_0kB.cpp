#include <bits/stdc++.h>
using namespace std;
long long int a[1000005];
long long int b[1000005];
void Build(int l,int r,int rt)
{
    a[rt]=0;
    if(l==r)
    {
        scanf("%lld",&a[rt]);
        b[rt]=0;
        return;
    }
    int mid = (l+r)>>1;
    Build(l,mid,rt<<1);
    Build(mid+1,r,(rt<<1)+1);
    a[rt]=a[rt*2]+a[rt*2+1];
}
void Down(int l,int r,int rt)
{
    if(b[rt])
    {
        b[2*rt]+=b[rt];
        b[2*rt+1]+=b[rt];
        a[2*rt]+=b[rt];
        a[2*rt+1]+=b[rt];
        b[rt]=0;
        return;
    }
}
void Change(int l,int r,int rt,int x,int y,int v)
{
    if(x<=l&&y>=r)
    {
        b[rt]+=v;
        return;
    }
    int mid = (l+r)>>1;
    Down (l,r,rt);
    if(x<=mid)
        Change(l,mid,rt*2,x,y,v);
    if(y>mid)
        Change(mid+1,r,rt*2+1,x,y,v);
}
long long int Query(int l,int r,int rt,int t)
{
    if(l==r&&l==t)
    {
        return a[rt];
    }
    Down(l,r,rt);
    int mid = (l+r)>>1;
    if(t<=mid)
        return Query(l,mid,rt*2,t);
    else
        return Query(mid+1,r,rt*2+1,t);

}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        Build(1,n,1);
        int i;
        for(i=0;i<n;i++)
        {
            int t,l,r,c;
            scanf("%d%d%d%d",&t,&l,&r,&c);
            if(t==0)
            {
                Change(1,n,1,l,r,c);
            }
            else
            {
                printf("%lld\n",Query(1,n,1,r));
            }

        }
    }



    return 0;
}
