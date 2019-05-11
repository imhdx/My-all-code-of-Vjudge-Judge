//
// Created by mhdx on 2019/5/7.
//

#include<bits/stdc++.h>
using namespace std;
const int maxn=10004;
char str1[maxn];
char str2[maxn];
vector<pair<int,int> > v1;
vector<pair<int,int> > v2;
int main()
{
    while (scanf("%s",str1)!=EOF){
        scanf("%s",str2);
        v1.clear();
        v2.clear();
        int c1=0,c2=0;
        for (int i=0;str1[i];i++)
        {
            if (str1[i]=='c') c1++;
        }
        for (int i=0;str2[i];i++)
        {
            if (str2[i]=='c') c2++;
        }
        if (c1!=c2) {
            printf("No\n");
            continue;
        }
        int len1=strlen(str1);
        int len2=strlen(str2);
        int a=0;
        int b=0;
        for (int i=0;i<len1;i++)
        {
            if (str1[i]=='c')
            {
                v1.push_back(make_pair(a,b));
                a=0,b=0;
            }
            else
            {
                if (str1[i]=='a') a++;
                else b++;
            }
        }
        v1.push_back(make_pair(a,b));
        a=0,b=0;
        for (int i=0;i<len2;i++)
        {
            if (str2[i]=='c')
            {
                v2.push_back(make_pair(a,b));
                a=0,b=0;
            }
            else
            {
                if (str2[i]=='a') a++;
                else b++;
            }
        }
        v2.push_back(make_pair(a,b));
        int flag=0;
        for (int i=0;i<v1.size();i++)
        {
            if (abs(v1[i].first-v2[i].first)%2==0
            &&abs(v1[i].second-v2[i].second)%2==0) ;
            else flag=1;
        }
        if (flag==0) printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}