//CodeVS P2776 Ñ°ÕÒ´ú±íÔª
#include <cstdio>
#include <cstring>
bool g[205][205]={0},vst[205]={0};
int match[205]={0},N,M;
bool dfs(int n){
	for(int m=1; m<=M; m++){
		if(g[n][m]&&!vst[m]){
			vst[m]=1;
			if(!match[m]||(dfs(match[m]))){
				match[m]=n;
				return 1;
				}
			}
		}
	return 0;
	}
int find(){
	int ans=0;
	for(int n=1; n<=N; n++){
		memset(vst,0,sizeof(vst));
		if(dfs(n)) ans++;
		}
	return ans;
	}
int main(){
	int x;
	scanf("%d %d",&N,&M);
	for(int i=1; i<=N; i++){
		scanf("%d",&x);
		while(x!=0){
			g[i][x]=1;
			scanf("%d",&x);
			}
		}
	printf("%d\n",find());
	return 0;
	}
