#include<bits/stdc++.h>
using namespace std;
#define int long long
int que[1001];
char str1[10];
char str2[10];
int n,m,k;
int p;
int a[1001];
int p1,p2;
int cnt1;
int cnt2;
int cnt;
signed main()
{
    while (scanf("%lld%lld%lld",&n,&m,&k)!=EOF)
    {
        if (n==0&&m==0&&k==0) return 0;
        for (int i=1;i<=m;i++) a[i]=0;
        scanf("%lld",&p);
        cnt=cnt1=cnt2=0;
        for (int i=0;i<p;i++)
        {
            scanf("%s%lld%s%lld",str1,&p1,str2,&p2);
            if (str1[0]=='c')
            {
                cnt1++;
                a[p2]++;
            }
            else
            {
                que[cnt++]=p1;
            }
        }
        for (int i=0;i<cnt;i++)
        {
            cnt2+=(n-a[que[i]]);
        }
        int ans=n*m*k-(cnt1*k+cnt2);
        printf("%lld\n",ans);
    }
    return 0;
}
