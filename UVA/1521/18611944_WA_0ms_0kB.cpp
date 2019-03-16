#include<bits/stdc++.h>
using namespace std;
int a[]={2,3,5,7,11,13,17};
int main()
{
    int n;
    scanf("%d",&n);
    int cnt=0;
    int s=1;
    for (cnt=0;;cnt++){
        s*=a[cnt];
        if (s>=n) break;
    }
    if (n==1) printf("0\n");
    else printf("%d\n",cnt+1);
    return 0;
}
