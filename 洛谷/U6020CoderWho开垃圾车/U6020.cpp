//Âå¹È U6020 CoderWho¿ªÀ¬»ø³µ
#include <cstdio>
#include <algorithm>
using namespace std;
struct node{
	int x,y,n,rankx,ranky;
	}s[1005]={0};
int num[1005][1005]={0};
long long sum[1005][1005]={0};
bool cmp1(struct node x,struct node y){
	return x.x<y.x;
	}
bool cmp2(struct node x,struct node y){
	return x.y<y.y;
	}
int main(){
	int N,M,K,x,y,n,numx,numy;
	scanf("%d %d %d",&N,&M,&K);
	for(int i=1; i<=K; i++){
		scanf("%d %d %d",&x,&y,&n);
		s[i].x=x;
		s[i].y=y;
		s[i].n=n;
		}
	sort(s+1,s+K+1,cmp1);
	int rank=1;
	s[1].rankx=1;
	for(int i=2; i<=K; i++){
		if(s[i].x>s[i-1].x) rank++;
		s[i].rankx=rank;
		}
	numx=rank;
	sort(s+1,s+K+1,cmp2);
	rank=1;
	s[1].ranky=1;
	for(int i=2; i<=K; i++){
		if(s[i].y>s[i-1].y) rank++;
		s[i].ranky=rank;
		}
	numy=rank;
	for(int i=1; i<=K; i++)
		num[s[i].rankx][s[i].ranky]=s[i].n;
	for(int i=1; i<=numx; i++)
		for(int j=1; j<=numy; j++)
			sum[i][j]=max(sum[i-1][j],sum[i][j-1])+num[i][j];
	printf("%lld\n",sum[numx][numy]);
	return 0;
	}
