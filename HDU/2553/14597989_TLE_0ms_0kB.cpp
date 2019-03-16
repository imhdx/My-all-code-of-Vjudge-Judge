#include<stdio.h>
#include<math.h>
#include<cmath>
using namespace std;
int n;
int k;
int book[100];//记录每一行皇后的位置
void quen(int a)
{
    int j;
    int i;
    if (a==n+1)
    {
        k++;
        return ;
    }
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=a-1;j++)
        {
            if (i==book[j]||abs(book[j]-i)==abs(j-a))
        break;
        }
        if (j==a)
        {
            book[a]=i;
            quen(a+1);
        }
    }
}
int main()
{
    while (scanf("%d",&n)!=EOF)
    {
        if (n==0) return 0;
        k=0;
        quen(1);
        printf("%d\n",k);
    }
    return 0;
}
