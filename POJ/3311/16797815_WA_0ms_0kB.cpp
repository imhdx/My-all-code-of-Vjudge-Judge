#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

typedef long long ll;


int dp[1<<20][20];
int a[1010][1010];

void tsp(int n){
    for(int i=0;i<=(1<<n)-1;i++){
        fill(dp[i],dp[i]+n,0x3f3f3f3f);
    }
    for (int i=0;i<n;i++)
    {
        dp[1<<i][i]=a[i][0];
    }
    //for (int i=1;i<n;i++) dp[1<<i][i]=a[i][0];
    for(int S=0;S<=(1<<n)-1;S++){
        for(int v=0;v<n;v++){
                if ((S>>v)&1)
                {
                    for(int u=0;u<n;u++)
                        dp[S|1<<u][u]=min(dp[S|1<<u][u],dp[S][v]+a[v][u]);
                }
        }
    }
    cout<<dp[(1<<n)-1][0]<<endl;

}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF&&n){
        n++;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&a[i][j]);
            }
        }
        for(int k=0;k<n;k++)
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    if(a[i][j]>a[i][k]+a[k][j])
                        a[i][j]=a[i][k]+a[k][j];
        tsp(n);
    }
    return 0;
}
