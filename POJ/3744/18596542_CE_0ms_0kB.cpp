#include<cstdio>
#include<algorithm>
using namespace std;
struct M
{
    double a[2][2];
};
void mul(M &a,M b)
{
    double tmp[2][2];
    memset(tmp,0,sizeof tmp);
    for (int i=0;i<2;i++){
        for (int j=0;j<2;j++){
            for (int k=0;k<2;k++)
                tmp[i][j]+=a.a[i][k]*b.a[k][j];
        }
    }
    for (int i=0;i<2;i++) for (int j=0;j<2;j++) a.a[i][j]=tmp[i][j];
}
void poww(M &a,int b)
{
    M tmp;
    tmp.a[0][0]=1;
    tmp.a[1][1]=1;
    tmp.a[1][0]=tmp.a[0][1]=0;
    while (b){
        if (b&1) mul(tmp,a);
        mul(a,a);
        b>>=1;
    }
    for (int i=0;i<2;i++) for (int j=0;j<2;j++) a.a[i][j]=tmp.a[i][j];
}
int a[20];
int main()
{
    int n;
    double p;
    while (scanf("%d%lf",&n,&p)!=EOF){
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+1+n);
        double ans=1;
        double tmp=1;
        for (int i=1;i<=n;i++){
            M k;
            k.a[0][0]=p;
            k.a[0][1]=1-p;
            k.a[1][0]=1;
            k.a[1][1]=0;
            poww(k,a[i]-a[i-1]-1);
            ans*=(1-k.a[0][0]);
        }
        printf("%.7f\n",ans);
    }
    return 0;
}
