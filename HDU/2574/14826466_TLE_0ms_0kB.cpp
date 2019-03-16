#include<bits/stdc++.h>
using namespace std;
bool prim[1000000];
int main()
{
    int i,j;
    for (i=2;i<1000000;i++)
    {
        if (prim[i]==0)
        {
            for (j=2;1LL*i*j<1000000;j++)
                prim[i*j]=1;
        }
    }
    int t;
    cin>>t;
    while (t--)
    {
        int ans=0;
        string aa;
        int n;
        cin>>n;
        int i;
        for (i=0;i<n;i++)
        {
            string str;
            int s;
            cin>>str>>s;
            int cnt=0;
            int j=2;
            while (j<s)
            {
                if (prim[j]==0)
                {
                    if (s%j==0)
                    {
                        cnt++;
                        while (s%j!=0)
                        {
                            s=s/j;
                        }
                        j++;
                    }
                    else
                        j++;
                }
                else j++;
            }
            if (ans<cnt)
            {
                ans=cnt;
                aa=str;
            }
            else if(ans==cnt)
            {
                aa=aa<=str?aa:str;
            }
        }
        cout<<aa<<endl;
    }
    return 0;
}
