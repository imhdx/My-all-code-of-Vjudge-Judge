#include<stdio.h>
int n;
int flag=0;
long long int qq;
void dfs(long long int aa)
{
	if (!(aa>=1&&aa<9223372036854775807)) return ;
	if (flag==1) return ;
	if (aa%n==0) {flag=1;qq=aa;return ;}
	dfs(aa*10);
	dfs(aa*10+1);
	return ;
}
int main()
{
	while (scanf("%d",&n)!=EOF)
	{
		if (n==0) break;
		flag=0;
		dfs(1);
		printf("%lld\n",qq);
		
	}
	return 0;
}