//Âå¹È P1359 ×âÓÃÓÎÍ§ SPFA°æ 
#include <cstdio>
#include <queue>
#define INF 999999999
using namespace std;
int g[505][505]={0},dist[505]={0};
bool vst[505]={0};
int main(){
	queue<int> q;
	int N;
	scanf("%d",&N);
	for(int i=1; i<=N; i++)
		for(int j=i+1; j<=N; j++) scanf("%d",&g[i][j]);
	for(int i=2; i<=N; i++) dist[i]=INF;
	q.push(1);
	vst[1]=1;
	while(!q.empty()){
		int p=q.front();
		for(int i=p+1; i<=N; i++){
			if(g[p][i]>0&&dist[p]+g[p][i]<dist[i]){
				dist[i]=dist[p]+g[p][i];
				if(!vst[i]){
					q.push(i);
					vst[i]=1;
					}
				}
			}
		vst[p]=0;
		q.pop();
		}
	printf("%d\n",dist[N]);
	return 0;
	}
