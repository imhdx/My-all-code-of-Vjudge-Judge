#include<bits/stdc++.h>
using namespace std;
bool prim(int n)
{
    if (n<2) return false;
    for (int i=2;i<=(int)sqrt(n);i++)
    {
        if (n%i==0) return false;
    }
    return true;
}
int main()
{
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
                if (prim(j))
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
