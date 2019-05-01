#include<bits/stdc++.h>
using namespace std;
int n;
long long a[50];
int main()
{
    a[0]=1;
    a[2]=3;
    for (int i=4;i<50;i++) a[i]=4*a[i-2]-a[i-4];
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        if (n==-1) return 0;
        printf("%d\n",a[n]);
    }
    return 0;
}
