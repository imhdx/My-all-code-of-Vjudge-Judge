#include<stdio.h>
int i;
int a[1003];
int b[1003];

int main()
{
    int n;
    int q,k;
    int tag=1;
    int mysize;
    while (scanf("%d",&n)!=EOF&&n!=0)
    {
        for (i=0;i<1003;i++) b[i]=0;

        while (scanf("%d",&b[1])!=EOF&&b[1]!=0)
        {
            q=1;
            for (i=2;i<=n;i++)
            scanf("%d",&b[i]);
            mysize=1;
            k=1;
            tag=1;
            for (i=1;i<=n;i++)
            {
                if (mysize!=1&&a[mysize-1]==b[i])
                {
                    mysize--;
                }
                else
                {
                    while (k<=n&&a[mysize-1]!=b[i])
                    {
                        a[mysize]=k;
                        k++;
                        mysize++;
                    }
                    if (a[mysize-1]==b[i]) mysize--;
                    else
                        tag=0;
                }
            }
            if (tag==0) printf("No\n");
            else
                printf("Yes\n");

        }
        printf("\n");
    }
    return 0;
}
