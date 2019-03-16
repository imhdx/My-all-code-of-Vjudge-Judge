#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        int ans=-1;
        string aa;
        int n;
        cin>>n;
        int i;
        for (i=0;i<n;i++)
        {
            string str;
            int s;
            cin>>str>>s;
            if (s==0) continue;
            int cnt=0;
            int j=2;
            for(j=2;j*j<=s;j++)
            {
                if(s%j==0)
                {
                    cnt++;
                    while(s%j==0)
                    s/=j;
                }
            }
            if (s!=1) cnt++;
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
