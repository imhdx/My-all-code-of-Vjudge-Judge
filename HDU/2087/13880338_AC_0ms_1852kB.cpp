#include<cstdio>
#include<cstring>
using namespace std;
char a[1001];
char b[1001];
int main()
{
    int i,j;
    while (scanf("%s",a)!=EOF)
    {
        if (a[0]=='#') break;
        scanf("%s",b);
        int ans=0;
        for (i=0;a[i];i++)
        {
            int k=0;
            for (j=0;b[j];j++)
            {
                if (a[i+k]==0) break;
                if (a[i+k]==b[j])
                {
                    k++;
                }
                else
                {
                    break;
                }
            }
            if (b[j]==0)
            {
                i=i+k-1;
                ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
