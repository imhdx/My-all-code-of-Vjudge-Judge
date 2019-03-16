#include<bits/stdc++.h>
using namespace std;
string str;
int main()
{
    int T;
    int t=1;
    scanf("%d",&T);
    while (T--)
    {
        cin>>str;
        int n=str.size();
        int c1=0;
        int c2=0;
        for (int i=0;i<n-1;i++)
        {
            if (str[i]=='S'&&str[i+1]=='S') c1++;
            else if (str[i+1]=='S') c2++;
        }
        printf("Case %d: %d / %d\n",t++,c1,c2);
    }
    return 0;
}
