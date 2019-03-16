#include<bits/stdc++.h>
using namespace std;
int num[1010];
int zhen[1010];
int viszhen[1010];
int pre[1010];
int x[100010];
int y[100010];
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
        if (viszhen[xx])
        {
            num[xx]+=num[yy];
            pre[yy]=xx;
        }
        else{
            num[yy]+=num[xx];
            pre[xx]=yy;
        }
    }
}
int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for (int i=0;i<=n;i++) num[i]=1,pre[i]=i;
    for (int i=0;i<k;i++)scanf("%d",&zhen[i]),viszhen[zhen[i]]=1;
    for (int i=0;i<m;i++)
    {
        scanf("%d%d",&x[i],&y[i]);
        nian(x[i],y[i]);
    }
    int sum=0;
    long long ans=0;
    int maxx=0;
    vector<long long> v;
    for (int i=0;i<k;i++)
    {

        ans+=1ll*num[getx(zhen[i])]*(num[getx(zhen[i])]-1)/2;
        sum+=num[getx(zhen[i])];
        //printf("%d %d\n",zhen[i],getx(zhen[i]));
        maxx=max(maxx,num[getx(zhen[i])]);
    }
    ans+=1ll*(n-sum+maxx)*(n-sum+maxx-1)/2-1ll*maxx*(maxx-1)/2;
    ans-=m;
    printf("%I64d\n",ans);
    return 0;
}
