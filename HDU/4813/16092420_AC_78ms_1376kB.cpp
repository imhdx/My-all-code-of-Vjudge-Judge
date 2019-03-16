#include<bits/stdc++.h>
using namespace std;
char str[2000];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        scanf("%s",str);
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                printf("%c",str[i*m+j]);
            }
            printf("\n");
        }
    }
    return 0;
}
