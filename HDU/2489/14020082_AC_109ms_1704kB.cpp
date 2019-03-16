#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
double esp=1e-3;
int n,m;
double minn=100000000;
int a[20];
int map[20][20];
int pre[20];
int kkk[20];
int anss[20];
struct note
{
    int len;
    int from;
    int to;
}que[410];
bool cmp(struct note a,struct note b)
{
    return a.len<b.len;
}
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
void dfs(int f,int num)
{
    int i,j;
    if (num==m)
    {

        int kk=0;
        for (i=0;i<20;i++) pre[i]=i;
        for (i=0;i<m;i++)
        {
            for (j=0;j<m;j++)
            {
                que[kk].from=kkk[i];
                que[kk].to=kkk[j];
                que[kk].len=map[kkk[i]][kkk[j]];
                ++kk;
            }
        }
        double ans1=0;
        double ans2=0;
        for (i=0;i<m;i++) ans1=ans1+a[kkk[i]];
        sort(que,que+kk,cmp);
        int cc=0;
        for (i=0;i<kk;i++)
        {
            if (jie(que[i].from,que[i].to))
            {
                ans2=ans2+que[i].len;
            }
        }
        double jkl=(ans2/ans1);
        if (minn-jkl>esp)
        {
            minn=(ans2/ans1);
            for (i=0;i<m;i++)
            {
                anss[i]=kkk[i];
            }
        }
    }
    for (i=f+1;i<n;i++)
    {
        kkk[num]=i;
        dfs(i,num+1);
    }



}
int main()
{
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        minn=100000000;
        if (n==0&&m==0) break;
        int i,j;
        for (i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for (i=0;i<n;i++)
        {
            for (j=0;j<n;j++)
                scanf("%d",&map[i][j]);
        }
        dfs(-1,0);
        for (i=0;i<m-1;i++)
            printf("%d ",anss[i]+1);
        printf("%d",anss[m-1]+1);
        printf("\n");
    }
   return 0;
}
