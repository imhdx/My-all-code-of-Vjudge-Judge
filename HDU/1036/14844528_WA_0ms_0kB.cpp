#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    double mm;
    scanf("%d%lf",&n,&mm);
    int name;
    while (scanf("%d",&name)!=EOF)
    {
        printf("%3d ",name);
        int h,m,s;
        double sum=0;
        int flag=0;
        for (int i=0;i<n;i++)
        {
            if (scanf("%d:%d:%d",&h,&m,&s)==3)
            {
                sum+=h*3600+m*60+s;
            }
            else
            {
                flag=1;
                break;
            }
        }
        if (flag==1)
        {
            char w[1000];
            gets(w);
            printf("-\n");
            continue;
        }
        else
        {
            int ans=(int)(sum/mm+0.500);
            printf("%01d:%02d min/km\n",ans/60,ans%60);
        }
    }
    return 0;
}
