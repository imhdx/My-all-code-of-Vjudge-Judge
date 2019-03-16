#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,num[205][66],t;
    int len;
    char a[333];
    for (i=0;i<205;i++)
        for (j=0;j<66;j++) num[i][j]=0;
    num[1][0]=1;
    num[2][0]=2;
    for (i=3;i<201;i++)
    {
        for (j=0;j+1<66;j++)
        {
            t=num[i][j]+num[i-1][j]+num[i-2][j];
            num[i][j]=t%10;
            num[i][j+1]=num[i][j+1]+t/10;
        }
    }
    scanf("%d",&t);
    getchar();
    while (t--)
    {
        gets(a);
        len=strlen(a);
        for (j=65;j>=0;j--)
            if (num[len][j]!=0) break;
        for (;j>=0;j--)
            printf("%d",num[len][j]);
        printf("\n");

    }
    return 0;
}
