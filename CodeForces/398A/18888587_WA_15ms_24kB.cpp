#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int f(int x)
{
    int tmp=n/x;
    int tt=n-tmp*x;
    int ans=0;
    ans+=(tt)*(tmp+1)*(tmp+1);
    ans+=tmp*tmp*(x-tt);
    x++;
    tmp=m/x;
    tt=m-tmp*x;
    ans-=(tt)*(tmp+1)*(tmp+1);
    ans-=tmp*tmp*(x-tt);
    return ans;
}
vector<int> v1;
vector<int> v2;
signed main()
{
    while (scanf("%I64d%I64d",&n,&m)!=EOF)
    {
        if (n==0)
        {
            printf("%I64d\n",-m*m);
            for (int i=0;i<m;i++) printf("x");
            printf("\n");
            continue;
        }
        else if (m==0)
        {
            printf("%I64d\n",n*n);
            for (int i=0;i<n;i++) printf("o");
            printf("\n");
            continue;
        }
        v1.clear();
        v2.clear();
        int l=1,r=min(n,m);
        int ans=-1;
        while (l<=r)
        {
            int mid=l+r>>1;
            int midd=mid+r>>1;
            //printf("hi\n");
            //printf("%I64d %I64d %I64d %I64d\n",mid,midd,f(mid),f(midd));
            if (f(mid)<f(midd))
            {
                ans=midd;
                r=midd-1;
            }
            else{
                ans=mid;
                l=mid+1;
            }
        }
        printf("%I64d\n",f(ans));

        int x=ans;
        int tmp=n/x;
        int tt=n-tmp*x;
        for (int i=0;i<tt;i++)
            v1.push_back(tmp+1);
        for (int i=0;i<x-tt;i++)
            v1.push_back(tmp);

        x++;
        tmp=m/x;
        tt=m-tmp*x;
        for (int i=0;i<tt;i++)
            v2.push_back(tmp+1);
        for (int i=0;i<x-tt;i++)
            v2.push_back(tmp);

        for (int i=0;i<v1.size()||i<v2.size();i++)
        {
            if (i<v2.size()) for (int j=0;j<v2[i];j++)
                printf("x");
            if (i<v1.size()) for (int j=0;j<v1[i];j++)
                printf("o");

        }
        printf("\n");
/*
        for (int i=1;i<=min(n,m);i++)
        {
            v2.clear();
            v1.clear();
            int x=i;
            int tmp=n/x;
            int tt=n-tmp*x;
            for (int i=0;i<tt;i++)
                v1.push_back(tmp+1);
            for (int i=0;i<x-tt;i++)
                v1.push_back(tmp);

            x++;
            tmp=m/x;
            tt=m-tmp*x;
            for (int i=0;i<tt;i++)
                v2.push_back(tmp+1);
            for (int i=0;i<x-tt;i++)
                v2.push_back(tmp);

            for (int i=0;i<v1.size()||i<v2.size();i++)
            {
                if (i<v2.size()) for (int j=0;j<v2[i];j++)
                    printf("x");
                if (i<v1.size()) for (int j=0;j<v1[i];j++)
                    printf("o");

            }
            printf("\n");
        }
*/

    }
    return 0;
}
