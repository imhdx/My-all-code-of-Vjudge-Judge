#include<cstdio>
#include<cmath>
struct note
{
    double x1,y1,x2,y2;
}que[110];
int n;
const double eps=1e-8;
int dcmp(double x)
{
    if(fabs(x)<eps)  return 0;
    else return x<0?-1:1;
}
bool work()
{
    int i;
    if (n==2) return true;
    double x1=que[0].x1;
    double y1=que[0].y1;
    double x2=que[1].x1;
    double y2=que[1].y1;
    for (i=2;i<n;i++)
    {
        if (dcmp(((que[i].x1-x1)*(que[i].y1-y2)-(que[i].x1-x2)*(que[i].y1-y1))*(que[i].x2-x1)*(que[i].y2-y2)-(que[i].x2-x2)*(que[i].y2-y1))>=0) break;
    }
    if (i==n) return true;
    x1=que[0].x2;
    y1=que[0].y2;
    x2=que[1].x1;
    y2=que[1].y1;
    for (i=2;i<n;i++)
    {
        if (dcmp(((que[i].x1-x1)*(que[i].y1-y2)-(que[i].x1-x2)*(que[i].y1-y1))*(que[i].x2-x1)*(que[i].y2-y2)-(que[i].x2-x2)*(que[i].y2-y1))>=0) break;
    }
    if (i==n) return true;
    x1=que[0].x1;
    y1=que[0].y1;
    x2=que[1].x2;
    y2=que[1].y2;
    for (i=2;i<n;i++)
    {
        if (dcmp(((que[i].x1-x1)*(que[i].y1-y2)-(que[i].x1-x2)*(que[i].y1-y1))*(que[i].x2-x1)*(que[i].y2-y2)-(que[i].x2-x2)*(que[i].y2-y1))>=0) break;
    }
    if (i==n) return true;
    x1=que[0].x2;
    y1=que[0].y2;
    x2=que[1].x2;
    y2=que[1].y2;
    for (i=2;i<n;i++)
    {
        if (dcmp(((que[i].x1-x1)*(que[i].y1-y2)-(que[i].x1-x2)*(que[i].y1-y1))*(que[i].x2-x1)*(que[i].y2-y2)-(que[i].x2-x2)*(que[i].y2-y1))>=0) break;
    }
    if (i==n) return true;
    return false;
}

int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&n);
        int i,j;
        for (i=0;i<n;i++)
        {
            scanf("%lf%lf%lf%lf",&que[i].x1,&que[i].y1,&que[i].x2,&que[i].y2);
        }

        if (work())
            printf("Yes!\n");
        else
            printf("No!\n");

    }
    return 0;
}
