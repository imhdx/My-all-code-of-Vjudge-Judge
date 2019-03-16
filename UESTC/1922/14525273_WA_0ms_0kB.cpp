#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;

struct note
{
    int num;
    int fi;
    int la;
    int zai;
}que[100010];

int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        int j;
        int tou=0;
        int wei=0;
        for (j=0;j<n;j++)
        {
            int p;
            scanf("%d",&p);
            if (p==1)
            {
                int t,a,b,i;
                scanf("%d%d%d",&t,&a,&b);
                que[wei].num=a;
                que[wei].fi=t;
                que[wei].la=t+b;
                que[wei].zai=1;
                wei++;
            }
            else if(p==2)
            {
                int t;
                scanf("%d",&t);
                int i=tou;
                while (i<wei)
                {
                    if (que[i].zai==1&&que[i].fi<=t&&que[i].la>t)
                    {
                        que[i].zai=0;
                        break;
                    }
                    i++;
                }
                tou=i+1;
            }
            else if(p==3)
            {
                int t;
                scanf("%d",&t);
                int i=tou;
                while (i<wei)
                {
                    if (que[i].zai==1&&que[i].fi<=t&&que[i].la>t)
                    {
                        break;
                    }
                    i++;
                }
                if (i<wei)
                printf("%d\n",que[i].num);
                else
                    printf("-1\n");

            }
        }
    }


    return 0;
}
