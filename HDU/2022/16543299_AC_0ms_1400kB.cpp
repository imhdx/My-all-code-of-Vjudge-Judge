#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[100][100];
    int n,m;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++) scanf("%d",&a[i][j]);
        }
        int r=0;
        int c=0;
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                if (abs(a[i][j])>abs(a[r][c]))
                {
                    r=i;
                    c=j;
                }
            }
        }
        printf("%d %d %d\n",r+1,c+1,a[r][c]);

    }
    return 0;
}
