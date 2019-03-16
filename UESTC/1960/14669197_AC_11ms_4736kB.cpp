#include<bits/stdc++.h>
using namespace std;
int a[1010][1010];
int nt[1010];
int main()
{
    memset(nt,-1,sizeof(nt));
    int n;
    scanf("%d",&n);
    int i,j;
    getchar();
    for (i=0;i<n;i++)
    {
        char str[1010];
        scanf("%s",str);
        for (j=0;str[j];j++)
        {
            if (i<j)
            {
                if (str[j]=='-')
                    a[j][i]=1;
                else if (str[j]=='+')
                    a[i][j]=1;
            }
        }
    }
    int tou,wei;
    tou=1;
    wei=0;
    if (a[1][0]!=1) swap(tou,wei);
    nt[tou]=wei;
    for (i=2;i<n;i++)
    {
        if (a[i][tou])
        {
            nt[i]=tou;
            tou=i;
        }
        else if (a[wei][i])
        {
            nt[wei]=i;
            wei=i;
        }
        else
        {
            int j=tou;
            while (nt[j]!=-1)
            {
                if (a[j][i]&&a[i][nt[j]])
                {
                    nt[i]=nt[j];
                    nt[j]=i;
                    break;
                }
                j=nt[j];
            }
        }
    }
    i=tou;
    printf("YES\n");
    printf("%d",tou);
    for (i=nt[tou];i!=-1;i=nt[i])
        printf(" %d",i);
    printf("\n");
    return 0;
}
