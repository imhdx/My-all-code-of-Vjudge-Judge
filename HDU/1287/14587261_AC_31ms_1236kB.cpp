#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
int a[30];
int vis[1000];
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        int i;

        for (i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        int j;
        for (i=0;i<26;i++)
        {
            memset(vis,0,sizeof(vis));
            for (j=0;j<26;j++)
            {
                if (vis[('A'+i)^('A'+j)]==1) break;
                vis[('A'+i)^('A'+j)]=1;
            }
            if (j<26) continue;
            for (j=0;j<n;j++)
            {
                if (vis[a[j]]!=1) break;
            }
            if (j==n)
            {
                break;
            }
        }
        int kk=i;
        for (j=0;j<n;j++)
        {
            for (i=0;i<26;i++)
            {
                if ((('A'+i)^('A'+kk))==a[j])
                    printf("%c",'A'+i);
            }
        }
        printf("\n");




    }
    return 0;
}
