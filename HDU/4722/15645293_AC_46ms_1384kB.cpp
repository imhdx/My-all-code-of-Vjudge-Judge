#include <iostream>
#include<bits/stdc++.h>
using namespace std  ;
long long int f[19][11];//f[i][j]表示第i位是数j时符合条件的数字数量
int digit[19];//digit[i]表示n从右到左第i位是多少
void init()
{

    for (int i=0; i<10; i++)
        f[0][i]=0,f[1][i]=1;
    f[0][0]=1;
    for(int i=2 ; i<=18; i++)
    {
        for(int j=0 ; j<10 ; j++) //枚举第i位
        {
            for (int k=0; k<10; k++)
            {
                f[i][(j+k)%10]+=f[i-1][k];
            }
        }
    }
}
int callen(long long int n)//计算n的长度
{
    int cnt=0 ;
    while(n)
    {
        cnt++ ;
        n/=10 ;
    }
    return cnt ;
}
void caldigit(long long int n,int len)//计算n的digit数组
{
    memset(digit,0,sizeof(digit)) ;
    for(int i=1 ; i<=len ; i++)
    {
        digit[i]=n%10 ;
        n/=10 ;
    }
}
long long solve(long long int n)//计算[0,n]区间满足条件的数字个数
{
    long long int ans=0 ;
    int len=callen(n) ;
    caldigit(n,len) ;
    int sum=0;
    int ss=0;
    for(int i=len ; i>=1 ; i--)
    {

        for(int j=0 ; j<digit[i]; j++)
        {
            sum=ss+j;
            for (int k=0; k<10; k++)
            {
                if ((sum+k)%10==0)
                {
                    //printf("%d %d %d %d\n",sum,i,j,f[i-1][k]);
                    ans+=f[i-1][k];
                }
            }

        }
        ss+=digit[i];
    }
    if (ss%10==0)
        ans++;
    return ans ;
}
int main()
{
    init();
    int T;
    int t=1;
    scanf("%d",&T);
    while (T--)
    {
        long long int n,m;
        scanf("%lld%lld",&n,&m);
        printf("Case #%d: ",t++);
        printf("%lld\n",solve(m)-solve(n-1));
    }
    return 0 ;
}
