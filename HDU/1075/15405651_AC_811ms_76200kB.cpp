#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<queue>
#include<vector>
#include<stack>
#include<iostream>
#include<map>
#include<set>
#include<cmath>
using namespace std;
map<string,string> m;
char a[5000];
char a1[5001];
char a2[5000];
int main()
{
    int c=0;
    scanf("%s",a);
    while (scanf("%s",a1)!=EOF)
    {
        if (a1[0]=='E') break;
        scanf("%s",a2);
        m[a2]=a1;
    }
    scanf("%s",a);
    getchar();
    while (gets(a)!=NULL)
    {
        if (a[0]=='E') break;
        string k="";
        for (int i=0;a[i];i++)
        {
            if (a[i]>='a'&&a[i]<='z')
            {
                k+=a[i];
            }
            else
            {
                if (m[k]!="")
                    cout<<m[k];
                else
                    cout<<k;
                printf("%c",a[i]);
                k="";
            }
        }
        printf("\n");
    }
    return 0;
}
