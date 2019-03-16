#include<bits/stdc++.h>
using namespace std;
int l[500010],r[500010];
int dp[500010][2];
char str[500010];
int pos=0;
int cnt=1;
int len;
void build(int x)
{
    char ch=getchar();
    if (ch=='0')
    {
        l[x]=0;
        r[x]=0;
        return ;
    }
    if (ch=='1')
    {
        l[x]=++cnt;
        r[x]=0;
        build(cnt);
    }
    else if (ch=='2')
    {
        l[x]=++cnt;
        build(cnt);
        r[x]=++cnt;
        build(cnt);
    }
}

void dfs1(int x)
{
    if (x==0) return ;
    dfs1(l[x]);
    dfs1(r[x]);
    dp[x][1]=dp[l[x]][0]+dp[r[x]][0]+1;
    dp[x][0]=max(dp[l[x]][0]+dp[r[x]][1],dp[l[x]][1]+dp[r[x]][0]);
}
void dfs2(int x)
{
    if (x==0) return ;
    dfs2(l[x]);
    dfs2(r[x]);
    dp[x][1]=dp[l[x]][0]+dp[r[x]][0]+1;
    dp[x][0]=min(dp[l[x]][0]+dp[r[x]][1],dp[l[x]][1]+dp[r[x]][0]);
}
int main()
{
    memset(l,0,sizeof(l));
    memset(r,0,sizeof(r));
    //scanf("%s",str);
    //len=strlen(str);
    build(1);
    dfs1(1);
    int ans1=max(dp[1][0],dp[1][1]);
    memset(dp,0,sizeof(dp));

    dfs2(1);
    int ans2=min(dp[1][1],dp[1][0]);
    printf("%d %d\n",ans1,ans2);
    return 0;
}
