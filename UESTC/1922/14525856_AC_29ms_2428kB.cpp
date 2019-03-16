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
            int t;
            scanf("%d%d",&p,&t);
            if (p==1)
            {
                int a,b;
                scanf("%d%d",&a,&b);
                que[wei].num=a;
                que[wei].fi=t;
                que[wei].la=t+b;
                wei++;
            }
            else if(p==2)
            {
                int i=tou;
                while (i<wei)
                {
                    if (que[i].fi<=t&&que[i].la>t)
                    {
                        break;
                    }
                    i++;
                }
                if (i<wei)
                tou=i+1;
            }
            else if(p==3)
            {
                int i=tou;
                while (i<wei)
                {
                    if (que[i].fi<=t&&que[i].la>t)
                    {
                        break;
                    }
                    i++;
                }
                tou=i;
                if (i<wei)
                printf("%d\n",que[i].num);
                else
                    printf("-1\n");
            }
        }
    }


    return 0;
}

