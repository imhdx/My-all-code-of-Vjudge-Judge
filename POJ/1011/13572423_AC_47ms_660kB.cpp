#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int N,stick[100],ans;
bool used[100];
bool dfs(int now_len, int num)
{
    if(num>=N && !now_len)
        return true;
    int last=-1;
    for(int i=N-1;i>=0;--i)
    {
        if(used[i]||stick[i]==last)
            continue;
        used[i]=true;
        if(now_len+stick[i]==ans)
            if(dfs(0, num+1))
                return true;
            else last=stick[i];
        else if(now_len+stick[i]<ans)
            if(dfs(now_len+stick[i], num+1))
                return true;
            else last=stick[i];
        used[i]=false;
        if(now_len==0)
            break;
    }
    return false;
}
int main()
{
    while(scanf("%d",&N)!=EOF&&N)
    {
        memset(used,0,sizeof(used));
        int sum=0;
        for(int i=0;i<N;++i)
        {
            scanf("%d",&stick[i]);
            sum+=stick[i];
        }
        sort(stick,stick+N);
        for(ans=stick[N-1];ans<=sum;++ans)
            if((sum%ans==0)&&dfs(0, 0))
                break;
        printf("%d\n",ans);
    }
    return 0;
}