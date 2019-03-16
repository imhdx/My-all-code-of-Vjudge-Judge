#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;
int a[500010];
int b[500010];
int main()
{
    int t=1;
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        int i;
        for (i=0;i<n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            a[x]=y;
        }
        int ans=1;
        b[1]=a[1];
        for (i=2;i<n;i++)
        {
            if (a[i]>b[ans])
            {
                b[++ans]=a[i];
            }
            else
            {
                int pos=lower_bound(b,b+ans+1,a[i])-b;
                b[pos]=a[i];
            }
        }
        printf("Case %d:\n",t++);
        printf("My king, at most %d road can be built.\n\n",ans);
    }

    return 0;
}
