#include<bits/stdc++.h>
char f[20];
int k[1000];
int main()
{
    for (int i=0;i<10;i++) f[i]='0'+i;
    for (int i=10;i<20;i++) f[i]=i-10+'A';
    int n,m;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        int kk=abs(n);
        if (n==0)
        {
            printf("0\n");
            continue;
        }
        int len=0;
        while (kk)
        {
            k[len]=kk%m;
            kk=kk/m;
            len++;
        }
        if (n<0) printf("-");
        for (int i=len-1;i>=0;i--)
            printf("%c",f[k[i]]);
        printf("\n");
    }
    return 0;
}
