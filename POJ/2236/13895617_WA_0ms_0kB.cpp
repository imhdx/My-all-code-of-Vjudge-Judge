#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>

using namespace std;
int n,d;
int book[1010];
struct note
{
    int x,y;
}que[1010];

int jj[1010];
int get(int kk)
{
    int i;
    if (jj[kk]==kk)
        return kk;
    jj[kk]=get(jj[kk]);
    return jj[kk];
}
void lian(int tou,int wei)
{
    if (book[tou]==1&&book[wei]==1)
    if ((que[tou].x-que[wei].x)*(que[tou].x-que[wei].x)+(que[tou].y-que[wei].y)*(que[tou].y-que[wei].y)<=d*d)
    {
        jj[tou]=get(wei);
    }
}

int main()
{

    scanf("%d%d",&n,&d);
    int i,j;
    for (i=1;i<=n;i++)
    {
        scanf("%d %d",&que[i].x,&que[i].y);
        book[i]=0;
        jj[i]=i;
    }
    char str;
    while (cin>>str)
    {
        if (str=='O')
        {
            int k;
            scanf("%d",&k);
            //getchar();
            book[k]=1;
            for (i=1;i<=n;i++)
            {
                lian(i,k);
            }
        }
        else
        {
            int q,p;
            scanf("%d %d",&q,&p);
            if (get(q)==get(p))
                printf("SUCCESS\n");
            else
                printf("FAIL\n");
        }
    }
    return 0;
}