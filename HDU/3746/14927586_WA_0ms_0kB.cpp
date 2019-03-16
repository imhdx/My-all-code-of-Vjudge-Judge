#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int Next[100010];
char T[100010];
int m;
void Getfail()
{
    Next[0] = -1;
    int i = 0, j =-1;
    while(i < m)
    {
        if(j == -1 || T[i] == T[j])
        {
            i++,j++;
            Next[i] = j;
        }
        else
            j = Next[j];
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
        Getfail();
        int len=m-Next[m];
        if (len==0)
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
