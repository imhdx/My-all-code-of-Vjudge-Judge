#include<bits/stdc++.h>
using namespace std;
struct node
{
    long long int p,s;

}que[100005];
long long minn[100005];
int ss[100005];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        int m;
        scanf("%d%d",&n,&m);
        for (int i=0;i<n;i++)
        {
            scanf("%d%d",&que[i].s,&que[i].p);
            ss[i]=que[i].s;
        }
        minn[n-1]=que[n-1].s*que[n-1].p;
        for (int i=n-2;i>=0;i--)
        {
            minn[i]=min(minn[i+1],que[i].s*que[i].p);
        }
        for (int i=0;i<n;i++)
        {
            printf("%lld ",minn[i]);
        }
        printf("\n");
        for (int i=0;i<m;i++)
        {
            int x;
            scanf("%d",&x);
            if (x==0)
            {
                printf("0\n");
                continue;
            }
            int pos=lower_bound(ss,ss+n,x)-ss;
            pos=max(0,pos-1);
            long long ans;
            //printf("pos=%d\n",pos);
            if (pos>=0&&pos<n)
            {
                ans=que[pos].p*x;
            }
            else
                ans=que[n-1].p*x;
            //printf("ans1=%lld\n",ans);
            if (pos+1<n)
            {
                if (pos+1<n) ans=min(ans,minn[pos+1]);
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}
