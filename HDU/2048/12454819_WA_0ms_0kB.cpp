#include<stdio.h>
int main()
{
    long long int a[21],jie[21];
    int i;
    jie[1]=1;
    for (i=2;i<21;i++)
        jie[i]=i*jie[i-1];
    a[2]=1;
    a[3]=2;
    for (i=4;i<21;i++)
        a[i]=(i-1)*(a[i-1]+a[i-2]);
    while (scanf("%d",&i)!=EOF)
    {
        printf("%.2f%%\n",100.00000*(double)a[i]/(double)jie[i]);
    }
    return 0;
}
