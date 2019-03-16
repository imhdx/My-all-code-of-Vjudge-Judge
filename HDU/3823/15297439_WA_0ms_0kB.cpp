#include<bits/stdc++.h>
using namespace std;
int prim[20000010];
bool check[20000010];
bool check1[201];
int cnt=0;
void init()
{
    cnt=0;
    int i;
    long long j;
    int maxx=0;
    for (i=2;i<20000001;i++)
    {
        if (check[i]==0)
        {
            prim[cnt++]=i;
            for (j=1ll*i*i;j<20000001;j+=i)
                check[j]=1;
        }
    }
    for (i=1;i<cnt;i++)
    {
        check1[prim[i]-prim[i-1]]=1;
    }
}
int main()
{
    int t=1;
    init();
    /*
    for (int i=0;i<cnt;i++)
        printf("%d ",prim[i]);
    printf("\n");
    */
    //printf("%d\n",cnt);
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        int i;
        scanf("%d%d",&n,&m);
        printf("Case %d: ",t++);
        if (check1[m-n]==0)
            printf("-1\n");
        else
        {
            for (i=0;i<cnt;i++)
            {
                if (prim[i+1]-prim[i]==m-n&&prim[i]>=n)
                {
                    printf("%d\n",prim[i]-n);
                    break;
                }
            }
        }

    }
    return 0;
}
