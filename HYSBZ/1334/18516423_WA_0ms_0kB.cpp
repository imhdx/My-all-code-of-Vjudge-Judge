#include<bits/stdc++.h>
using namespace std;
int a[100005];
bool cmp(int q,int p){return q>p;}
int main()
{
    int sum=0;
    int n;scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d",&a[i]),sum+=a[i];
    sort(a,a+n,cmp);
    int cnt=0;
    for (int i=0;i<n;i++){
        cnt+=a[i];
        if (2*cnt>sum)
            break;
    }
    printf("%d\n",cnt);
    return 0;
}
