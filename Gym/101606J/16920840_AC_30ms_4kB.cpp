#include<bits/stdc++.h>
using namespace std;
int main()
{
    double ans=0;
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        if (x==0) ans+=2;
        else
            ans+=1.0/x;

    }
    printf("%f\n",ans);
    return 0;
}
