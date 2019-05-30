//
// Created by mhdx on 2019/5/11.
//

#include<bits/stdc++.h>
using namespace std;
int a[100005];
int b[100005];
bool vis[100005];
vector<int> len1;
int len2[100005];
int n,m;
void dfs1(int x,int h)
{
    if (vis[x]==1)
    {
        len1.push_back(h);
        return ;
    }
    vis[x]=1;
    dfs1(a[x],h+1);
}
void dfs2(int x,int h)
{
    if (vis[x]==1)
    {
        len2[h]++;
        return ;
    }
    vis[x]=1;
    dfs2(b[x],h+1);
}
const int mod=1e9+7;
int main()
{
    int tt=1;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        len1.clear();
        for (int i=0;i<n;i++) scanf("%d",&a[i]);
        for (int i=0;i<m;i++) scanf("%d",&b[i]);
        memset(vis,0,sizeof(vis));
        for (int i=0;i<n;i++)
        {
            if (vis[i]==0) dfs1(i,0);
        }
        memset(vis,0,sizeof(vis));

        memset(len2,0,sizeof(len2));
        for (int i=0;i<m;i++)
        {
            if (vis[i]==0) dfs2(i,0);
        }
        long long ans=1;
        for (int i=0;i<len1.size();i++)
        {
            long long tmp=0;
            for (int j=1;1ll*j*j<=len1[i];j++)
            {
                if (len1[i]%j==0)
                {
                    if (len2[j])
                    {
                        (tmp+=1ll*len2[j]*j%mod)%=mod;
                    }
                    if (len1[i]/j!=j&&len2[len1[i]/j])
                    {
                        (tmp+=1ll*len2[len1[i]/j]%mod*(len1[i]/j)%mod)%=mod;
                    }
                }
            }
            (ans*=tmp)%=mod;
        }
        printf("Case #%d: ",tt++);
        printf("%lld\n",ans);
    }

    return 0;
}//