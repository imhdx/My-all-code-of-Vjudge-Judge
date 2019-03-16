#include<bits/stdc++.h>
using namespace std;
char w[100001];
int main()
{
    int n;
    double mm;
    scanf("%d%lf",&n,&mm);
    int name;
    while (scanf("%d",&name)!=EOF)
    {

        int h,m,s;
        int sum=0;
        int flag=0;
        for (int i=0;i<n;i++)
        {
            scanf("%s",w);
            if (w[0]=='-')
                flag=1;
            else
            {
                sscanf(w,"%d:%d:%d",&h,&m,&s);
                sum+=h*3600+m*60+s;
            }
        }
        if (flag==1)
        {
            printf("%3d:",name);
            printf(" -\n");
            continue;
        }
        else
        {
            int ans=(int)(sum/mm+0.5);
            printf("%3d:",name);
            printf("%2d:%02d min/km\n",ans/60,ans%60);
        }
    }
    return 0;
}
