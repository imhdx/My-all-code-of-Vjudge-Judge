#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int> mmp;
#define hash nvjdsnnac
int hash(int a[])
{
    int cnt=0;
    for (int i=0;i<6;i++)
    {
        cnt=cnt*10+a[i];
    }
    return cnt;
}
void minstr(int s[])///最小表示法
{
    int n=6;
    int i=0,j=1,k=0,t;
    while(i<n && j<n && k<n)
    {
        t=s[(i+k)%n]-s[(j+k)%n];
        if (!t) k++;
        else
        {
            if (t>0) i+=k+1;
            else j+=k+1;
            if (i==j) j++;
            k=0;
        }
    }
    int pos=i<j?i:j;
    int tmp[10];
    for (int i=0;i<n;i++) tmp[i]=s[(i+pos)%6];
    for (int i=0;i<n;i++) s[i]=tmp[i];
}
int a[10];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<6;j++) scanf("%d",&a[j]);
        minstr(a);
        if (mmp.count(hash(a))!=0) return 0*printf("Twin snowflakes found.\n");
        mmp[hash(a)]=1;
        reverse(a,a+6);
        minstr(a);
        if (mmp.count(hash(a))!=0) return 0*printf("Twin snowflakes found.\n");
        mmp[hash(a)]=1;
    }
    printf("No two snowflakes are alike.\n");
    return 0;
}
