#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>

using namespace std;
struct node
{
    int h;
    int w;
};
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        if (n==-1) break;
        stack<node> s;
        node chu;
        chu.h=chu.w=0;
        s.push(chu);
        int max_area=0;
        int ws=0;
        while (n--)
        {
            int hh,ww;
            scanf("%d%d",&ww,&hh);
            if (hh>s.top().h)
            {
                chu.h=hh;
                chu.w=ww;
                s.push(chu);
            }
            else
            {
                ws=0;
                while (hh<=s.top().h)
                {
                    chu=s.top();
                    s.pop();
                    ws+=chu.w;
                    max_area=max(max_area,chu.h*ws);
                }
                ww+=ws;
                chu.h=hh;
                chu.w=ww;
                s.push(chu);
            }
        }
        ws=0;
        while (!s.empty())
        {
            chu=s.top();
            s.pop();
            ws+=chu.w;
            max_area=max(max_area,ws*chu.h);
        }
        printf("%d\n",max_area);
    }

    return 0;
}
