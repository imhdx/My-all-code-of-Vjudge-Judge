#include<bits/stdc++.h>
using namespace std;

char str[12][100];
bool f(char s1[],char s2[])
{
    //printf("%s\n%s\n",s1,s2);
    int i=0;
    int j=0;
    while (s1[i]&&s2[j])
    {
        if (s1[i]==s2[j])
        {
            i++;
            j++;
        }
        else
        {
            j++;
        }
    }
    if (s1[i]==0)
    {
        return true;
    }
    return false;
}
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        //getchar();
        scanf("%s",str[0]);
        int len=strlen(str[0]);

        for (int i=1; i<n; i++)
            scanf("%s",str[i]);

        char ans[20]="";
        for (int st=0; st<len; st++)
        {
            for (int i=(1<<len)-1; i>0; i--)
            {
                char ss[20];
                int cnt=0;
                if ((i>>st)&1)
                    ss[cnt++]=str[0][st];
                for (int j=(st+1)%len; j!=st; j=(j+1)%len)
                {
                    if ((i>>j)&1)
                        ss[cnt++]=str[0][j];
                }
                ss[cnt]=0;
                //printf("%s\n",ss);
                int k;
                for (k=1; k<n; k++)
                {
                    int ll1=strlen(ss);
                    int ll2=strlen(str[k]);
                    int flag=0;
                    for (int j=0; j<ll2; j++)
                    {
                        if (j!=0)
                        {
                            str[k][ll2+j-1]=str[k][j-1];
                            str[k][ll2+j]=0;
                        }
                        //puts(str[k]+j);
                        if (f(ss,str[k]+j))
                        {
                            flag=1;
                            break;
                        }

                    }
                    str[k][ll2]=0;
                    if (flag==0)
                        break;
                }
                if (k==n)
                {
                    if (ans[0]==0)
                    {
                        strcpy(ans,ss);
                    }
                    else
                    {
                        if (strlen(ans)<strlen(ss))
                        {
                            strcpy(ans,ss);
                        }
                        else if (strlen(ans)==strlen(ss)&&strcmp(ans,ss)>0)
                        {
                            strcpy(ans,ss);
                        }
                    }
                }

            }
        }
        if (ans[0]==0)
        {
            printf("0\n");
        }
        else
        {
            printf("%s\n",ans);
        }


    }

    return 0;
}
