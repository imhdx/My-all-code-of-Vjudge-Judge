#include<bits/stdc++.h>
using namespace std;
long long a[40];
int main()
{
    a[0]=1;
    a[1]=1;
    a[2]=2;
    for (int i=3;i<40;i++)
    {
        for (int j=0;j<i;j++) a[i]+=a[j]*a[i-j-1];
    }
    int n;
    int cnt=1;
    while (scanf("%d",&n)!=EOF&&n!=-1)
    {
        printf("%d %d %lld\n",cnt++,n,a[n]*2ll);
    }
    return 0;
}
