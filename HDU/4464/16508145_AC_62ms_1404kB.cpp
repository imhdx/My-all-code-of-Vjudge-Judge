#include<bits/stdc++.h>
using namespace std;
string str;
int main()
{
    int t=1;
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        long long ans=0;
        for (int i=0;i<n;i++)
        {
            cin>>str;
            long long cc=0;
            for (int j=0;str[j];j++) cc+=str[j];
            ans=max(ans,cc);
        }
        printf("Case %d: ",t++);
        printf("%lld\n",ans);
    }
    return 0;
}
