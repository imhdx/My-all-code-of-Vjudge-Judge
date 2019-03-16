#include<cstdio>
#include<iostream>
#include<cstring>
#include<stack>
#include<cstdlib>
#include<queue>
using namespace std;
struct note
{
    int r;
    int w;
    note(){r=0;w=0;}
}que[28];
char a[9999999];
int main()
{
    stack<note>p;
    int i;
    int n;
    char c;
    int qqq;
    int www;
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        getchar();
        scanf("%c %d %d",&c,&qqq,&www);
        que[c-'A'].r=qqq;
        que[c-'A'].w=www;
    }
    int sum=0;
    struct note qq,ww;
    getchar();
    printf("\n");
    while (gets(a)!=NULL)
    {
        while(!p.empty())
            p.pop();
        sum=0;
        int flag=0;
        for (i=0;a[i];i++)
        {
            if (a[i]>='A'&&a[i]<='Z')
            {
                p.push(que[a[i]-'A']);
            }
            else if (a[i]==')')
            {
                ww=p.top(); p.pop();
                qq=p.top(); p.pop();
                if (qq.w!=ww.r)
                {
                    flag=1;
                    break;
                }
                sum=sum+qq.w*qq.r*ww.w;
                ww.r=qq.r;
                p.push(ww);
            }
        }
        if (flag==0)
            printf("%d\n",sum);
        else
            printf("error\n");
    }
    return 0;
}
