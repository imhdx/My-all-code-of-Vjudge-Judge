#include<bits/stdc++.h>
using namespace std;
map<string,int> M;
map<int,int> a;
int main()
{
    M["red"]=1;
    M["yellow"]=2;
    M["green"]=3;
    M["brown"]=4;
    M["blue"]=5;
    M["pink"]=6;
    M["black"]=7;
    int n;
    scanf("%d",&n);
    int ans=0;
    for (int i=0;i<n;i++)
    {
        char str[10];
        scanf("%s",str);
        a[M[str]]++;
    }
    int i;
    for (i=7;i>=2;i--)
    {
        if (a[i]) break;
    }
    if (i>=2)
    {
        int ans=a[1]*(i+1);
        for (int i=2;i<=7;i++)
        {
            ans+=i*a[i];
        }
        printf("%d\n",ans);
    }
    else
    {
        printf("1\n");
    }
    return 0;
}
