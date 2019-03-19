#include<stdio.h>
#include<math.h>
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        printf("%.0f\n",pow(2,n));
    }
    return 0;
}
