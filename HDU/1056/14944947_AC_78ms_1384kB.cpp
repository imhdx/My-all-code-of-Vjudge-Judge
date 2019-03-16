#include<bits/stdc++.h>
using namespace std;
int main()
{
    double n;
    while (scanf("%lf",&n)!=EOF&&n)
    {
        double ans=0;
        int i=0;
        for (i=2;ans<n;i++)
            ans+=1.0/i;
        printf("%d card(s)\n",i-2);
    }
    return 0;
}
