#include<bits/stdc++.h>
using namespace std;
char str[200009];
int n;
int getmin(char *s)///最小表示法
{
    int i=0,j=1,k=0,t;
    while(i<n && j<n && k<n)
    {
        t=s[(i+k)%n]-s[(j+k)%n];
        if (!t) k++;
        else
        {
            if (t>0) i+=k+1;
            else j+=k+1;
            if (i==j) j++;
            k=0;
        }
    }
    return i<j?i:j;
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d %s",&n,str);
        printf("%d\n",getmin(str));
    }
    return 0;
}
