#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int tt=1;
    while (scanf("%d",&n)!=EOF)
    {
        int ans=n*log10(2);
        printf("Case #%d: %d\n",tt++,ans);
    }

    return 0;
}