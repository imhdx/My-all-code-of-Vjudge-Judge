#include<cstdio>
#include<algorithm>
using namespace std;
struct note
{
    int ji;
    int num;
}que[3][999];
bool cmp(struct note aaa,struct note bbb)
{
    if (aaa.ji==bbb.ji)
    {
        return aaa.num<bbb.num;
    }
    return aaa.ji>bbb.ji;
}
int main()
{
    int n;
    int k;
    int tou[3],wei[3];
    char a[5];
    while (scanf("%d",&n)!=EOF)
    {
        k=0;
        getchar();
        int i,j;
        for (i=0;i<3;i++) tou[i]=wei[i]=0;
        for (i=0;i<n;i++)
        {
            scanf("%s",a);
            if (a[0]=='I')
            {
                int aa,ss;
                scanf("%d%d",&aa,&ss);
                getchar();
                que[aa][wei[aa]].ji=ss;
                que[aa][wei[aa]].num=k++;
                wei[aa]++;
            }
            else
            {
                int aa;
                scanf("%d",&aa);
                getchar();
                if (tou[aa]==wei[aa])
                    printf("EMPTY\n");
                else
                {
                    sort(que[aa]+tou[aa],que[aa]+wei[aa],cmp);
                    printf("%d\n",que[aa][tou[aa]].num+1);
                    tou[aa]++;
                }
            }
        }
    }
    return 0;
}
