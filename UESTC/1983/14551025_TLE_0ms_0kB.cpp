#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
#define ull unsigned long long int
ull poww(int a, int b)
{
    ull ans = 1, base = a;
    while (b != 0) {
        if (b & 1 != 0)
            ans *= base;
        base *= base;
        b >>= 1;
    }
    return ans;
}
int main()
{
    int n;
    char s[100010];
    cin>>s;
    cin>>n;
    int i;
    for (i=0;i<n;i++)
    {
        int x;;
        int y;
        cin>>x>>y;
        x--;
        y--;
        ull ans=0;
        int j;
        for (j=x;j<=y;j++)
        {
            ans=ans+(s[j]-'a')*poww(163,y-x-(j-x));
        }
        cout<<ans<<endl;
    }
    return 0;
}
