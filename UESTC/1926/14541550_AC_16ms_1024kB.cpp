#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>

using namespace std;
int map[300100];
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
    for (i=0;i<m;i++)
    {
        char kk[5];
        int x,y;
        scanf("%s%d%d",&kk,&x,&y);
        if (kk[0]=='A')
        {
            int s;
            scanf("%d",&s);
            if (s==1)
            {
                nian(x,y);
                nian(x+n,y+n);
            }
            else if (s==2)
            {
                nian(x,y+n);
                nian(y,x+n);
            }
        }
        else if (kk[0]=='Q')
        {
            if (getx(x)==getx(y))
            {
                printf("%d\n",1);
            }
            else if (getx(x)==getx(y+n)||getx(y)==getx(x+n))
            {
                printf("%d\n",2);
            }
            else
                printf("3\n");

        }
    }



    return 0;
}
