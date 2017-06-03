//CodeVS P1021 ÂêÀö¿¨
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct node{
	int l,r;
	node(){
		l=0;
		r=0;
		}
	}s[1005];
int g[1005][1005]={0},dist[1005]={0},fa[1005]={0};
bool vst[1005]={0};
int main(){
	int N,M,x,y,v,ans=0;
	scanf("%d %d",&N,&M);
	for(int i=1; i<=M; i++){
		scanf("%d %d %d",&x,&y,&v);
		g[x][y]=v;
		g[y][x]=v;
		}
	memset(dist,-1,sizeof(dist));
	dist[1]=0;
	while(1){
		int v=0;
		for(int i=1; i<=N; i++) if(!vst[i]&&dist[i]!=-1&&(!v||dist[i]<dist[v])) v=i;
		if(v==0) break;
		vst[v]=1;
		for(int i=1; i<=N; i++) if(g[v][i]&&(dist[i]==-1||dist[v]+g[v][i]<dist[i])){
			fa[i]=v;
			dist[i]=dist[v]+g[v][i];
			}
		}
	int k=N,t=0;
	while(k!=1){
		t++;
		s[t].l=fa[k];
		s[t].r=k;
		k=fa[k];
		}
	for(int i=1; i<=t; i++){
		int temp=g[s[i].l][s[i].r];
		g[s[i].l][s[i].r]=0;
		memset(vst,0,sizeof(vst));
		memset(dist,-1,sizeof(dist));
		dist[1]=0;
		while(1){
			int v=0;
			for(int i=1; i<=N; i++) if(!vst[i]&&dist[i]!=-1&&(!v||dist[i]<dist[v])) v=i;
			if(v==0) break;
			vst[v]=1;
			for(int i=1; i<=N; i++) if(g[v][i]&&(dist[i]==-1||dist[v]+g[v][i]<dist[i])){
				fa[i]=v;
				dist[i]=dist[v]+g[v][i];
				}
			}
		ans=max(ans,dist[N]);
		g[s[i].l][s[i].r]+=temp;
		}
	printf("%d\n",ans);
	return 0;
	}
