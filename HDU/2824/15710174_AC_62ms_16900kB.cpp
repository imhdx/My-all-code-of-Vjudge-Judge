#include<bits/stdc++.h>
using namespace std;
const int MAX=3000005;
int euler[MAX];
bool check[MAX];
int prime[MAX];
void init()
{
    euler[1]=1;
    int tot=0;
    for (int i=2;i<MAX;i++)
    {
        if (!check[i])
        {
            prime[tot++]=i;
            euler[i]=i-1;
        }
        for (int j=0;j<tot;j++)
        {
            int k=i*prime[j];
            if (k>=MAX) break;
            check[k]=1;
            euler[k]=euler[i]*prime[j];
            if (i%prime[j]==0) break;
            else
            {
                euler[k]-=euler[i];
            }
        }
    }
    //for (int i=1;i<MAX;i++) euler[i]+=euler[i-1];
}
/*
void init()
{
    euler[1]=1;
    for (int i=2;i<MAX;i++)
    {
        if (!euler[i])
            for (int j=i;j<MAX;j+=i)
        {
            if (!euler[j])
                euler[j]=j;
            euler[j]=euler[j]/i*(i-1);
        }
    }
    for (int i=1;i<MAX;i++)
        euler[i]+=euler[i-1];
}
*/
int main()
{
    init();
    int n,m;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        long long ans=0;
        for (int i=n;i<=m;i++) ans+=euler[i];
        printf("%lld\n",ans);
    }
    return 0;
}
