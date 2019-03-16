#include<bits/stdc++.h>
using namespace std;
int a[50][50];
double a1[50];
double a2[50];
int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        for (int i=0;i<n;i++)
        {
            double k=0;
            for (int j=0;j<m;j++)
            {
                k+=a[i][j];
            }
            k=k/m;
            a1[i]=k;
        }
        for (int j=0;j<m;j++)
        {
            double k=0;
            for (int i=0;i<n;i++)
            {
                k+=a[i][j];
            }
            k=k/n;
            a2[j]=k;
        }
        for (int i=0;i<n;i++)
        {
            printf("%.2f%c",a1[i]," \n"[i==n-1]);
        }
        for (int j=0;j<m;j++)
        {
            printf("%.2f%c",a2[j]," \n"[j==m-1]);
        }
        int ans=0;
        for (int i=0;i<n;i++)
        {
            int j=0;
            for (j=0;j<m;j++)
            {
                if (a[i][j]<a2[j])
                    break;
            }
            if (j==m) ans++;
        }
        printf("%d\n",ans);

    }
    return 0;
}
