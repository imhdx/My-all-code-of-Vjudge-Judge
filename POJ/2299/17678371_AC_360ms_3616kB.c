#include<stdio.h>
int a[500005];
int temp[500005];
int n,i,j;
long long int sum;
void merge(int s1,int e1,int s2,int e2)
{
    int p=0;
    int ss1=s1,ss2=s2;
    while(ss1<=e1&&ss2<=e2)
    {
        if(a[ss1]<=a[ss2])
            temp[p++]=a[ss1++];
        else
        {

            sum+=e1-ss1+1;
            temp[p++]=a[ss2++];
        }
    }
    while(ss1<=e1)
        temp[p++]=a[ss1++];
    while(ss2<=e2)
        temp[p++]=a[ss2++];
   // int i;
    for(j=0;j<p;j++)
        a[j+s1]=temp[j];
}
void sort(int st,int la)
{
    if(st<la)
    {
        int mid=(st+la)/2;
        sort(st,mid);
        sort(mid+1,la);
        merge(st,mid,mid+1,la);
    }
}
int main()
{
    while(scanf("%d",&n))
    {
        if(n==0)
            break;

        sum=0;
       // int i;
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);

        sort(0,n-1);
        printf("%lld\n",sum);
    }
    return 0;
}
