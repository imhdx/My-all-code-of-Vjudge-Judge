#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>

using namespace std;
int map[300009];
int getx(int a)
{
    if (map[a]==a)
    {
        return a;
    }
    return map[a]=getx(map[a]);
}
void nian(int a,int b)
{
    int x=getx(a);
    int y=getx(b);
    if (x!=y)
        map[x]=y;
}
bool check(int a,int b)
{
    return getx(a)!=getx(b);
}
int main()
{
    int n,m;
    int flag=-1;
    int i;
    scanf("%d%d",&n,&m);
    for (i=1;i<=3*n;i++)
        map[i]=i;
    int ans=0;
    for (i=0;i<m;i++)
    {
        int kk,x,y;
        scanf("%d%d%d",&kk,&x,&y);
        if(kk==1)
        {
            if(check(x,y+n)&&check(x,y+2*n))
            {
                nian(x,y);
                nian(x+n,y+n);
                nian(x+2*n,y+2*n);
            }
            else
            {
                ans++;
                continue;
            }
        }
        else
        {
            if(check(x,y)&&check(x,y+2*n))
            {
                nian(x,y+n);
                nian(x+n,y+2*n);
                nian(x+2*n,y);
            }
            else
            {
                ans++;
                continue;
            }
        }
    }
    printf("%d\n",ans);



    return 0;
}
