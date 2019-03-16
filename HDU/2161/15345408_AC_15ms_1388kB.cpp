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

bool check[20000];
void init()
{
    int i;
    check[0]=check[1]=1;
    for (i=2;i<20000;i++)
    {
        if (check[i]==0)
        {
            for (long long j=1ll*i*i;j<20000;j=j+i)
                check[j]=1;
        }
    }
}
int main()
{
    init();
    int t=1;
    int n;
    check[2]=1;
    while (scanf("%d",&n)!=EOF&&n>0)
    {
        printf("%d: ",t++);
        if (check[n]==0)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
