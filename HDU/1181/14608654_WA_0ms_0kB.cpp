#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    char a[1000];
    int flag=0;
    int tag=0;
    while (scanf("%s",a)!=EOF)
    {
        if (a[0]=='b') flag=1;
        if (a[strlen(a)-1]=='m') tag=1;
        if (strcmp(a,"0")==0)
{
printf("No.\n");
continue;
}
        while (1)
        {
            scanf("%s",a);
            if (a[0]=='b') flag=1;
            if (a[strlen(a)-1]=='m') tag=1;
            if (strcmp(a,"0")==0) break;
        }
        if (flag==1&&tag==1) printf("Yes.\n");
        else
            printf("No.\n");
    }
    return 0;
}
