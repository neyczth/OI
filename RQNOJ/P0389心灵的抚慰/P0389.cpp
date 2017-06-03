#include <cstdio>
#include <queue>
#define INF 999999999 
using namespace std;
int g[255][255]={0},dist[255]={0};
bool vst[255]={0};
int main(){
	queue<int> q;
	int N,M,x,y,t;
	scanf("%d %d",&N,&M);
	for(int i=1; i<=M; i++){
		scanf("%d %d %d",&x,&y,&t);
		g[x][y]=t;
		}
	for(int i=2; i<=N; i++) dist[i]=INF;
	vst[1]=1;
	q.push(1);
	while(!q.empty()){
		int p=q.front();
		for(int i=1; i<=N; i++)
			if(g[p][i]&&dist[p]+g[p][i]<dist[i]){
				dist[i]=dist[p]+g[p][i];
				if(!vst[i]){
					q.push(i);
					vst[i]=1;
					}
				}
		vst[p]=0;
		q.pop();
		}
	int minans=INF;
	for(int i=2; i<=N; i++) if(g[i][1]&&dist[i]+g[i][1]<minans) minans=dist[i]+g[i][1];
	if(minans==INF) printf("He will never come back.\n");
	else printf("%d\n",minans);
	return 0;
	}
