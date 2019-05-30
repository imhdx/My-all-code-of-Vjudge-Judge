//
// Created by mhdx on 2019/5/13.
//

#include<bits/stdc++.h>
using namespace std;
int n;
int a[10004];
int main()
{
    while (scanf("%d",&n)!=EOF)
    {
        for (int i=0;i<n;i++) scanf("%d",&a[i]);
        int ans=0;
        while (1)
        {
            int t=ans;
            for (int i=0;i<n;i++)
                if (a[i]<0)
                {
                    a[(i-1+n)%n]+=a[i];
                    a[(i+1)%n]+=a[i];
                    a[i]=-a[i];
                    ans++;
                }
            if (t==ans) break;
        }
        printf("%d\n",ans);
    }
    return 0;
}