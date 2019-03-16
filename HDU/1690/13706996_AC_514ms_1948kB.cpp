
#include<stdio.h>
#include<string.h>
#include<algorithm>
#define INF 0xffffffffffff
using namespace std;
__int64 dis[101];
__int64 vis[101];
__int64 map[101][101];
__int64 n;
void dijkstra(__int64 s){
	
	memset(vis,0,sizeof(vis));
	
	for(int i=0;i<n;i++){
		dis[i] = INF;
	}
	dis[s] = 0;
	__int64 min = INF;
	int u;
	for(int i=0;i<n-1;i++){
		min = INF;
		for(int j=0;j<n;j++){
			if(!vis[j] && dis[j] < min){
				min = dis[j];
				u = j;
			}
		} 
		if(min == INF){
			break;
		}
		vis[u] = 1;
		for(int j=0;j<n;j++){
			if(dis[j] > dis[u] + map[u][j]){
				dis[j] = dis[u] + map[u][j];
			}
		}
	}
	
}
int main(){
	int t;
	scanf("%d",&t);
	__int64 l1,l2,l3,l4,c1,c2,c3,c4,m;
	for(int q=0;q<t;q++){
		
		scanf("%I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d",&l1,&l2,&l3,&l4,&c1,&c2,&c3,&c4);
		scanf("%I64d %I64d",&n,&m);
		
		__int64 x[501];
		for(int i=0;i<n;i++){
			scanf("%I64d",&x[i]);
		}
		
		int tmp = 0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i == j){
					map[i][j] = 0;
				}else{
					tmp = abs(x[i] - x[j]);
					if(tmp > 0 && tmp <= l1){
						map[i][j] = map[j][i] = c1;
					}else if(tmp > l1 && tmp <= l2){
						map[i][j] = map[j][i] = c2;
					}else if(tmp > l2 && tmp <= l3){
						map[i][j] = map[j][i] = c3;
					}else if(tmp > l3 && tmp <= l4){
						map[i][j] = map[j][i] = c4;
					}else if(tmp > l4){
						map[i][j] = map[j][i] = INF;
					}
				}
			}
		}
		__int64 s,e;
		printf("Case %d:\n",q+1);
		for(int i=0;i<m;i++){
			scanf("%I64d %I64d",&s,&e);
			dijkstra(s-1);
			if(dis[e-1] == INF){
				printf("Station %I64d and station %I64d are not attainable.\n",s,e);
			}else{
				printf("The minimum cost between station %I64d and station %I64d is %I64d.\n",s,e,dis[e-1]);
			}
		}
	}
	return 0;
} 