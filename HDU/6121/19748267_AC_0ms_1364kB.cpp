//
// Created by mhdx on 2019/5/14.
//

#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[100];///  每一层往下的总个数
long long b[100];///   满的第i层的个数
#define y1 d12345s6f
long long x1,y1,x2,y2,z1,z2;
long long f(long long x,long long y) /// x个y
{
    if (x&1) return y;
    return 0;
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%lld%lld",&n,&k);
        if (k==1)
        {
            if (n%4==0)
            {
                printf("%lld\n",n);
            }
            else if (n%4==1)
            {
                printf("1\n");
            }
            else if (n%4==2)
            {
                printf("%lld\n",n+1);
            }
            else printf("0\n");
            continue;
        }
        memset(b,0,sizeof(b));
        memset(a,0,sizeof(a));
        int cnt=0;
        long long tmp=1;
        long long m=n;
        while (1)
        {
            if (tmp<=m){
                m-=tmp;
                a[++cnt]=tmp;
                if (m/tmp<=k) break;
                tmp*=k;
            }
            else break;
        }
        if (m!=0)
        {
            a[++cnt]=m;
        }
        //for (int i=1;i<=cnt;i++) printf("%lld\n",a[i]);
        for (int i=cnt;i>=1;i--) a[i]=a[i]+a[i+1];
        b[1]=1;
        for (int i=2;i<=cnt;i++) b[i]=b[i-1]*k;
        //for (int i=1;i<=cnt;i++) printf("%lld %lld\n",a[i],b[i]);

        long long ans=0;
        long long x1,x2,z1,z2,y1,y2;
        x1=a[cnt];
        x2=1;
        z1=b[cnt]-a[cnt];
        z2=0;
        y1=0;
        y2=0;
        if (cnt>=1) /// cnt
        {
            ans^=(f(x1,x2));
        }
        if (cnt>=2)  ///  cnt-1
        {
            long long tx1=x1;
            long long tx2=x2;
            long long ty1=y1;
            long long ty2=y2;
            long long tz2=z2;
            x1=tx1/k;
            x2=tx2*k+1;
            if (tx1%k==0)
            {
                y1=y2=0;
                z1=b[cnt-1]-x1-y1;
                z2=1;
            }
            else{
                y1=1;
                y2=1+(tx1%k);
                z1=b[cnt-1]-x1-y1;
                z2=1;
            }
            ans^=(f(x1,x2)^f(y1,y2)^f(z1,z2));
        }
        for (int i=cnt-2;i>=1;i--)
        {
            long long tx1=x1;
            long long tx2=x2;
            long long ty1=y1;
            long long ty2=y2;
            long long tz1=z1;
            long long tz2=z2;
            x1=tx1/k;
            x2=tx2*k+1;
            z1=tz1/k;
            z2=tz2*k+1;
            y1=b[i]-x1-z1;
            y2=a[i]-x1*x2-z1*z2;
            //printf("%lld %lld %lld %lld %lld %lld\n",x1,x2,y1,y2,z1,z2);
            ans^=(f(x1,x2)^f(y1,y2)^f(z1,z2));
        }
        printf("%lld\n",ans);

    }
    return 0;
}///