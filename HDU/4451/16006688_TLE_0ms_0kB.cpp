#include<bits/stdc++.h>
using namespace std;
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
int main()
{
    while (scanf("%d%d%d",&n,&m,&k)!=EOF)
    {
        if (n==0&&m==0&&k==0) return 0;
        for (int i=1;i<=m;i++) a[i]=0;
        scanf("%d",&p);
        cnt=cnt1=cnt2=0;
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
                que[cnt++]=p1;
            }
        }
        for (int i=0;i<cnt;i++)
        {
            cnt2+=(n-a[que[i]]);
        }
        int ans=n*m*k-(cnt1*k+cnt2);
        printf("%d\n",ans);
    }

    return 0;
}
