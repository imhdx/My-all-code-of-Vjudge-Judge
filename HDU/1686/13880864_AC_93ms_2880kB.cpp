#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

int Next[10010];
char S[1000010],T[10010];
int slen,tlen;
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
int KMP()
{
    int ans = 0;
    int i, j = 0;
    if(slen==1&&tlen==1)
    {
        if(S[0] == T[0])
            return 1;
        else
            return 0;
    }
    init();
    for(i=0;i<slen;i++)
    {
        while(j>0&&S[i]!=T[j])
            j=Next[j];
        if(S[i]==T[j])
            j++;
        if(j==tlen)
        {
            ans++;
            j=Next[j];
        }
    }
    return ans;
}
int main()
{
    int t;
    scanf("%d",&t);
    getchar();
    while (t--)
    {
        gets(T);
        gets(S);
        slen=strlen(S);
        tlen=strlen(T);
        printf("%d\n",KMP());
    }
    return 0;
}
