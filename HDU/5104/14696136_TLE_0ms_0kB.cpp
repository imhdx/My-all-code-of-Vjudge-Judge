#include<stdio.h>
#include<math.h>
bool pri(int n)
{
    if (n<2) return false;
    for (int i=2;i<=(int)sqrt(n);i++)
    {
        if (n%i==0) return false;
    }
    return true;
}
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        int i,j,k;
        int ans=0;
        for (i=2;i<=n/3+1;i++)
        {
            for (j=i;j<=(n-i)/2+1;j++)
            {
                k=n-i-j;
                if (k<j) continue;
                if (pri(i)&&pri(j)&&pri(k))
                    ans++;
            }
        }
        printf("%d\n",ans);
    }

    return 0;
}
