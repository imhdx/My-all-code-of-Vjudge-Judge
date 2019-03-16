#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x;
    int sum=0;
    int i=0;
    while (scanf("%d",&x)!=EOF) sum+=x,i++;
    sum-=i-1;
    printf("%d\n",sum);
    return 0;
}
