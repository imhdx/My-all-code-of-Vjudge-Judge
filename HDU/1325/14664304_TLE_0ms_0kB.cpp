#include<cstdio>
int pre[100000];
int getx(int x)
{
    if (x==pre[x]) return x;
    return pre[x]=getx(pre[x]);
}
int main()
{
    int i;
    int cnt=1;
    int x,y;
    while (scanf("%d%d",&x,&y)!=EOF)
    {
        if (x==-1&&y==-1) return 0;
        if (x==0&&y==0)
        {
            printf("Case %d is a tree.\n",cnt++);
            continue;
        }
        for (i=0;i<100000;i++)
            pre[i]=i;
        pre[y]=x;
        int flag=0;
        while (1)
        {
            scanf("%d%d",&x,&y);
            if (x==0&&y==0) break;
            int xx=getx(x);
            int yy=getx(y);
            if (xx==yy)
            {
                flag=1;
            }
            else
            {
                pre[xx]=yy;
            }
        }
        if (flag==0) printf("Case %d is a tree.\n",cnt++);
        else
            printf("Case %d is not a tree.\n",cnt++);
    }
}
