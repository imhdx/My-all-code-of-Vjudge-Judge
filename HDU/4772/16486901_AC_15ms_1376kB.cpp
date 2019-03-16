#include<bits/stdc++.h>
using namespace std;
int a[50][50];
int b[50][50];
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        if (n==0) return 0;
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++) scanf("%d",&a[i][j]);
            for (int i=0;i<n;i++)
                for (int j=0;j<n;j++) scanf("%d",&b[i][j]);
        int maxx=0;
        int ans=0;
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                int p=i;
                int q=j;
                //printf("%d ",b[p][q]);
                if (a[i][j]==b[p][q])
                            ans++;
            }
            //printf("\n");
        }
        maxx=max(maxx,ans);
        ans=0;
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                int p=i;
                int q=n-j-1;
                //printf("%d ",b[q][p]);
                if (a[i][j]==b[q][p])
                            ans++;
            }
            //printf("\n");
        }
        maxx=max(maxx,ans);
        ans=0;
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                int p=n-1-i;
                int q=n-1-j;
                //printf("%d ",b[p][q]);
                if (a[i][j]==b[p][q])
                            ans++;
            }
            //printf("\n");
        }
        maxx=max(maxx,ans);
        ans=0;
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                int p=n-1-i;
                int q=j;
                //printf("%d ",b[q][p]);
                if (a[i][j]==b[q][p])
                            ans++;
            }
            //printf("\n");
        }
        maxx=max(maxx,ans);
        
        printf("%d\n",maxx);
    }

    return 0;
}
