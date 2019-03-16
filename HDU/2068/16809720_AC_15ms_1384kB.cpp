#include<bits/stdc++.h>
using namespace std;
long long jie[30][30];
long long a[30];
void init()
{
    jie[0][0]=1;
    jie[1][1]=jie[1][0]=1;
    for (int i=2;i<30;i++)
    {
        jie[i][0]=1;
        for (int j=1;j<=i;j++) jie[i][j]=jie[i-1][j]+jie[i-1][j-1];
    }

    a[0]=1;
    a[1]=0;
    a[2]=1;
    for (int i=3;i<30;i++) a[i]=(a[i-1]+a[i-2])*(i-1);
}
int main()
{

    init();
    int n;
    while (scanf("%d",&n)!=EOF)
    {

        if (n==0) return 0;
        long long ans=0;
        for (int i=n;i+i>=n;i--)
        {
            ans+=jie[n][i]*a[n-i];
            //printf("%lld\n",ans);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
