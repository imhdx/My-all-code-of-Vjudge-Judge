#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
char str[2001][8];
struct note
{
    int from;
    int to;
    int len;
}que[2000010];
int pre[2001];
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
bool cmp(struct note a,struct note b)
{
    return a.len<b.len;
}
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        if (n==0) break;
        getchar();
        int i,j,k;
        for (i=0;i<2001;i++) pre[i]=i;
        for (i=0;i<n;i++)
        {
            gets(str[i]);
        }
        int kk=0;
        for (i=0;i<n;i++)
        {
            for (j=i+1;j<n;j++)
            {
                int l=0;
                for (k=0;k<8;k++)
                {
                    if (str[i][k]!=str[j][k]) l++;
                }
                que[kk].from=i;
                que[kk].to=j;
                que[kk].len=l;
                kk++;
            }
        }
        sort(que,que+kk,cmp);
        int ans=0;
        int cc=0;
        for (i=0;i<kk;i++)
        {
            if (jie(que[i].from,que[i].to)) {cc++;ans=ans+que[i].len;}
        }
        printf("The highest possible quality is 1/%d.\n",ans);

    }

    return 0;
}
