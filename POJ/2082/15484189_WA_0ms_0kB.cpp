#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<stack>
#include<queue>
#include<cmath>
#include<iostream>
using namespace std;
struct node
{
    int h;
    int w;
    node(int _h=0,int _w=0):h(_h),w(_w){}
};
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        if (n==-1) break;
        int i,j;
        stack<node> s;
        node a;
        int max_area=0;
        for (i=0;i<n;i++)
        {
            scanf("%d%d",&a.w,&a.h);
            if (s.empty()) s.push(node(0,0));
            while (!s.empty())
            {
                //printf("hi\n");
                if (s.top().h>a.h)
                {
                    int ww=s.top().w;
                    max_area=max(max_area,s.top().h*s.top().w);
                    s.pop();
                    a.w+=ww;
                }
                else
                {
                    break;
                }
            }
            s.push(a);
        }
        //printf("123\n");

        while (!s.empty())
        {
            int ww=s.top().w;
            max_area=max(max_area,s.top().h*s.top().w);
            s.pop();
            if (!s.empty()) s.top().w+=ww;
        }
        printf("%d\n",max_area);
        /*
        int total_w=0, cur_area = 0;
        while(!s.empty())
        {
            total_w += s.top().w;
            if((cur_area=total_w*s.top().h)>max_area)
                max_area = cur_area;
            s.pop();
        }
        cout<<max_area<<endl;
        */
    }

    return 0;
}
