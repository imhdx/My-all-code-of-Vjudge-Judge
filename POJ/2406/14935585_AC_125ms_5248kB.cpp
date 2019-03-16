#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int Next[1000005];
char T[1000005];
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
int main()
{
    int n;
    while (scanf("%s",T)!=EOF)
    {
        if (T[0]=='.') return 0;
        m=strlen(T);
        init();
        int len=m-Next[m];
        //printf("最小循环节是%d\n",len);
        if (m%len==0)
            printf("%d\n",m/len);
        else
            printf("%d\n",1);

    }
    return 0;
}
