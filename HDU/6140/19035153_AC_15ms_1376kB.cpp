#include<bits/stdc++.h>
using namespace std;
int a[1003];
char b[1003][3];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for (int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for (int i=0;i<n;i++)
        {
            scanf("%s",b[i]);
        }
        long long maxx=0;
        for (int i=0;i<n;i++)
        {
            if (b[i][0]=='N') maxx+=a[i];
            if (b[i][0]=='L') maxx+=a[i];
        }
        long long minn=0;
        for (int i=0;i<n;i++)
        {
            if (b[i][0]=='N') minn-=a[i];
            if (b[i][0]=='D') minn-=a[i];
        }
        if (m>=minn&&m<=maxx) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
