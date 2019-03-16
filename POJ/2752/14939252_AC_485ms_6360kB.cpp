#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
using namespace std;
int Next[1000010];
char T[1000010];
int m;
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
void Print(int t)
{
    if (Next[t]==0) return ;
    Print(Next[t]);
    printf("%d ",Next[t]);
}
int main()
{
    while (scanf("%s",T)!=EOF)
    {
        init();
        int m=strlen(T);

        Print(m);
        printf("%d\n",m);

    }
    return 0;
}
