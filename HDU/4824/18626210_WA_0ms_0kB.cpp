#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
int main()
{
    int T;scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        long long ans=0;
        int now1=0,now2=0;
        for (int i=0;i<n;i++)
        {
            int x,y;scanf("%d%d",&x,&y);
            ans+=(x-now1)*400ll;
            ans+=min(360-abs(now2-y),abs(now2-y));
            ans+=10ll;
            now1=x;
            now2=y;
        }
        ans+=400ll*now1;
        ans+=min(360-abs(now2),abs(now2));
        printf("%lld\n",ans);
    }
    return 0;
}
