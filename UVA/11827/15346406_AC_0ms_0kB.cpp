#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
using namespace std;
char str[3000];
int a[103];
int main()
{
    int m;
    scanf("%d",&m);
    getchar();
    while (m--)
    {
        gets(str);
        int i;
        int cnt=0;
        int len=strlen(str);
        for (i=0;i<len;i++)
        {
            int num=0;
            while (i<len&&str[i]!=' ')
            {
                num=num*10+str[i]-'0';
                i++;
            }
            a[cnt++]=num;
        }
        int ans=0;
        for (int i=0;i<cnt;i++)
        {
            for (int j=i+1;j<cnt;j++)
            {
                ans=max(ans,__gcd(a[i],a[j]));
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
