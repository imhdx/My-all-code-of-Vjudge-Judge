#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<iostream>
#include<vector>
using namespace std;
struct KMP
{
    const string s;
    vector<int> next;
    KMP(const string &s):s(s),next(s.size()+1,0)
    {
        for(int i=1,j; i<s.size(); ++i)
        {
            for(j=next[i]; j&&s[i]!=s[j]; j=next[j]);
            next[i+1]=s[i]==s[j]?j+1:0;
        }
    }
    int find_in(const string &t)
    {
        int cnt=0;
        for(int i=0,j=0; i<t.size(); ++i)
        {
            for(; j&&s[j]!=t[i]; j=next[j]);
            if(s[j]==t[i])++j;
            if(j==s.size()) cnt++;//不return可得到t中s的所有匹配地址i+1-s.size()
        }
        return cnt;
    }
};
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T;cin>>T;
    while (T--)
    {
        string a;
        cin>>a;
        KMP kmp(a);
        string b;
        cin>>b;
        cout<<kmp.find_in(b)<<'\n';

    }
    return 0;
}
