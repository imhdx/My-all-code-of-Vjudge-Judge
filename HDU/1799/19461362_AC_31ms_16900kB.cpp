#include<bits/stdc++.h>
using namespace std;
int c[2002][2002];
void init()
{
    c[0][0]=1;
    for (int i=1;i<2002;i++)
    {
        c[i][0]=c[i][i]=1;
        for (int j=1;j<i;j++) c[i][j]=(c[i-1][j]+c[i-1][j-1])%1007;
    }

}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        printf("%d\n",c[m][n]);
    }
    return 0;
}
