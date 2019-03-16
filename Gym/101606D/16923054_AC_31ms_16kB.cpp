#include<bits/stdc++.h>
using namespace std;
char str[1003];
vector<pair<int,int>> v;
void ssort(char str[])
{
    for (int i=0;str[i];i++)
    {
        int pos=i;
        for (int j=i;str[j];j++)
        {
            if (str[pos]>str[j])
            {
                pos=j;
            }
        }
        if (i!=pos)
        swap(str[i],str[pos]),v.push_back({pos+1,i+1});
    }
}
int main()
{
    scanf("%s",str);
    ssort(str);
    for (int i=v.size()-1;i>=0;i--)
    {
        printf("%d %d\n",v[i].first,v[i].second);
    }
    return 0;
}
