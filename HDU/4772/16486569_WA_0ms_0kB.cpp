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
                for (int p=0;p<n;p++)
                {
                    for (int q=0;q<n;q++)
                    {
                        if (a[i][j]==b[p][q])
                            ans++;
                    }
                }
            }
        }
        maxx=max(maxx,ans);
        ans=0;
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                for (int p=0;p<n;p++)
                {
                    for (int q=n-1;q>=0;q--)
                    {
                        if (a[i][j]==b[p][q])
                            ans++;
                    }
                }
            }
        }
        maxx=max(maxx,ans);
        ans=0;
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                for (int p=n-1;p>=0;p--)
                {
                    for (int q=n-1;q>=0;q--)
                    {
                        if (a[i][j]==b[p][q])
                            ans++;
                    }
                }
            }
        }
        maxx=max(maxx,ans);
        ans=0;
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                for (int p=n-1;p>=0;p--)
                {
                    for (int q=0;q<n;q++)
                    {
                        if (a[i][j]==b[p][q])
                            ans++;
                    }
                }
            }
        }
        maxx=max(maxx,ans);
        ans=0;
        printf("%d\n",maxx);
    }

    return 0;
}
