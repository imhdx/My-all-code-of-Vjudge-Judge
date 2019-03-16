#include<bits/stdc++.h>
using namespace std;
int n;
long long int a[23];
int main()
{
    a[1]=0;
    a[2]=1;
    a[3]=2;
    for (int i=4;i<23;i++) a[i]=1ll*(i-1)*a[i-2]+1ll*(i-1)*a[i-1];
    int i;
    while (scanf("%d",&i)!=EOF)
    {
        printf("%lld\n",a[i]);
    }
    return 0;
}
