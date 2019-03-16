#include<bits/stdc++.h>
using namespace std;
int pri[10000007];
long long phi[10000007];
bool check[10000007];
int tot;
void init()
{
    phi[1]=1;
    tot=0;
    for (int i=2;i<10000007;i++)
    {
        if (!check[i]){
            pri[tot++]=i;
            phi[i]=i-1;
        }
        for (int j=0;j<tot;j++){
            if (i*pri[j]>=10000007) break;
            check[i*pri[j]]=1;
            if (i%pri[j]==0){
                phi[i*pri[j]]=phi[i]*pri[j];
                break;
            }
            else phi[i*pri[j]]=phi[i]*(pri[j]-1);
        }
    }
}
int main()
{
    init();
    for (int i=1;i<10000007;i++) phi[i]+=phi[i-1];
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        
        long long ans=0;
        for (int i=0;i<tot&&pri[i]<=n;i++)
        {
            ans+=2ll*phi[n/pri[i]]-1;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
