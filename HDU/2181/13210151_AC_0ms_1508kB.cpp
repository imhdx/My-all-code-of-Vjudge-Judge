#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int book[21];
int way[21];
struct note
{
    int to[3];
}a[21];
int cc;
int m;
void dfs(int last,int step)
{
    way[step]=last;
    if (step==20)
    {
        if (a[last].to[0]!=m&&a[last].to[1]!=m&&a[last].to[2]!=m) return ;
        printf("%d: ",cc);
        cc++;
        for (int i=1;i<=20;i++)
            printf(" %d",way[i]);
        printf(" %d\n",way[1]);
        return ;
    }
    if (step>20) return ;
    sort(a[last].to,a[last].to+3);
    for (int i=0;i<3;i++)
    {
        if (book[a[last].to[i]]==0)
        {
            book[a[last].to[i]]=1;
            dfs(a[last].to[i],step+1);
            book[a[last].to[i]]=0;
        }
    }
}
int main()
{
    int i,j;
    for (i=1;i<=20;i++)
    {
        for (j=0;j<3;j++)
            scanf("%d",&a[i].to[j]);
    }
    while (scanf("%d",&m)!=EOF&&m!=0)
    {
        cc=1;
        memset(book,0,21*sizeof(int));
        book[m]=1;
        dfs(m,1);


    }


    return 0;
}
