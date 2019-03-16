#include<bits/stdc++.h>
using namespace std;
const int MAX=3000001;
long long euler[MAX];
int prime[MAX];
void init()
{
    euler[1]=1;
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
        euler[i]+=euler[i-1];
    }
}
int main()
{
    init();
    int n,m;
    while (scanf("%d%d",&n,&m)!=EOF)
        printf("%lld\n",euler[m]-euler[n-1]);
}
