#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        int anss=0;
        int i;
        for (i=n;i<=m;i++)
        {
            int cnt=0;
            int j=i;
            while (j!=1)
            {
                cnt++;
                if (j%2==0)
                    j=j/2;
                else
                    j=3*j+1;
            }
            anss=max(anss,cnt);
        }
        printf("%d %d %d\n",n,m,anss+1);
    }
    return 0;
}
