//RQNOJ P0341 –«√≈Ã¯‘æ
#include <cstdio>
#include <queue>
#define INF 999999999
using namespace std;
int g[10005][10005]={0},dist[30005]={0};
bool vst[30005]={0};
int main(){
	queue<int> q;
	int N,M,x,y,z;
	scanf("%d %d",&N,&M);
	for(int i=1; i<=M; i++){
		scanf("%d %d %d",&x,&y,&z);
		g[x][y]=z;
		g[y][x]=z;
		}
	for(int i=2; i<=N; i++) dist[i]=INF;
	q.push(1);
	vst[1]=1;
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
	printf("%d\n",dist[N]);
	return 0;
	}
