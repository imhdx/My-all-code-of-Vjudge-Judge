#include<bits/stdc++.h>
using namespace std;
int dx[4]= {-1,0,1,0};
int dy[4]= {0,-1,0,1};
int getflag(char c)
{
    if (c=='N')
        return 0;
    if (c=='W')
        return 1;
    if (c=='S')
        return 2;
    if (c=='E')
        return 3;
}
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        if (n==0) return 0;
        char b1[10];
        char b2[10];
        int s1,t1,s2,t2;
        scanf("%s%d%d",b1,&s1,&t1);
        scanf("%s%d%d",b2,&s2,&t2);
        int k;
        scanf("%d",&k);
        int x1=1,y1=1;
        int x2=n,y2=n;
        int flag1,flag2;

        flag1=getflag(b1[0]);
        flag2=getflag(b2[0]);
        for (int i=1; i<=k; i++)
        {
            //printf("flag1=%d flag2=%d\n",flag1,flag2);
            for (int j=1;j<=s1;j++)
            {
                x1=x1+dx[flag1];
            y1=y1+dy[flag1];

            if (x1<1||x1>n||y1<1||y1>n)
            {
                flag1=(flag1+2)%4;
                x1=x1+2*dx[flag1];
                y1=y1+2*dy[flag1];
            }

            }
            for (int j=1;j<=s2;j++)
            {
                x2=x2+dx[flag2];
            y2=y2+dy[flag2];
            if (x2<1||x2>n||y2<1||y2>n)
            {
                flag2=(flag2+2)%4;
                x2=x2+2*dx[flag2];
                y2=y2+2*dy[flag2];
            }
            }
            //printf("%d %d %d %d\n",x1,y1,x2,y2);
            if (x1!=x2||y1!=y2)
            {
                if (i%t1==0)
                {
                    flag1=(flag1+1)%4;
                }
                if (i%t2==0)
                {
                    flag2=(flag2+1)%4;
                }
            }
            else
            {
                int tmp=flag1;
                flag1=flag2;
                flag2=tmp;
            }

        }
        printf("%d %d\n%d %d\n",x1,y1,x2,y2);
    }
    return 0;
}
