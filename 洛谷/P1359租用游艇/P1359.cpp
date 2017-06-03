//Âå¹È P1359 ×âÓÃÓÎÍ§ 
#include <cstdio>
#include <cstring>
int g[205][205]={0},dist[205]={0};
bool vst[205]={0};
int main(){
	int N;
	scanf("%d",&N);
	for(int i=1; i<=N; i++)
		for(int j=i+1; j<=N; j++) scanf("%d",&g[i][j]);
	memset(dist,-1,sizeof(dist));
	dist[1]=0;
	while(1){
		int v=0;
		for(int i=1; i<=N; i++) if(!vst[i]&&dist[i]!=-1&&(!v||dist[i]<dist[v])) v=i;
		if(v==0) break;
		vst[v]=1;
		for(int i=v+1; i<=N; i++) if(g[v][i]&&(dist[i]==-1||dist[v]+g[v][i]<dist[i])) dist[i]=dist[v]+g[v][i];
		}
	printf("%d\n",dist[N]);
	return 0;
	}
