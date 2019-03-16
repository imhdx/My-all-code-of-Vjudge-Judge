#include<cstdio>
#include<cstring>
using namespace std;
long long int shai[1000100];
long long int pri[1000100];
long long int t=0;
void sett()
{
    long long int i,j;
    memset(shai,0,1000100*sizeof(long long int));
    for (i=2;i<1000100;i++)
    {
        if (!shai[i])
        {
            pri[t++]=i;
            for (j=i*2;j<1000100;j=j+i)
                shai[j]=1;
        }
    }
    return ;
}
int main()
{
    sett();
    long long int k,kk;
    long long int i,j;
    scanf("%lld",&k);
    for (kk=1;kk<=k;kk++)
    {
        long long int n;
        long long int ans=1;
        scanf("%lld",&n);
        long long int m=n;
        for (i=0;i<t&&pri[i]*pri[i]<=n;i++)
        {
            long long int cnt=1;
            if (pri[i]>n) break;
            while (n%pri[i]==0)
            {
                cnt++;
                n=n/pri[i];
            }
            ans=ans*cnt;
        }

        printf("Case %lld: ",kk);
        if (n>1) ans=ans*2;
        ans--;
        printf("%lld\n",ans);
    }
    return 0;
}
