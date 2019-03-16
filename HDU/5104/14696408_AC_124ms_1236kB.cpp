#include<stdio.h>
#include<math.h>
int prim[10010];
int main()
{
    int i;
    prim[1]=1;
    for (i=2;i<10010;i++)
    {
        if (prim[i]==0)
        {
            for (long long j=2;i*j<10010;j++)
                prim[i*j]=1;
        }
    }
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        int i,j,k;
        int ans=0;
        for (i=2;i<=n/3+1;i++)
        {
            if (prim[i]!=0) continue;
            for (j=i;j<=(n-i)/2+1;j++)
            {
                if (prim[j]!=0) continue;
                k=n-i-j;
                if (k<j) break;
                if (prim[k]==0)
                    ans++;
            }
        }
        printf("%d\n",ans);
    }

    return 0;
}
