//
// Created by mhdx on 2019/5/6.
//

#include<bits/stdc++.h>
using namespace std;
struct node
{
    int x,y,l,op;
}que[102];
struct duan
{
    int x;
    int val;
    bool operator<(const duan &b)const{
        if (x!=b.x) return x<b.x;
        return val<b.val;
    }
}ac[102];
int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        for (int i=0;i<m;i++)
        {
            scanf("%d%d%d%d",&que[i].x,&que[i].y,&que[i].l,&que[i].op);
            que[i].x++;que[i].y++;
            swap(que[i].x,que[i].y);
            if (que[i].op==0) que[i].x--;
            else if (que[i].op==2) que[i].y--;
            else if (que[i].op==3) que[i].x--,que[i].y--;
        }
        long long ans=0;
        for (int i=1;i<=n;i++)
        {
            int cnt=0;
            for (int j=0;j<m;j++)
            {
                if (que[j].op==0)
                {
                    if (i>que[j].x||i<que[j].x-que[j].l+1) continue;
                    int l=que[j].y;
                    int r=i-(que[j].x-que[j].l+1)+que[j].y;
                    r=min(r,n);
                    ac[cnt++]=duan{l,1};
                    ac[cnt++]=duan{r+1,-1};
                }
                else if (que[j].op==1)
                {
                    if (i<que[j].x||i>que[j].x+que[j].l-1) continue;
                    int l=que[j].y;
                    int r=que[j].x+que[j].l-1-i+que[j].y;
                    r=min(r,n);
                    ac[cnt++]=duan{l,1};
                    ac[cnt++]=duan{r+1,-1};
                }
                else if (que[j].op==2) {
                    if (i<que[j].x||i>que[j].x+que[j].l-1) continue;
                    int r=que[j].y;
                    int l=que[j].y-(que[j].x+que[j].l-1-i);
                    l=max(l,1);
                    ac[cnt++]=duan{l,1};
                    ac[cnt++]=duan{r+1,-1};
                }
                else
                {
                    if (i>que[j].x||i<que[j].x-que[j].l+1) continue;
                    int r=que[j].y;
                    int l=que[j].y-(i-(que[j].x-que[j].l+1));
                    l=max(l,1);
                    ac[cnt++]=duan{l,1};
                    ac[cnt++]=duan{r+1,-1};
                }
            }
            sort(ac,ac+cnt);
            long long tmp=0;
            int tt=0;

            for (int i=0;i<cnt;i++)
            {
                if (tmp&1)
                {
                    ans+=ac[i].x-ac[i-1].x;
                }
                tmp+=ac[i].val;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}