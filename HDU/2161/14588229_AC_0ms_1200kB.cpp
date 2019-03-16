#include<stdio.h>
#include<math.h>
bool pri(int n)
{
    if (n<=2) return false;
    for (int i=2;i<=(int)sqrt(n);i++)
    {
        if (n%i==0) return false;
    }
    return true;
}
int main()
{
    int n;
    int cnt=1;
    while (scanf("%d",&n)!=EOF)
    {
        if (n<=0) return 0;
        printf("%d: ",cnt++);
        if (pri(n)) printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
