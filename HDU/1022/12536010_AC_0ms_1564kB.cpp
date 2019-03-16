#include<stdio.h>
#include<string.h>
#include<stack>
using namespace std;
int k,n,i,j,flag[100];
char str1[20],str2[20];
stack <char> s;
int main()
{

    while(scanf("%d%s%s",&n,str1,str2)!=EOF)
    {
        while(!s.empty())
            s.pop();

        memset(flag,-1,sizeof(flag));
        j=0;
        k=0;;
        for(i=0;i< n;i++)
        {
            s.push(str1[i]);
            flag[k++] = 1;
            while(!s.empty())
            {
                if (s.top()==str2[j])
                {   flag[k++]=0;
                    j++;
                    s.pop();
                }
                else
                    break;
            }
        }
        if(j==n)
        {
            printf("Yes.\n");
            for(i=0;i<k;i++)
            {
                if(flag[i])
                    printf("in\n");
                else
                    printf("out\n");
            }
        }
        else
            printf("No.\n");
        printf("FINISH\n");
    }
    return 0;
}