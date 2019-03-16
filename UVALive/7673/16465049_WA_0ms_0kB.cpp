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
        que[0].c='A';
        que[0].times=tt['A'-'A'];
        que[1].c='C';
        que[1].times=tt['C'-'A'];
        que[2].c='D';
        que[2].times=tt['D'-'A'];
        que[3].c='G';
        que[3].times=tt['G'-'A'];
        sort(que,que+4,cmp);
        for (int i=0;i<4;i++)
        {
            printf("%c %d%c",que[i].c,que[i].times," \n"[i==3]);
        }
    }
    return 0;
}
