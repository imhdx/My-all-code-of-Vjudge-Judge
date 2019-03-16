#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;
bool vis[10000007];
bool insert(int a[])
{
    for (int i=0;i<6;i++) a[i]%=131;
    for (int i=0;i<6;i++)
    {
        int sum=0;
        for (int j=0;j<6;j++)
        {
            sum*=10;
            sum+=a[(i+j+6)%6];
            sum%=10000007;
        }
        if (vis[sum]!=0) return 1;
        vis[sum]=1;
        sum=0;
        for (int j=0;j<6;j++)
        {
            sum*=10;
            sum+=a[(i-j+6)%6];
            sum%=10000007;
        }
        if (vis[sum]!=0) return 1;
        vis[sum]=1;
    }
    return 0;
}
int a[10];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        for (int j=0;j<6;j++)
            scanf("%d",&a[j]);
        if (insert(a))
        {
            printf("Twin snowflakes found.\n");
            return 0;
        }
    }
    printf("No two snowflakes are alike.\n");
    return 0;
}
