#include<bits/stdc++.h>
using namespace std;
const int MAXN=5010;

int a[MAXN];
int b[MAXN];
int gcd[MAXN];
map<int,bool>mmp;
int _gcd(int a,int b)
{
    if (b==0) return a;
    return _gcd(b,a%b);
}
int cal(int x)
{
    int sum=0;
    int i;
    for (i=2;i*i<=x;i++)
    {
        while (x%i==0)
        {
            if (mmp[i])
                sum--;
            else
                sum++;
            x=x/i;
        }
    }
    if (x!=1)
    {
        if (mmp[x])
                sum--;
            else
                sum++;
    }
    return sum;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int i,j;
    for (i=0;i<n;i++) scanf("%d",&a[i]);
    for (i=0;i<m;i++)
    {
        int x;
        scanf("%d",&x);
        mmp[x]=true;
    }
    gcd[0]=a[0];
    for (i=1;i<n;i++) gcd[i]=_gcd(a[i],gcd[i-1]);
    for (i=n-1;i>=0;i--)
    {
        int p=gcd[i];
        if (cal(gcd[i])<0)
        {
            for (j=i;j>=0;j--)
            {
                gcd[j]/=p;
                a[j]/=p;
            }
        }
    }
    int ans=0;
    for (i=0;i<n;i++)
    {
        ans+=cal(a[i]);
    }
    printf("%d\n",ans);
    return 0;
}
