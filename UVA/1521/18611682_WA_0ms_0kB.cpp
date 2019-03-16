#include<bits/stdc++.h>
using namespace std;
int a[]={2,3,5,7,9};
int main()
{
    int n;
    scanf("%d",&n);
    int cnt=0;
    for (int i=2;i<=n;i++){
        if (n%i==0){
            cnt++;
            while (n%i==0) n/=i;
        }
    }
    if (n!=1) cnt++;
    printf("%d\n",cnt);
    return 0;
}
