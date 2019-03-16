#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
char a1[1000001];
char a2[10001];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int aa,bb;
        scanf("%d%d",&aa,&bb);
        int i,j;
        for (i=0;i<aa;i++)
        {
            int dd;
            scanf("%d",&dd);
            a1[i]=dd+'0';
        }
        a1[i]=0;



        for (j=0;j<bb;j++)
        {
            int dd;
            scanf("%d",&dd);
            a2[j]=dd+'0';
        }
        a2[j]=0;

        char *p=strstr(a1,a2);
        if (p==NULL)
            printf("-1\n");
        else
            printf("%d\n",p-a1+1);
    }
    return 0;
}
