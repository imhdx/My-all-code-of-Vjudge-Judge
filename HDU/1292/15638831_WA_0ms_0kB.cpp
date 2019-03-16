#include<bits/stdc++.h>
using namespace std;
///C(n)=C(n-1)*((4*n-2)/(n+1))
long long c[30];
void init()
{
    int i;
    c[0]=1;
    c[1]=1;
    c[2]=2;
    for (i=3;i<30;i++)
        c[i]=c[i-1]*(4*i-2)/(i+1);
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        printf("%lld\n",c[n]);
    }
    return 0;
}
