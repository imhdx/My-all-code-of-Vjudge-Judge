#include<stdio.h>
#include<string.h>
using namespace std;
long long int dp[20][10];
int digit[20];
void init()
{
    //十位加个位dp，百位加十位dp，千位加百位dp
    dp[0][0]=1;
    for(int i=1;i<=20;i++)
    {
        for(int j=0;j<10;j++)//枚举第i位数上的数字、
        {
            for(int k=0;k<10;k++)//枚举第i-1位上的数字、
            {
                if(!(j==4&&k==9))//满足条件
                dp[i][j]+=dp[i-1][k];
            }
        }
    }
}
int calchangdu(long long int n)
{
    int cont=0;
    while(n)
    {
        cont++;
        n/=10;
    }
    return cont;
}
int caldigit(long long int n,int len)
{
    memset(digit,0,sizeof(digit));
    for(int i=1;i<=len;i++)
    {
        digit[i]=n%10;
        n/=10;
    }
}
long long solve(long long int n)//计算[0,n)符合条件的个数
{
     long long int ans=0;
     int len=calchangdu(n);
     caldigit(n,len);
     for(int i=len;i>=1;i--)//从最高位开始枚举
     {
         for(int j=0;j<digit[i];j++)
         {
             if(!(j==9&&digit[i+1]==4))
             {
                 ans+=dp[i][j];
             }
         }
         if (digit[i+1]==4&&digit[i]==9) break;
     }
     return ans;
}
int main()
{
    init();
    long long m;
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%lld",&m);
        printf("%lld\n",m+1-solve(m+1));
    }
}
