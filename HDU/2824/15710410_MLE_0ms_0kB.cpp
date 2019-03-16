#include<bits/stdc++.h>
using namespace std;
const int MAX=3000001;
int euler[MAX];
long long ans[MAX];
int prime[MAX];
void init()
{
    euler[1]=1;
    ans[1]=1;
    int tot=0;
    for (int i=2;i<MAX;++i)
    {
        if (!euler[i])
        {
            prime[tot++]=i;
            euler[i]=i-1;
        }
        for (int j=0;j<tot;++j)
        {
            int k=i*prime[j];
            if (k>=MAX) break;
            euler[k]=euler[i]*prime[j];
            if (i%prime[j]==0) break;
            else euler[k]-=euler[i];
        }
        ans[i]+=ans[i-1]+euler[i];
    }
}
int main()
{
    init();
    int n,m;
    while (scanf("%d%d",&n,&m)!=EOF)
        printf("%lld\n",ans[m]-ans[n-1]);
}
