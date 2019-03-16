#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;

struct note
{
    int wei;
    int dis;
    friend bool operator<(note a, note b)
    {
        if (a.wei==b.wei)
        return a.dis>b.dis;
        return a.wei>b.wei;
    }
};
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        priority_queue<struct note> que;
        int n;
        scanf("%d",&n);
        int i,j;
        for (i=0;i<n;i++)
        {
            struct note t;
            scanf("%d%d",&t.wei,&t.dis);
            que.push(t);
        }
        int flag=1;
        int ans=-1;
        while (!que.empty())
        {
            if (flag==0)
            {
                flag=1;
                que.pop();
            }
            else
            {
                flag=0;
                struct note t=que.top();
                t.wei=t.wei+t.dis;
                ans=max(ans,t.wei);
                que.push(t);
                que.pop();
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
