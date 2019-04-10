#include<bits/stdc++.h>
using namespace std;
double sum[10];
double a[30];
int pos[30];
int n,k,m;
double ave;
double mn;
void solve()
{
    //printf("%.10f\n",ave);
    //printf("%d %d %.10f\n",n,m,ave);

    random_shuffle(a,a+n);
    memset(sum,0,sizeof(sum));
    for (int i=0;i<n;i++)
    {
        int p=rand()%m;
        pos[i]=p;
        sum[p]+=a[i];
    }
    double ans=0;
    for (int i=0;i<m;i++)
    {
        ans+=(sum[i]-ave)*(sum[i]-ave);
    }
    double esp=0.1;
    double t=10000;
    while (t>esp)
    {

        //printf("hi\n");
        int x=rand()%n;
        int y=pos[x];
        int z;
        if (t>500)
        {
            z=min_element(sum,sum+m)-sum;
        }
        else z=rand()%m;
        if (y==z) continue;
        //printf("hi\n");
        //printf("%d %d\n",y,z);
        double tmp=ans;
        tmp-=(sum[y]-ave)*(sum[y]-ave);
        tmp-=(sum[z]-ave)*(sum[z]-ave);
        tmp+=(sum[y]-a[x]-ave)*(sum[y]-a[x]-ave);
        tmp+=(sum[z]+a[x]-ave)*(sum[z]+a[x]-ave);
        if (tmp<=ans)
        {
            ans=tmp;
            sum[y]-=a[x];
            sum[z]+=a[x];
            pos[x]=z;
        }
        t*=0.99;
    }
    if (ans<mn) mn=ans;

}
int main()
{
    scanf("%d%d",&n,&k);
    m=k;
    ave=0;
    for (int i=0;i<n;i++)
    {
        scanf("%lf",&a[i]);
        ave+=a[i];
    }
    // printf("%.10f\n",ave);
    ave/=m;
    mn=1e30;
    for (int i=0;i<1000;i++) solve();
    //printf("mn=%.10f\n",mn);
    printf("%.2f\n",sqrt(mn/m));
    return 0;
}
