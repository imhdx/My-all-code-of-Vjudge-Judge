#include<bits/stdc++.h>
using namespace std;
struct note
{
    int x;
    int id;
}que[1010];
int m;
bool cmp(struct note q,struct note p)
{
    if (q.x!=p.x) return q.x>p.x;
    if (q.id==m) return 1;
    else return 0;
}
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int n;
        int i,j;
        scanf("%d%d",&n,&m);
        for (i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            que[i].x=x;
            que[i].id=i+1;
        }
        sort(que,que+n,cmp);
        for (i=0;i<n;i++)
        {
            if (que[i].id==m) break;
        }
        printf("%d\n",i);
    }
    return 0;
}
