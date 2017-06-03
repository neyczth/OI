//UOJ P0078 二分图最大匹配
#include <iostream>
#include <cstring>
using namespace std;
bool g[505][505]={0},visited[505]={0};
int match[505]={0},nu,nv;
bool dfs(int u){
	for(int v=1; v<=nv; v++){
		if(g[u][v]==1&&visited[v]==0){
			visited[v]=1;
			if(match[v]==0||dfs(match[v])){
				match[v]=u;
				return 1;
				}
			}
		}
	return 0;
	}
int find(){
	int ans=0;
	for(int u=1; u<=nu; u++){
		memset(visited,0,sizeof(visited));
		if(dfs(u)) ans++;
		}
	return ans;
	}
int main(){
	int m,x,y;
	cin>>nv>>nu>>m;
	while(m--){
		cin>>x>>y;
		g[y][x]=1;
		}
	cout<<find()<<endl;
	for(int v=1; v<=nv; v++) cout<<match[v]<<' ';
	cout<<endl;
	return 0;
	}
