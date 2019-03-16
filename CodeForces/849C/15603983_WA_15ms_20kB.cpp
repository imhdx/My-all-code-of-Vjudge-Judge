#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<26;i++)
    {
        if (n==0) break;
        int pos=0;
        for (int j=0;j<1000;j++)
        {
            if (n-j*(j-1)/2<0)
            {
                pos=j-1;
                n=n-pos*(pos-1)/2;
                break;
            }
        }
        for (int j=0;j<pos;j++) printf("%c",i+'a');
    }
    printf("\n");
    return 0;
}
