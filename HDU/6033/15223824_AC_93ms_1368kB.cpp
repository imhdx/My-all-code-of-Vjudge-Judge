#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int t=1;
    while (scanf("%d",&n)!=EOF)
    {
        int ans=n*log10(2);
        printf("Case #%d: ",t++);
        printf("%d\n",ans);
    }
    return 0;
}
