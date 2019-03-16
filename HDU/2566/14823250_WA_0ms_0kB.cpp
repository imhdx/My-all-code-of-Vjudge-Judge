#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    int n,m;
    int i,j,k;
    while (t--)
    {
        int cnt=0;
        scanf("%d%d",&n,&m);
        for (i=0;i<=n;i++)
        {
            for (j=0;j<=n;j++)
            {
                k=n-i-j;
                if (i+j+j+5*k==m) cnt++;

            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
