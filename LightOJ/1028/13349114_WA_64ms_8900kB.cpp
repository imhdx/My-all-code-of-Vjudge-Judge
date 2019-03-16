#include<cstdio>
#include<cstring>
using namespace std;
int shai[1000100];
int pri[1000100];
int t=0;
void sett()
{
    int i,j;
    memset(shai,0,1000100*sizeof(int));
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
    int k,kk;
    int i,j;
    scanf("%d",&k);
    for (kk=1;kk<=k;kk++)
    {
        int n;
        int ans=1;
        scanf("%d",&n);
        int m=n;
        for (i=0;i<t&&pri[i]*pri[i]<=n;i++)
        {
            int cnt=1;
            if (pri[i]>n) break;
            while (n%pri[i]==0)
            {
                cnt++;
                n=n/pri[i];
            }
            ans=ans*cnt;
        }

        printf("Case %d：",kk);
        if (n>1) ans=ans*2;
        ans--;
        printf("%d\n",ans);
    }
    return 0;
}
