#include<bits/stdc++.h>
using namespace std;
char str[30][30];
struct node
{
    char c;
    int times;
}que[10];
int tt[30];
bool cmp(struct node q,struct node p)
{
    if (q.times==p.times) return q.c<p.c;
    return q.times>p.times;
}
int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        if (n==0&&m==0) return 0;
        memset(tt,0,sizeof(tt));
        for (int i=0;i<n;i++) scanf("%s",str[i]);

        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                tt[str[i][j]-'A']++;
            }
        }
        int cnt=0;
        if (tt['E'-'A']!=0)
        que[cnt].c='E',que[cnt].times=tt['E'-'A'],cnt++;
        if (tt['A'-'A']!=0)
        que[cnt].c='A',que[cnt].times=tt['A'-'A'],cnt++;
        if (tt['C'-'A']!=0)
        {
        que[cnt].c='C';
        que[cnt].times=tt['C'-'A'];
        cnt++;
        }
        if (tt['D'-'A']!=0)
        {
        que[cnt].c='D';
        que[cnt].times=tt['D'-'A'];
        cnt++;
        }
        if (tt['G'-'A']!=0)
        {
        que[cnt].c='G';
        que[cnt].times=tt['G'-'A'];
        cnt++;
        }
        sort(que,que+cnt,cmp);
        for (int i=0;i<cnt;i++)
        {
            printf("%c %d%c",que[i].c,que[i].times," \n"[i==cnt-1]);
        }
    }
    return 0;
}
