#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
int n,m;
int pre[201];
int get(int x)
{
    if (pre[x]==x) return x;
    return pre[x]=get(pre[x]);
}
bool jie(int a,int b)
{
    int x=get(a);
    int y=get(b);
    if (x==y) return false;
    if (x>y) pre[x]=y;
    else
        pre[y]=x;
    return true;
}
struct note
{
    int len;
    int from;
    int to;
}que[40100];
bool cmp(struct note a,struct note b)
{
    return a.len<b.len;
}
int xxx[201],yyy[201];
int main()
{
	int tyf=1;
    while (scanf("%d",&n)!=EOF)
    {
        if (n==0) break;
        int i,j;
        for (i=0;i<201;i++)
            pre[i]=i;
            for (i=0;i<n;i++)
            	scanf("%d%d",&xxx[i],&yyy[i]);
        int k=0;
        for (i=0;i<n;i++)
        {
            for (j=0;j<n;j++)
            {
                        if (i==j) continue;
            	que[k].from=i;
            	que[k].to=j;
            	que[k].len=(xxx[i]-xxx[j])*(xxx[i]-xxx[j])+(yyy[i]-yyy[j])*(yyy[i]-yyy[j]);
            	++k;
            }
        }
        sort(que,que+k,cmp);
        int ans=0;
        for (i=0;i<k;i++)
        {
            if (jie(que[i].from,que[i].to))
            {
            	if (get(0)==get(1))
            	{
            		ans=que[i].len;
            		break;
            	}
            }
        }
        
        printf("Scenario #%d\n",tyf);
        printf("Frog Distance = %.3f\n\n",sqrt(ans));
        tyf++;
    }
    return 0;
}