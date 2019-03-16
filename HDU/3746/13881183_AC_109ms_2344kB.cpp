#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

int Next[100010];
char T[100010];
int tlen;
void init()
{
    int i,j;
    i=0,j=-1;
    Next[0]=-1;
    while(T[i])
    {
        if(j==-1||T[i]==T[j])
        {
            i++;
            j++;
            Next[i]=j;
        }
        else
            j=Next[j];
    }
}

int main()
{
    int t;
    int i;
    scanf("%d",&t);
    getchar();
    while (t--)
    {
        gets(T);
        tlen=strlen(T);
        init();

        int n=tlen-Next[tlen];
            if(n!=tlen&&tlen%n==0)
                printf("0\n");
            else
                printf("%d\n",n-Next[tlen]%n);

    }
    return 0;
}

