//洛谷 P2299 Mzc和体委的争夺战 
#include <cstdio>
#include <cstring>
int g[10005][10005]={0},dist[10005]={0};
bool vst[10005]={0};
int main(){
	freopen("P2299.in","r",stdin);
	int N,M,x,y,z;
	scanf("%d %d",&N,&M);
	for(int i=1; i<=M; i++){
		scanf("%d %d %d",&x,&y,&z);
		g[x][y]=z;
		g[y][x]=z;
		}
	memset(dist,-1,sizeof(dist));
	dist[1]=0;
	while(1){
		int v=0;
		for(int i=1; i<=N; i++) if(!vst[i]&&dist[i]!=-1&&(!v||dist[i]<dist[v])) v=i;
		if(v==0) break;
		vst[v]=1;
		for(int i=1; i<=N; i++) if(g[v][i]&&(dist[i]==-1||dist[v]+g[v][i]<dist[i])) dist[i]=dist[v]+g[v][i];
		}
	printf("%d\n",dist[N]);
	return 0;
	}
