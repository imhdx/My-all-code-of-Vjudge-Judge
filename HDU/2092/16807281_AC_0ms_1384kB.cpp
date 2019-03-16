#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    while (scanf("%d%d",&a,&b)!=EOF)
    {
        if (a==0&&b==0) return 0;
        int flag=0;
        if ((int)(a+sqrt(a*a-4*b))==(a+sqrt(a*a-4*b))&&(int)(a+sqrt(a*a-4*b))%2==0)
           flag=1;
        else if((int)(a-sqrt(a*a-4*b))==(a-sqrt(a*a-4*b))&&(int)(a-sqrt(a*a-4*b))%2==0)
            flag=1;
        if (flag==1) printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
