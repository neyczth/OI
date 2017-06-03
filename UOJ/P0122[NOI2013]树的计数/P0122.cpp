//UOJ P0122 [NOI2013]树的计数 
#include <cstdio>
#include <iostream>
using namespace std;
int b[2000005]={0},d[2000005]={0},dd[2000005]={0},bb[2000005]={0},qs[2000005]={0},ceng[2000005]={0},last[2000005]={0},fa[2000005]={0};//qs[i]("前s")是s[i]的前缀和. 
double s[2000005]={0};
bool vst[2000005]={0};//s[i]表示BFS序列中第i个数与第i+1个数是否同层. 
int main(){
	int N,x;
	double ans=0;
	cin>>N;
	for(int i=1; i<=N; i++){
		cin>>x;
		d[i]=x;
		dd[x]=i;
		}
	for(int i=1; i<=N; i++){
		cin>>x;
		b[i]=x;
		bb[x]=i;
		}
	s[1]=1;//约束1: 根节点与下一个节点必不同层. 
	for(int i=2; i<N; i++) if(dd[b[i]]>dd[b[i+1]]) s[i]=1;//约束2: BFS中相邻但在DFS中反向的两个数一定不同层.
	//接下来处理约束3: DFS中相邻的两个数层数至多相差1(原因要知道). 利用前缀和.
	for(int i=1; i<N; i++) qs[i]=qs[i-1]+s[i];//预处理, 得到前缀和.
	for(int i=1; i<N; i++)
		if(bb[d[i+1]]>bb[d[i]]&&qs[bb[d[i+1]]-1]-qs[bb[d[i]]-1]==1)
			for(int j=bb[d[i]]; j<bb[d[i+1]]; j++) vst[j]=1;//至此约束3处理结束.
	for(int i=1; i<N; i++) if(vst[i]==0) s[i]=0.5;//对于无约束的点, 说明多解. 显然这些点对于答案的贡献为0.5.
	for(int i=1; i<N; i++) ans+=s[i];
	ans+=1;
	printf("%.3lf",ans);
	return 0;
	}
