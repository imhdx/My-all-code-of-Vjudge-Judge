#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
    printf("0 1\n1 2\n2 2.5\n3 2.666666667\n4 2.708333333\n");
    double ans=0;
    double cnt=1;
    for (int i=1;i<=9;i++)
    {
        cnt*=i;
        ans+=1/cnt;
        if (i>4)
            printf("%d %.9f\n",i,1+ans);
    }

    return 0;
}
