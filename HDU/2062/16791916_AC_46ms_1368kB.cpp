#include<bits/stdc++.h>
using namespace std;
int a[30];
long long int f[31];
void init()
{
    f[1]=1;
    int i;
    for (i=2;i<30;i++)
        f[i]=1ll*(i-1)*f[i-1]+1;
}
int main()
{
    init();
    int n;
    long long m;
    while(scanf("%d%lld",&n,&m)!=EOF)
    {
        int i;
        for (i=1;i<=n;i++) a[i]=i;
        while (n>0&&m>0)
        {
            int aa=m/f[n];
            if (m%f[n]!=0) aa++;
            m=m-(aa-1)*f[n];
            m--;
            printf("%d%c",a[aa]," \n"[m==0]);
            for (int i=aa;i<n;i++)
            {
                a[i]=a[i+1];
            }
            n--;
        }
    }
    return 0;
}