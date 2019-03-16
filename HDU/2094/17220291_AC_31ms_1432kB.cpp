#include<bits/stdc++.h>
using namespace std;
map<string,int> M;
bool vis[1010];
int main()
{
	int n;
	while (scanf("%d",&n)!=EOF)
	{
		if (n==0) return 0;
		int cnt=1;
		M.clear();
		memset(vis,0,sizeof(vis));
		char str1[100],str2[100];
		for (int i=0;i<n;i++)
		{
			scanf("%s%s",str1,str2);
			if (M[str1]==0) M[str1]=cnt++;
			if (M[str2]==0) M[str2]=cnt++;
			vis[M[str2]]=1;
		}
		int flag=0;
		for (int i=1;i<cnt;i++)
		{
			if (vis[i]==0) flag++;
		}
		if (flag==1) printf("Yes\n");
		else
		printf("No\n");
	}
	
	return 0;
}