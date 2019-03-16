#include<bits/stdc++.h>
using namespace std;
map<string,int> M;
set<string> K;
string str;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    while (cin>>n)
    {
        M.clear();
        for (int i=0;i<n;i++)
        {
            K.clear();
            cin>>str;
            int len=str.length();
            for (int i=0;i<len;i++)
            {

                for (int j=(1<<len)-1;j>0;j--)
                {
                    string s="";
                    for (int k=0;k<len;k++)
                    {
                        if ((j>>k)&1)
                        {
                            s+=str[(k+i)%len];
                        }
                    }
                    //cout<<s<<endl;
                    if (K.count(s)==0)
                    {
                        M[s]++;
                        K.insert(s);
                    }
                }
            }
        }
        string ans="";

        for (auto i:M)
        {
            if (i.second==n)
            {
                if (ans[0]==0)
                {
                    ans=i.first;
                }
                else if (ans.size()<i.first.size())
                {
                    ans=i.first;
                }
                else if (ans.size()==i.first.size())
                {
                    if (ans>i.first)
                    {
                        ans=i.first;
                    }
                }
            }
        }
        if (ans[0]==0)
            cout<<0<<'\n';
        else
            cout<<ans<<'\n';
    }

    return 0;
}
