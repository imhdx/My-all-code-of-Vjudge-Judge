#include<bits/stdc++.h>
using namespace std;
char str[200009];
int n;
int ans;
bool cmp(int st,int la)
{
    int flag=0;
    for (int i=0;i<n;i++)
    {
        if (str[st+i]>str[la+i])
        {
            flag=1;
            break;
        }
        else if (str[st+i]<str[la+i])
        {
            flag=-1;
            break;
        }
    }
    if (flag==1)
    {
        ans=la;
    }
    return flag;
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d %s",&n,str);
        ans=0;
        int la=n;
        for (int i=0;i<n;i++)
        {
            cmp(ans,i);
            str[la]=str[i];
            str[++la]='\0';
        }
        printf("%d\n",ans);
    }
    return 0;
}
