//洛谷 U6203 C'Thun
#include <cstdio>
#include <cstring>
struct node{
	int gjl,xl;
	node(){
		gjl=0;
		xl=0;
		}
	}g[55];
int m,all=0,N,win=0,die[55]={0},gj[55]={0};
int gcd(int x,int y){
	return x%y ? gcd(y,x%y) : y;
	}
void debug(){
	printf("Ans%d:\n",all);
	for(int i=1; i<=N; i++) printf("gj[%d]=%d ",i,gj[i]);
	for(int i=1; i<=m; i++) printf("die[%d]=%d ",i,die[i]);
	printf("win=%d all=%d",win,all);
	printf("\n\n");
	return;
	}
void check(){
	all++;
	for(int i=1; i<=m; i++) if(g[i].xl==0) die[i]++;
	if(g[0].xl==0) {debug();return;}
	if(g[m+1].xl==0){
		win++;
		debug();
		return;
		}
	int sh=0;
	for(int i=1; i<=m; i++) if(g[i].xl>0) sh+=g[i].gjl;
	if(sh<g[0].xl) win++;
	debug();
	return;
	}
void dfs(int n){
	if(n==0) check();
	else{
		for(int i=1; i<=m+1; i++)
			if(g[i].xl>0){
				g[i].xl--;
				gj[N-n+1]=i;
				dfs(n-1);
				gj[N-n+1]=-1;
				g[i].xl++;
				}
		}
	}
int main(){
	freopen("U6203.in","r",stdin);
	int wo,ene;
	scanf("%d %d %d",&N,&wo,&ene);
	scanf("%d",&m);
	memset(gj,-1,sizeof(gj));
	for(int i=1; i<=m; i++) scanf("%d %d",&g[i].gjl,&g[i].xl);
	g[0].xl=wo;
	g[m+1].xl=ene;
	dfs(N);
	for(int i=1; i<=m; i++){
		int gys=gcd(die[i],all);
		int fz=(all-die[i])/gys,fm=all/gys;
		printf("%d/%d\n",fz,fm);
		}
	int gys=gcd(win,all);
	int fz=win/gys,fm=all/gys;
	printf("%d/%d\n",fz,fm);
	return 0;
	}
