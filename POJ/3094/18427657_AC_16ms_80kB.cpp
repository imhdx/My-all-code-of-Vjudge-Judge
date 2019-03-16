#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    char str[300];
    while (gets(str))
    {
        if (str[0]=='#') return 0;
        long long ans=0;
        for (int i=0;str[i];i++)
        {
            if (str[i]==' ') continue;
            ans+=(str[i]-'A'+1)*(i+1);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
