#include<bits/stdc++.h>
using namespace std;
long long a[50];///最后两个颜色相同
long long b[50];///最后两个颜色不同
int main()
{
    a[2]=3;
    b[2]=6;
    for(int i=3;i<=50;i++)
    {
        a[i]=a[i-1]+b[i-1];
        b[i]=a[i-1]*2+b[i-1];
    }
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        if (n==1) printf("3\n");
        else
        printf("%lld\n",a[n]+b[n]);
    }
    return 0;
}
