#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
    int T;scanf("%d",&T);
    while (T--){
        long long n,m,v,k;
        scanf("%lld%lld%lld%lld",&n,&m,&v,&k);
        if (m>=n){printf("0\n");continue;}
        if ((m-v)*k<=m){printf("-1\n");continue;}
        int cnt=-1;
        while (m<n){
            cnt++;
            m=(m-v)*k;
        }
        if (cnt==-1) {printf("-1\n");continue;}
        else {printf("%d\n",cnt+1);continue;}
    }
    return 0;
}
