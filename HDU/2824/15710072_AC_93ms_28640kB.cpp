#include<bits/stdc++.h>
using namespace std;
const int MAX=3000005;
long long int euler[MAX];
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
            if (i*prime[j]>=MAX) break;
            check[i*prime[j]]=1;
            if (i%prime[j]==0)
            {
                euler[i*prime[j]]=euler[i]*prime[j];
                break;
            }
            else
            {
                euler[i*prime[j]]=euler[i]*(prime[j]-1);
            }
        }
    }
    for (int i=1;i<MAX;i++) euler[i]+=euler[i-1];
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
        printf("%lld\n",euler[m]-euler[n-1]);
    }
    return 0;
}
