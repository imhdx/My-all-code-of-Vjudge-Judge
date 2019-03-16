#include<bits/stdc++.h>
using namespace std;
string str;
bool check(int l,int r)
{
    while (l<r)
    {
        if (str[l++]!=str[r--])
            return false;
    }
    return true;
}
int f[1010];
int main()
{
    int n;
    cin>>n;
    while (n--)
    {
        cin>>str;
        int i,j;
        f[0]=1;
        for (i=0;str[i];i++)
        {
            int k=999999;
            for (j=0;j<=i;j++)
            {
                if (check(j,i))
                {
                    if (j==0)
                        k=min(k,1);
                    else
                        k=min(k,f[j-1]+1);
                }
            }
            f[i]=k;
        }
        printf("%d\n",f[i-1]);
    }

    return 0;
}
