//POJ P3041 Asteroids
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
bool g[505][505]={0},visited[505]={0};
int match[505]={0},N;
bool dfs(int u){
	for(int v=1; v<=N; v++){
		if(g[u][v]==1&&visited[v]==0){
			visited[v]=1;
			if(match[v]==-1||dfs(match[v])){
				match[v]=u;
				return 1;
				}
			}
		}
	return 0;
	}
int maxmatch(){
	int ans=0;
	memset(match,-1,sizeof(match));
	for(int u=1; u<=N; u++){
		memset(visited,0,sizeof(visited));
		if(dfs(u)) ans++;
		}
	return ans;
	}
int main(){
	int K,x,y;
	cin>>N>>K;
	for(int i=1; i<=K; i++){
		cin>>x>>y;
		g[x][y]=1;
		}
	cout<<maxmatch()<<endl;
	return 0;
	}
