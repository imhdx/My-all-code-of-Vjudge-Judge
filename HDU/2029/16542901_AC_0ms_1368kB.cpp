#include<bits/stdc++.h>
using namespace std;
int main()
{
    char str[1000];
    int n;
    scanf("%d",&n);
    while (n--)
    {
        scanf("%s",str);
        int i=0;
        int j=strlen(str)-1;
        while (i<j)
        {
            if (str[i]==str[j])
                i++,j--;
            else
                break;
        }
        if (i<j)
            printf("no\n");
        else
            printf("yes\n");
    }
    return 0;
}
