#include<bits/stdc++.h>
using namespace std;
int f(int x)
{
    int ans=0;
    ans+=x/100;
    x=x%100;
    ans+=x/50;
    x=x%50;
    ans+=x/10;
    x=x%10;
    ans+=x/5;
    x=x%5;
    ans+=x/2;
    x=x%2;
    ans+=x;
    return ans;
}
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        if (n==0) return 0;
        int ans=0;
        int x;
        for (int i=0;i<n;i++)
            scanf("%d",&x),ans+=f(x);
        printf("%d\n",ans);
    }

    return 0;
}
