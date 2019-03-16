#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        int ans=0;
        for (int i=n;i>=1;i--)
        {
            if (n%i==0&&(i&1)) ans++;
            //else if (n%i==2&&i%2==0) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
