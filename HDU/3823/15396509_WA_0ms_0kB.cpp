#include<bits/stdc++.h>
using namespace std;
const int maxn=21000000;
bool check1[maxn];
bool check2[200];
int prim[maxn];
int cnt=0;
void init()
{
    int i;
    long long j;
    cnt=0;
    for (i=2;i<maxn;i++)
    {
        if (check1[i]==0)
        {
            prim[cnt++]=i;
            for (j=1ll*i*i;j<maxn;j=j+i)
                check1[j]=1;
        }
    }
    for (i=0;i<cnt-1;i++)
    {
        if (prim[i+1]-prim[i]<200)
        {
            check2[prim[i+1]-prim[i]]=1;
        }
    }
}
int main()
{
    init();
    int T;
    int t=1;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        printf("Case %d: ",t++);
        if (n>m) swap(n,m);
        if (check2[m-n]==0)
        {
            printf("-1\n");
            continue;
        }
        for (int i=0;i<cnt-1;i++)
        {
            if (prim[i+1]-prim[i]==m-n&&prim[i]>=n)
            {
                printf("%d\n",prim[i]-n);
                break;
            }
        }
    }
    return 0;
}
