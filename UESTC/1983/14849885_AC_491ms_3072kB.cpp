#include<bits/stdc++.h>
using namespace std;
char str[100005];
unsigned long long a[100005];
unsigned long long poww(unsigned long long a,unsigned long long b)
{
    unsigned long long res=1;
    while (b>0)
    {
        if (b&1)
            res*=a;
        a*=a;
        b>>=1;
    }
    return res;
}
int main()
{
    scanf("%s",str+1);
    int n;
    int i;
    a[0]=0;
    for (i=1;i<=strlen(str+1); i++)
    {
        a[i]=a[i-1]*163+str[i]-'a';
    }
    cin>>n;
    for (i=0; i<n; i++)
    {
        int x,y;
        cin>>x>>y;
        unsigned long long ans=a[y]-a[x-1]*poww(163,y-x+1);
        printf("%llu\n",ans);
    }

    return 0;
}
