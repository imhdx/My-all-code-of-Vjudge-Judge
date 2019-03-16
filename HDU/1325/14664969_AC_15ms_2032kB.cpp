#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
int pre[100010];
int ss[100010];
map<int,int> M;
int getx(int x)
{
    if (x==pre[x])
        return x;
    return pre[x]=getx(pre[x]);
}
int main()
{
    int i;
    int cnt=1;
    int x,y;
    while (scanf("%d%d",&x,&y)!=EOF)
    {
        M.clear();
        int tx=x;
        int minn=100011;
        int maxx=0;
        minn=min(minn,x);
        minn=min(minn,y);
        maxx=max(maxx,x);
        maxx=max(maxx,y);
        int n=0;
        if (x<0||y<0)
            return 0;
        if (x==0&&y==0)
        {
            printf("Case %d is a tree.\n",cnt++);
            continue;
        }
        for (i=0; i<100010; i++)
        {
            ss[i]=0;
            pre[i]=i;
        }
        int flag=0;
        if (getx(x)!=getx(y))
        {
            pre[y]=x;
        }
        else
        {
            flag=1;
        }
        M[y]++;
        ss[x]=1;
        ss[y]=1;
        while (1)
        {
            scanf("%d%d",&x,&y);
            if (x==0&&y==0)
                break;
            M[y]++;
            ss[x]=1;
            ss[y]=1;
            minn=min(minn,x);
            minn=min(minn,y);
            maxx=max(maxx,x);
            maxx=max(maxx,y);
            int xx=getx(x);
            int yy=getx(y);
            if (xx==yy)
            {
                flag=1;
            }
            else
            {
                pre[yy]=xx;
            }
        }
        int ccc=0;
        int kkk=0;
        for (i=minn; i<=maxx; i++)
        {
            if (ss[i])
            {
                kkk++;
                if (getx(i)!=getx(tx))
                {
                    flag=1;
                    break;
                }
                if (M[i]==1) ccc++;
            }
        }
        if (kkk!=ccc+1) flag=1;
        if (flag==0)
            printf("Case %d is a tree.\n",cnt++);
        else
            printf("Case %d is not a tree.\n",cnt++);
    }
    return 0;
}
