#include<bits/stdc++.h>
using namespace std;
#define int long long
set<int> s;
const int INF=4ll*INT_MAX;
signed main()
{
    s.clear();
    int n;
    scanf("%lld",&n);
    long long ans=0;
    for (int i=0;i<n;i++){
        int x;scanf("%lld",&x);
        if (i==0){
            ans+=x;
            s.insert(x);
        }
        else{
            auto pos=s.lower_bound(x);
            long long minn=INF;
            if (pos!=s.end()){
                minn=min(minn,abs(*pos-x));
            }
            if (pos!=s.begin()){
                --pos;
                minn=min(minn,abs(*pos-x));
            }
            ans+=minn;
            s.insert(x);
        }
    }
    printf("%lld\n",ans);
    return 0;
}
