#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    while (n--)
    {
        string s1;
        string s2;
        cin>>s1>>s2;
        int len=s1.length()/2;
        int i;
        for (i=0;i<len;i++)
            printf("%c",s1[i]);
        cout<<s2;
        for (;s1[i];i++)
            printf("%c",s1[i]);
        printf("\n");
    }
    return 0;
}
