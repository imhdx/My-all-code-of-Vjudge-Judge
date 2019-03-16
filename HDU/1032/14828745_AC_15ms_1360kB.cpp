#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        printf("%d %d",n,m);
        if (n>m)
        {
            int tmp=n;
            n=m;
            m=tmp;
        }
        int anss=0;
        int i;
        for (i=n;i<=m;i++)
        {
            int cnt=1;
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
        printf(" %d\n",anss);
    }
    return 0;
}
