#include<bits/stdc++.h>
using namespace std;
const int MAX=3000005;
long long int euler[MAX];
void init()
{
    euler[1]=1;
    for (int i=2;i<MAX;i++)
    {
        if (!euler[i])
            for (int j=i;j<MAX;j+=i)
        {
            if (!euler[j])
                euler[j]=j;
            euler[j]=euler[j]/i*(i-1);
        }
    }
    for (int i=1;i<MAX;i++)
        euler[i]+=euler[i-1];
}
int main()
{
    init();
    int n,m;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        printf("%lld\n",euler[m]-euler[n-1]);
    }
    return 0;
}
