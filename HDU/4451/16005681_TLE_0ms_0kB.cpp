#include<bits/stdc++.h>
using namespace std;
struct node
{
    int x;
}que[1005];
int main()
{
    int n,m,k;
    while (scanf("%d%d%d",&n,&m,&k)!=EOF)
    {
        if (n==0&&m==0&&k==0) return 0;
        int p;
        scanf("%d",&p);
        char str1[100];
        char str2[100];
        int p1,p2;
        int cnt1=0;
        int cnt2=0;
        int a[1005];
        memset(a,0,sizeof(a));
        int cnt=0;
        for (int i=0;i<p;i++)
        {

            scanf("%s%d%s%d",str1,&p1,str2,&p2);
            if (str1[0]=='c')
            {
                cnt1++;
                a[p2]++;
            }
            else
            {
                que[cnt++].x=p1;
            }
        }
        for (int i=0;i<cnt;i++)
        {
            cnt2+=(n-a[que[i].x]);
        }
        //printf("%d %d\n",cnt1,cnt2);
        long long ans=1ll*n*m*k-(1ll*cnt1*k+1ll*cnt2);
        printf("%lld\n",ans);
    }

    return 0;
}
