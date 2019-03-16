#include<cstdio>
#include<vector>
using namespace std;
int a[100005][6];
vector<int> v[1000006];
int myhash(int k)
{
    int sum=0;
    int cnt=1;
    for (int i=0;i<6;i++)
    {
        sum+=a[k][i];
        sum%=1000006;
        cnt*=a[k][i];
        cnt%=1000006;
    }
    sum+=cnt;
    sum%=1000006;
    return sum;
}
bool f(int k,int p)
{
    int flag=0;
    for (int i=0;i<6;i++)
    {
        int j=0;
        for (j=0;j<6;j++)
        {
            if (a[k][i]!=a[p][(i+j)%6]) break;
        }
        if (j==6) flag=1;
        for (j=0;j<6;j++)
        {
            if (a[k][i]!=a[p][(i-j+6)%6]) break;
        }
        if (j==6) flag=1;
    }
    if (flag==1) return 0;
    return 1;
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<6;j++) scanf("%d",&a[i][j]);
        int c=myhash(i);
        if (v[c].size()==0) v[c].push_back(i);
        else{
            for (int j=0;j<v[c].size();j++)
            {
                if (f(v[c][j],i))
                {
                    printf("Twin snowflakes found.\n");
                    return 0;
                }
            }
            v[c].push_back(i);
        }
    }
    printf("No two snowflakes are alike.\n");
    return 0;
}
