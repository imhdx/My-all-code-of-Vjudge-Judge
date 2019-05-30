//
// Created by mhdx on 2019/5/12.
//

#include<algorithm>
#include<cstdio>
using namespace std;
int n,m;
int a[1003],b[1003];
double s[1003];
bool check(double mid)
{
    for (int i=0;i<n;i++) s[i]=a[i]-mid*b[i];
    sort(s,s+n);
    double ans=0;
    for (int i=n-1,j=0;i>=0&&j<n-m;i--,j++)
    {
        ans+=s[i];
    }
    return ans>=0;
}
int main()
{
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        if (n==0&&m==0) return 0;
        for (int i=0;i<n;i++) scanf("%d",&a[i]);
        for (int i=0;i<n;i++) scanf("%d",&b[i]);
        double l=0,r=1e11;
        double ans=-1;
        while (l<=r)
        {
            double mid=(l+r)/2;
            if (check(mid))
            {
                ans=mid;
                l=mid+1e-7;
            }
            else r=mid-1e-7;
        }
        printf("%.0f\n",ans*100);
    }
    return 0;
}