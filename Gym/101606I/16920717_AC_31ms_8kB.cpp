#include<bits/stdc++.h>
using namespace std;
int a[20];
int main()
{
    int n;
    int t;
    int min=1e9+7;
    int mx=0;
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    scanf("%d",&t);
    for (int i=0;i<n;i++)
    {
        if (t%a[i]<t%a[mx]) mx=i;
    }
    printf("%d\n",a[mx]);
    return 0;
}
