#include<bits/stdc++.h>

using namespace std;
map<string,int> m;
set<pair<int,string>> s;
int main()
{
    m.clear();
    s.clear();
    int n;
    cin>>n;
    int i;
    for (i=0;i<n;i++)
    {
        int flag;
        cin>>flag;
        switch(flag)
        {
        case 1:
            {
                string str;
                int pri;
                cin>>str>>pri;
                if (m[str]!=0) break;
                m[str]=pri;
                s.insert(make_pair(pri,str));
                break;
            }
        case 2:
            {
                string str;
                cin>>str;
                if (m[str]==0) break;
                s.erase(make_pair(m[str],str));
                m[str]=0;
                break;
            }
        case 3:
            {
                string str;
                int pri;
                cin>>str>>pri;
                if (m[str]==0)
                    break;
                s.erase(make_pair(m[str],str));
                m[str]=pri;
                s.insert(make_pair(m[str],str));
                break;
            }
        case 4:
            {
                int pri;
                cin>>pri;
                if (s.empty()) break;
                if (pri==1)
                {
                    cout<<s.begin()->second<<endl;
                }
                else if (pri==2)
                {
                    cout<<s.rbegin()->second<<endl;
                }
                break;
            }
        }
    }

    return 0;
}
