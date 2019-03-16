#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
struct note
{
    int len;
    int zuo;
    int you;
}a[51];
int get(struct note qq,struct note pp)
{
    if (qq.len>=pp.len)
        return qq.zuo+qq.len+pp.len;
    return qq.zuo+3*qq.len-pp.len;
}
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF&&n!=0)
    {
        int i,j;
        for (i=0;i<n;i++)
        {
            scanf("%d",&a[i].len);
            a[i].zuo=0;
        }
        for (i=0;i<n;i++)
        {
            for (j=0;j<i;j++)
            {
                a[i].zuo=max(a[i].zuo,get(a[j],a[i]));
            }
            a[i].you=a[i].zuo+a[i].len*2;
        }
        for(i=0; i<n; i++)
            for(j=0; j<i; j++)
            {
                if(a[i].len<a[j].len&&a[i].zuo<a[j].you)
                    a[i].zuo=a[j].you;
                else if(a[i].len>a[j].len&&a[i].zuo<a[j].you)
                    a[j].you=a[i].zuo;
            }
        for(int i=0; i<n; i++)
            if(a[i].zuo<a[i].you)
                printf("%d ",i+1);
        printf("\n");

    }
    return 0;
}
