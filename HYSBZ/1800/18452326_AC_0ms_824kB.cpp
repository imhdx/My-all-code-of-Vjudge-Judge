#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
int a[200];
int s[200];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    int cnt=0;
    for (int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    for (int i=0;i<n;i++)
    {
        for (int j=i+1;j<n;j++)
        {
            for (int k=j+1;k<n;k++)
            {
                for (int p=k+1;p<n;p++)
                {
                    if (s[j]-s[i]==s[p]-s[k]&&(s[k]-s[i])*2==s[n])
                        cnt++;
                }
            }
        }
    }
    printf("%d\n",cnt);

    return 0;
}
