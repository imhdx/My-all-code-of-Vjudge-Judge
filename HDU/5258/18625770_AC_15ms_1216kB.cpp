#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
#define y1 cjlaccjlac1
struct ac
{
    int x1,x2,y1,y2;
}ac[30];
bool jiao(int x,int y)
{
    if (ac[x].x1==ac[x].x2)
    {
        if (ac[y].y1==ac[y].y2)
        {
            if ((ac[y].y1-ac[x].y1)*(ac[y].y1-ac[x].y2)<0)
            {
                if ((ac[x].x1-ac[y].x1)*(ac[x].x1-ac[y].x2)<0) return 1;
                else return 0;
            }
            else return 0;
        }
        else return 0;
    }
    else if (ac[x].y1==ac[x].y2)
    {
        if (ac[y].x1==ac[y].x2)
        {
            swap(x,y);
            if ((ac[y].y1-ac[x].y1)*(ac[y].y1-ac[x].y2)<0)
            {
                if ((ac[x].x1-ac[y].x1)*(ac[x].x1-ac[y].x2)<0) return 1;
                else return 0;
            }
            else return 0;
        }
        else return 0;
    }
    else return 0;
}
bool f(int x,int y,int z,int w)
{
    int a=jiao(x,y)+jiao(x,z)+jiao(x,w)+
    jiao(y,z)+jiao(y,w)+jiao(z,w);
    return a==4;
}
int main()
{
    int T;
    int tt=1;
    scanf("%d",&T);
    while (T--)
    {
        int n;scanf("%d",&n);
        for (int i=0;i<n;i++)
        {
            scanf("%d%d%d%d",&ac[i].x1,&ac[i].y1,&ac[i].x2,&ac[i].y2);
        }
        int cnt=0;
        for (int i=0;i<n;i++)
        {
            for (int j=i+1;j<n;j++)
            {
                for (int k=j+1;k<n;k++)
                {
                    for (int p=k+1;p<n;p++)
                    {

                        if (f(i,j,k,p))
                        {
                            cnt++;
                        }
                    }
                }
            }
        }
        printf("Case #%d:\n",tt++);
        printf("%d\n",cnt);
    }
    return 0;
}
