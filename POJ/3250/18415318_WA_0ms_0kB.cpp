#include<cstdio>
#include<cstdlib>
using namespace std;
struct ac
{
    int num,id;
}que[80004];
int main()
{
    int cnt=0;
    int n;
    scanf("%d",&n);
    int ans=0;
    for (int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        while (cnt!=0&&que[cnt-1].num<=x)
        {
            ans+=i-que[cnt-1].id-1;
            //printf("%d %d\n",que[cnt-1].num,i-que[cnt-1].id-1);
            cnt--;
        }
        que[cnt].num=x;
        que[cnt++].id=i;
    }
    while (cnt!=0)
    {
        ans+=n+1-que[cnt-1].id-1;
        //printf("%d %d\n",que[cnt-1].num,n+1-que[cnt-1].id-1);
        cnt--;
    }
    printf("%d\n",ans);
    return 0;
}
