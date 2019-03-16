#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int Next[100010];
char T[100010];
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
    scanf("%d",&n);
    getchar();
    while (n--)
    {
        scanf("%s",T);
        m=strlen(T);
        init();
        int len=m-Next[m];
        if (len==m)
        {
            printf("%d\n",m);
            continue;
        }
        else
        {
            int ans=(len-m%len)%len;
            printf("%d\n",ans);
        }
    }
    return 0;
}
