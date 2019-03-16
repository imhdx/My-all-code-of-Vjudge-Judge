#include<stdio.h>
int a[100005];
int temp[100005];
int n;
void bing(int s1,int e1,int s2,int e2)
{
    int p=0;
    int ss1=s1,ss2=s2;
    while (ss1<=e1&&ss2<=e2)
    {
        if (a[ss1]<=a[ss2])
            temp[p++]=a[ss1++];
        else
            temp[p++]=a[ss2++];
    }
    while (ss1<=e1)
        temp[p++]=a[ss1++];
    while (ss2<=e2)
        temp[p++]=a[ss2++];
    int i;
    for (i=0;i<p;i++)
        a[i+s1]=temp[i];
}

void sort(int st,int la)
{
    if (st<la)
    {
        int mid=(st+la)/2;
        sort(st,mid);
        sort(mid+1,la);
        bing(st,mid,mid+1,la);
    }
}

int main()
{
    int i=0;
    while (scanf("%d",&temp[i])!=EOF)
    {
        i++;
    }
    sort(0,n-1);
    printf("%d",a[0]);
    for (i=1;i<n;i++)
        printf(" %d",a[i]);
    printf("\n");
    return 0;
}
