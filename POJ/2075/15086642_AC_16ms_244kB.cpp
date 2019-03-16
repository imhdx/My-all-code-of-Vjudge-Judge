#include<map>
#include<string>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
map<string,int> M;
int pre[511];
struct note
{
    int x,y;
    float len;
}que[130050];
int getx(int x)
{
    if (pre[x]==x) return x;
    return pre[x]=getx(pre[x]);
}
bool cmp(struct note q,struct note p)
{
    return q.len<p.len;
}
int main()
{
    float len;
    while (scanf("%f",&len)!=EOF)
    {
        M.clear();
        int i,j;
        int n;
        scanf("%d",&n);
        for (i=0;i<=n;i++)
            pre[i]=i;
        string str1;
        for (i=0;i<n;i++)
        {
            cin>>str1;
            M[str1]=i;
        }
        int m;
        cin>>m;
        string str2;
        for (i=0;i<m;i++)
        {
            float ll;
            cin>>str1>>str2>>ll;
            que[i].x=M[str1];
            que[i].y=M[str2];
            que[i].len=ll;
        }
        sort(que,que+m,cmp);
        double ans;
        for (i=0;i<m;i++)
        {
            int xx=getx(que[i].x);
            int yy=getx(que[i].y);
            if (xx!=yy)
            {
                if (xx<yy)
                    pre[xx]=yy;
                else
                    pre[yy]=xx;
                ans+=que[i].len;
            }
        }
        if (len>=ans)
            printf("Need %.1f miles of cable\n",ans);
        else
            printf("Not enough cable\n");
    }


    return 0;
}
