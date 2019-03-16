#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int f[25][505],g[25][505],mi[25];
void init()
{
    mi[0]=1;
    for (int i=1;i<25;i++) mi[i]=mi[i-1]*10%mod;
    f[0][200]=1;
    for (int i=0;i<=9;i++){
        f[1][i+200]=1;
        g[1][i+200]=i;
    }
    for (int i=2;i<=19;i++){
        for (int j=-100;j<=100;j++){
            for (int k=0;k<=9;k++){
                (f[i][j+200]+=f[i-1][k-j+200])%=mod;///注意是k-j 因为f[i][j] 表示长度为i为 交错和为j 且第一位取正
                                                    ///所以此位要想取正，那么i-1位取负
                                                    ///所以j=k+(-1)x
                                                    ///x=k-j;
                (g[i][j+200]+=g[i-1][k-j+200])%=mod;
                (g[i][j+200]+=mi[i-1]*k%mod*f[i-1][k-j+200])%=mod;
            }
        }
    }
}
int cal(int n,int k)
{
    int a[25],tot=0;
    if (n<=1) return 0;
    while (n){
        a[++tot]=n%10;
        n/=10;
    }
    /// tot~1
    int ans=0;
    for (int i=tot-1;i>=1;i--){///算的是前面全是0的情况
        for (int j=1;j<=9;j++){
            (ans+=g[i-1][j-k+200])%=mod;
            (ans+=mi[i-1]*j%mod*f[i-1][j-k+200]%mod)%=mod;
        }
    }
    int now=0;
    int op=1,s=0;
    for (int i=tot;i>=1;i--){
        int j;
        if (i==tot) j=1;
        else j=0;
        for (;j<a[i];j++){
            if (op==1){///此位取正
                (ans+=g[i-1][s+op*j-k+200])%=mod;
                (ans+=(mi[i-1]*j%mod+now)*f[i-1][s+op*j-k+200]%mod)%=mod;
            }
            else{///此位取负
                (ans+=g[i-1][k-(s+op*j)+200])%=mod;
                (ans+=(mi[i-1]*j%mod+now)*f[i-1][k-(s+op*j)+200]%mod)%=mod;
            }
        }
        (now+=mi[i-1]*a[i]%mod)%=mod;
        s+=op*a[i];
        op*=-1;
    }
    return ans;
}
signed main()
{
    init();
    int n,m,k;
    scanf("%lld%lld%lld",&n,&m,&k);
    int ans=cal(m+1,k)-cal(n,k);
    ans%=mod;
    ans+=mod;
    ans%=mod;
    printf("%lld\n",ans);
    return 0;
}
