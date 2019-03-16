#include<bits/stdc++.h>
using namespace std;
long long int a[20];
long long int b[20];
int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        if (n==0&&m==0) break;
        int i,j;
        long long int s=0;
        for (i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
            s+=a[i];
        }
        for (i=0;i<m;i++)
        {
            scanf("%lld",&b[i]);
            for (j=0;j<n;j++)
            {
                if (b[i]==a[j])
                {
                    a[j]=-100;
                    break;
                }
            }
            if (j<n) continue;
            s+=b[i];
        }
        printf("%lld\n",s);
    }
    return 0;
}
