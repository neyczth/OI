//Âå¹È U6208 ÎÄÃ÷»éÒö
#include <cstdio>
#include <cstring>
using namespace std;
bool vst[505]={0};
int nu,nv,match[505]={0},g[505][505]={0};
bool dfs(int u){
	for(int v=1; v<=nv; v++)
		if(g[u][v]==1&&vst[v]==0){
			vst[v]=1;
			if(match[v]==0||dfs(match[v])){
				match[v]=u;
				return 1;
				}
			}
	return 0;
	}
int find(){
	int ans=0;
	for(int u=1; u<=nu; u++){
		memset(vst,0,sizeof(vst));
		if(dfs(u)) ans++;
		}
	return ans;
	}
int main(){
	int m,x,y;
	scanf("%d %d %d",&nv,&nu,&m);
	for(int i=1; i<=m; i++){
		scanf("%d %d",&x,&y);
		g[y][x]=1;
		}
	printf("%d\n",find());
	for(int v=1; v<=nv; v++) printf("%d ",match[v]);
	printf("\n");
	return 0;
	}
