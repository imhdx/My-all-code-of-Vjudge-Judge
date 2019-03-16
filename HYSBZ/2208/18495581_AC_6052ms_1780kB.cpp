#include<bits/stdc++.h>
using namespace std;
bitset<2002> b[2002];
int main()
{
    int n;scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            int x;
            scanf("%1d",&x);
            b[i][j]=x;
        }
        b[i][i]=1;
    }
    for (int k=0;k<n;k++)
    {
        for (int i=0;i<n;i++)
        {
            if (b[i][k]) b[i]|=b[k];
        }
    }
    int ans=0;
    for (int i=0;i<n;i++) ans+=b[i].count();
    printf("%d\n",ans);
    return 0;
}
