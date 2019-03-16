#include<bits/stdc++.h>
using namespace std;
const double eps=1e-7;
int main()
{
    int x,y;
    while (scanf("%d%d",&x,&y)!=EOF)
    {
        if (x>y)
        {
            printf("%d\n",-1);
            continue;
        }
        else if (x==1)
        {
            printf("%d\n",y-1);
        }
        else
        {
            int cnt=0;
            double yy=1.0;
            double xx=1.0;
            double s=1.0*(y+0.99999)/x;
            cnt=x-xx;
            while (xx<=x)
            {
                cnt+=(int)((s*xx-yy)+eps);
                //printf("cnt=%d\n",(int)((s*xx-yy)+eps));
                yy+=(int)((s*xx-yy)+eps);
                //printf("%f %f\n",xx,yy);
                yy+=yy/xx;
                xx=xx+1.0;
                //printf("%f %f\n",xx,yy);
            }
            printf("%d\n",cnt);
        }
    }

    return 0;
}
