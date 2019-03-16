#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    char a[1000];
    while (scanf("%s",a)!=EOF)
    {
        int flag=0;
        int tag=0;
        if (a[0]=='b') flag=1;
        if (a[strlen(a)-1]=='m') tag=1;
        while (1)
        {
            if (strcmp(a,"0")==0) break;
            scanf("%s",a);
            if (a[0]=='b') flag=1;
            if (a[strlen(a)-1]=='m') tag=1;
        }
        if (flag==1&&tag==1) printf("Yes.\n");
        else
            printf("No.\n");
    }
    return 0;
}
