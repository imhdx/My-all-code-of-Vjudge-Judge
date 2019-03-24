#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int f(int x)
{
    int ans=0;
    ans+=x-1;
    ans+=(n-x+1)*(n-x+1);
    x++;
    int tmp=m/x;
    int tt=m-tmp*x;
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
        int l=1,r=min(n,m-1);
        int maxx=f(1);
        int ans=1;
        for (int i=1;i<=r;i++)
        {
            //printf("%I64d %I64d\n",i,f(i));
            if (maxx<f(i))
            {
                maxx=f(i);
                ans=i;
            }
        }
        printf("%I64d\n",f(ans));
        int x=ans;
        for (int i=0;i<ans-1;i++)
            v1.push_back(1);
        v1.push_back(n-ans+1);

        x++;
        int tmp=m/x;
        int tt=m-tmp*x;
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
    return 0;
}
