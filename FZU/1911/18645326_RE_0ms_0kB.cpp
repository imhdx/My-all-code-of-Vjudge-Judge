#include<cstdio>
using namespace std;
int a[202][202];
int mod=1;
void print(int n)
{
    for (int i=1;i<=n/2;i++)for (int j=1;j<=n;j++) a[i][j]=1;
    for (int i=n/2+1;i<=n;i++) for (int j=1;j<=n;j++) a[i][j]=-1;
    for (int i=n;i>n/2;i--)
    {
        for (int j=1;j<=n-i+1;j++) a[i][j]=0;
    }
    for (int i=2;i<=n/2;i++)
    {
        for (int j=n;j>=n-i+2;j--) a[i][j]=0;
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++) printf("%d%c",a[i][j]," \n"[j==n]);
}
struct ac
{
    int a[3][3];
};
void mul(ac &a,ac &b)
{
    ac tmp;
    for (int i=0;i<3;i++) for (int j=0;j<3;j++) tmp.a[i][j]=0;

    for (int i=0;i<3;i++)for (int j=0;j<3;j++)for (int k=0;k<3;k++)
    {
        (tmp.a[i][j]+=a.a[i][k]*b.a[k][j])%=mod;
    }
    a=tmp;
}
void poww(ac &a,int b)
{
    ac tmp;
    for (int i=0;i<3;i++) for (int j=0;j<3;j++) if (i==j) tmp.a[i][j]=1;else tmp.a[i][j]=0;
    while (b)
    {
        if (b&1) mul(tmp,a);
        mul(a,a);
        b>>=1;
    }
    a=tmp;
}
int main()
{
    int tt=1;
    int T;scanf("%d",&T);
    while (T--){
        int n;
        scanf("%d%d",&n,&mod);
        printf("Case %d: ",tt++);

        ac t;
        t.a[0][0]=t.a[0][1]=t.a[1][0]=t.a[2][0]=t.a[2][1]=t.a[2][2]=1;
        t.a[0][2]=t.a[1][1]=t.a[1][2]=0;
        poww(t,n-2);

        n=t.a[2][0]+t.a[2][1]+2*t.a[2][2];
        n%=mod;
        
        if (n&1||n==0){printf("No\n");continue;}
        printf("Yes\n");
        print(t.a[2][0]+t.a[2][1]+2*t.a[2][2]);
    }


    return 0;
}
