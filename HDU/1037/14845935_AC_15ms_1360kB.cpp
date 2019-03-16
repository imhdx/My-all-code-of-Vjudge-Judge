#include<bits/stdc++.h>
int main()
{
    int i,j,k;
    while (scanf("%d%d%d",&i,&j,&k)!=EOF)
    {
        if (i<=168)
        {
            printf("CRASH %d\n",i);
            continue;
        }
        if (j<=168)
        {
            printf("CRASH %d\n",j);
            continue;
        }
        if (k<=168)
        {
            printf("CRASH %d\n",k);
            continue;
        }
        printf("NO CRASH\n");
    }
    return 0;
}
