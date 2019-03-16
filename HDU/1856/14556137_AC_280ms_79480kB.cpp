#include<stdio.h>
#include<algorithm>
using namespace std;
int map[10000010];
int num[10000010];
int maxx;
int getx(int n)
{
    if (map[n]==n)
        return n;
    return map[n]=getx(map[n]);
}
void nian(int x,int y)
{
    int xx=getx(x);
    int yy=getx(y);
    if (xx!=yy)
    {
        map[xx]=yy;
        num[yy]+=num[xx];
        maxx=max(num[yy],maxx);
    }
}
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        int i;
        maxx=1;
        for (i=1;i<=10000010;i++)
        {
            map[i]=i;
            num[i]=1;
        }
        for (i=0;i<n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            nian(x,y);
        }
        printf("%d\n",maxx);
    }
    return 0;
}
