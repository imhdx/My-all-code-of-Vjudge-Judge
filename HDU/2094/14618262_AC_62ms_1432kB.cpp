#include<map>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<iostream>

using namespace std;
map<string,int> m;
int pre[2010];
int main()
{
    int n;
    while (cin>>n)
    {
        if (n==0) return 0;
        int i;
        int cnt=1;
        m.clear();
        string a,b;
        for (i=0;i<2010;i++) pre[i]=1;
        for (i=0; i<n; i++)
        {
            cin>>a>>b;
            if (m[a]==0) m[a]=cnt++;
            if (m[b]==0) m[b]=cnt++;
            pre[m[b]]=0;
        }
        int ans=0;
        for (i=1;i<cnt;i++)
        {
            ans+=pre[i];
        }
        if (ans==1) printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
