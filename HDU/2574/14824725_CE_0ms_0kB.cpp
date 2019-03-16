#include<bits/stdc++.h>
using namespace std;
map<int,string> mp;
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int i;
        for (i=0;i<n;i++)
        {
            string str;
            int s;
            cin>>str>>s;
            mp[s]=str;
        }
        cout<<mp.rbegin()->second<,endl;
    }


    return 0;
}
