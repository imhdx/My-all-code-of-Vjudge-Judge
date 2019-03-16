#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a[40];
    a[1]=1;
    a[2]=2;
    for (int i=3;i<40;i++)
    {
        a[i]=a[i-1]*(4*i-2)/(i+1);
    }
    int n;
    int cnt=1;
    while (scanf("%d",&n)!=EOF&&n!=-1)
    {
        printf("%d %d %lld\n",cnt++,n,a[n]*2ll);
    }
    return 0;
}
