#include<bits/stdc++.h>
using namespace std;
int a[120];
int main()
{
    int v;
    scanf("%d",&v);
    int minn=1;
    for (int i=1;i<=9;i++)
    {
        scanf("%d",&a[i]);
        if (a[i]<=a[minn])
        {
            minn=i;
        }
    }
    string s="";
    int wei=v/a[minn];
    for (int i=0;i<wei;i++)
    {
        for (int j=9;j>=1;j--)
        {
            if ((v-a[j])/a[minn]>=wei-i-1)
            {
                v-=a[j];
                s+='0'+j;
                break;
            }
        }
    }
    if (s=="") printf("-1\n");
    else cout<<s<<'\n';
    return 0;
}
