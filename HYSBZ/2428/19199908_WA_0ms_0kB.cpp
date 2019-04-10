#include<bits/stdc++.h>
using namespace std;
double sum[10];
double a[30];
int pos[30];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    int m=k;
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    random_shuffle(a,a+n);
    double ave=0;
    for (int i=0;i<n;i++)
    {
        ave+=a[i];
        int p=rand()%m;
        sum[p]+=a[i];
        pos[i]=p;
    }
    ave/=m;
    double ans=0;
    for (int i=0;i<m;i++)
    {
        ans+=(sum[i]-ave)*(sum[i]-ave);
    }
    //printf("%.10f\n",ans);
    double esp=1e-4;
    double t=10000;
    while (t>esp)
    {
        int x=rand()%n;
        int y=pos[x];
        int z;
        if (t>500)
        {
            z=min_element(sum,sum+m)-sum;
        }
        else z=rand()%m;
        if (y==z) continue;
        //printf("%d %d\n",y,z);
        double tmp=ans;
        tmp-=(sum[y]-ave)*(sum[y]-ave);
        tmp-=(sum[z]-ave)*(sum[z]-ave);
        tmp+=(sum[y]-a[x]-ave)*(sum[y]-a[x]-ave);
        tmp+=(sum[z]+a[x]-ave)*(sum[z]+a[x]-ave);
        if (tmp<ans)
        {
            ans=tmp;
            sum[y]-=a[x];
            sum[z]+=a[x];
            pos[x]=z;
        }
        t*=0.99;
    }
    printf("%.2f\n",sqrt(ans/m));
    return 0;
}
