#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=1003;
const int mod=9999991;
int c[maxn][maxn];
int dp1[maxn][maxn];///行
int dp2[maxn][maxn];///列
int sum1[maxn];///表示行方向上走了i步后的种数
int sum2[maxn];///表示列方向上走了i步后的种数
void init()
{
    c[0][0]=1;
    for (int i=1;i<maxn;i++){
        c[i][0]=c[i][i]=1;
        for (int j=1;j<i;j++) (c[i][j]+=c[i-1][j]+c[i-1][j-1])%=mod;
    }
}
int dx[]={1,-1,2,-2};
int main()
{
    int tt=1;
    init();
    int T;scanf("%d",&T);
    while (T--){
        int n,m,k,x,y;scanf("%d%d%d%d%d",&n,&m,&k,&x,&y);///利用两个维度的不相关性，转成两个一维
        memset(dp1,0,sizeof(dp1));
        memset(dp2,0,sizeof(dp2));
        dp1[x][0]=1;
        for (int i=1;i<=k;i++)
        {
            for (int j=1;j<=n;j++)
            {
                for (int p=0;p<4;p++){
                    int xx=j+dx[p];
                    if (xx>=1&&xx<=n) (dp1[j][i]+=dp1[xx][i-1])%=mod;
                }
            }
        }
        dp2[y][0]=1;
        for (int i=1;i<=k;i++)
        {
            for (int j=1;j<=n;j++)
            {
                for (int p=0;p<4;p++){
                    int xx=j+dx[p];
                    if (xx>=1&&xx<=m) (dp2[j][i]+=dp2[xx][i-1])%=mod;
                }
            }
        }
        memset(sum1,0,sizeof(sum1));
        memset(sum2,0,sizeof(sum2));
        for (int i=0;i<=k;i++){
            for (int j=1;j<=n;j++)
                (sum1[i]+=dp1[j][i])%=mod;
        }
        for (int i=0;i<=k;i++){
            for (int j=1;j<=m;j++)
                (sum2[i]+=dp2[j][i])%=mod;
        }
        int ans=0;
        for (int i=0;i<=k;i++)
        {
            ans+=1ll*c[k][i]*sum1[i]%mod*sum2[k-i]%mod;
            ans%=mod;
        }
        printf("Case #%d:\n",tt++);
        printf("%d\n",ans);
    }
    return 0;
}
