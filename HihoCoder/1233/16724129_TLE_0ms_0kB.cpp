#include<bits/stdc++.h>
using namespace std;
long long vis[(1<<22)];
int n;
int k[10];///存放当前柱子上最小的是谁；
void f(long long ans)
{
    for (int i=0;i<n;i++)
    {
        printf("%d  ",(ans>>(3*(n-i-1)))%8);
    }
    printf("\n");
}
int tt[10];
int a[10];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        memset(vis,-1,sizeof(vis));
        long long val=0;
        for (int i=0;i<n;i++)
        {
            val=(val<<3)+i;
        }
        //f(val);
        
        vis[val]=0;
        queue<long long> que;
        que.push(val);
        while (!que.empty())
        {
            long long val=que.front();
            que.pop();
            long long ans=val;
            memset(k,-1,sizeof(k));
            for (int i=n-1;i>=0;i--)
            {
                int t=(ans)%8;
                ans=ans>>3;
                if (k[t]==-1) k[t]=i;
                else
                    k[t]=min(k[t],i);
            }
            //printf("k\n");
            //for (int i=0;i<n;i++) printf("%d ",k[i]);
            //printf("\n\n");
			for (int i=0;i<n;i++)
            {
            	if (k[i]==-1) continue;
                if (i-1>=0&&(k[i-1]==-1||k[i-1]>k[i]))
                {
                    ans=val-(1<<(3*(n-k[i]-1)));
                    //printf("ans=%lld\n",ans);
                    if (vis[ans]==-1)
                    {
                        //f(ans);
                        que.push(ans);
                        vis[ans]=vis[val]+1;
                    }
                }
                if (i+1<n&&(k[i+1]==-1||k[i+1]>k[i]))
                {
                    ans=val+(1<<(3*(n-k[i]-1)));
                    //printf("ans=%lld\n",ans);
                    if (vis[ans]==-1)
                    {
                        //f(ans);
                        que.push(ans);
                        vis[ans]=vis[val]+1;
                    }
                }
            }
        }
        
        long long int ans=0;
        
        for (int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            tt[i]=a[i];
        }
        if (n<2)
        {
        	printf("0\n");
        	continue;
		}
        sort(tt,tt+n);
        int m=unique(tt,tt+n)-tt;
        for (int i=0;i<n;i++) a[i]=lower_bound(tt,tt+m,a[i])-tt;
        //for (int i=0;i<n;i++) printf("%d ",a[i]);
        //printf("\n");
        ans=0;
        for (int i=0;i<n;i++)
        {
        	tt[a[i]]=i;
		}
        for (int i=0;i<n;i++)
        {
            ans=(ans<<3)+tt[i];
        }
        //f(ans);
        printf("%d\n",vis[ans]);
    }
    return 0;
}
