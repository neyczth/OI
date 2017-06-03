//Âå¹È P1003 ÆÌµØÌº
#include <cstdio>
struct node{
	int a,b,x,y;
	node(){
		a=0;
		b=0;
		x=0;
		y=0;
		}
	}g[10005];
int main(){
	int N,p,q,i;
	scanf("%d",&N);
	for(i=1; i<=N; i++) scanf("%d %d %d %d",&g[i].a,&g[i].b,&g[i].x,&g[i].y);
	scanf("%d %d",&p,&q);
	for(i=N; i>=1; i--){
		if(p>=g[i].a&&p<=g[i].a+g[i].x&&q>=g[i].b&&q<=g[i].b+g[i].y) break;
		}
	if(i==0) printf("-1\n");
	else printf("%d\n",i);
	return 0;
	}
