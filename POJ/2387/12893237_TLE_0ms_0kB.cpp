#include<stdio.h>
int a[1200][1200];
int book[1200];
int min=999999;
int n;
void dfs(int city,int dis)
{
    if (dis>999999) return ;
    if (city==n)
    {
        if (dis<min) min=dis;
        return ;
    }
    int i;
    for (i=1;i<=n;i++)
    {
        if (a[i][city]!=999999&&book[i]==0)
        {
            book[i]=1;
            dfs(i,dis+a[i][city]);
            book[i]=0;
        }
    }
    return ;
}
int main()
{
    int t;
    while (scanf("%d%d",&t,&n)!=EOF)
    {
        int j,i;
        for (i=0;i<1200;i++)
            for (j=0;j<1200;j++)
            {
                a[i][j]=999999;
                if (i==j) a[i][j]=0;
            }
        for (i=0;i<1200;i++) book[i]=0;
        int q,p,len;
        for (i=0;i<t;i++)
        {
            scanf("%d%d%d",&q,&p,&len);
            a[q][p]=len;
            a[p][q]=len;
        }
        book[1]=1;
        min=999999;
        dfs(1,0);
        printf("%d\n",min);
    }
    return 0;
}
