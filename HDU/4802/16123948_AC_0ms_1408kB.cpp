#include<bits/stdc++.h>
using namespace std;
int a[1020];
double b[1020];
char str[1020][10];
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        for (int i=0;i<n;i++)
        {
            scanf("%d%s",&a[i],str[i]);
            if (strcmp(str[i],"A")==0)
                b[i]=4.0;
            if (strcmp(str[i],"A-")==0)
                b[i]=3.7;
            if (strcmp(str[i],"B+")==0)
                b[i]=3.3;
            if (strcmp(str[i],"B")==0)
                b[i]=3.0;
            if (strcmp(str[i],"B-")==0)
                b[i]=2.7;
            if (strcmp(str[i],"C+")==0)
                b[i]=2.3;
            if (strcmp(str[i],"C")==0)
                b[i]=2.0;
            if (strcmp(str[i],"C-")==0)
                b[i]=1.7;
            if (strcmp(str[i],"D")==0)
                b[i]=1.3;
            if (strcmp(str[i],"D-")==0)
                b[i]=1.0;
            if (strcmp(str[i],"F")==0)
                b[i]=0;
            if (strcmp(str[i],"P")==0||strcmp(str[i],"N")==0)
                b[i]=10.0;
        }
        double ans=0;
        double ans1=0;
        for (int i=0;i<n;i++)
        {
            //printf("%d %f\n",a[i],b[i]);
            if (b[i]!=10.0)
            {
            ans+=(a[i]*b[i]);
            ans1+=a[i];
            }
        }
        if (ans1==0)
            printf("0.00\n");
        else
        {
            ans=ans/ans1;
            printf("%.2f\n",ans);
        }
    }
    return 0;
}
