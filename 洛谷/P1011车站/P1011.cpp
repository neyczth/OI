//Âå¹È P1011 ³µÕ¾
#include <cstdio>
int a1[25]={0},a2[25]={0},b1[25]={0},b2[25]={0};
int main(){
	int a,n,m,x;
	scanf("%d %d %d %d",&a,&n,&m,&x);
	a1[1]=1;
	a2[2]=1;
	b1[1]=1;
	b1[2]=1;
	for(int i=3; i<=n-1; i++){
		a1[i]=a1[i-2]+a1[i-1];
		a2[i]=a2[i-2]+a2[i-1];
		b1[i]=b1[i-1]+a1[i-2];
		b2[i]=b2[i-1]+a2[i-2];
		}
	int k=(m-b1[n-1]*a)/b2[n-1];
	printf("%d\n",b1[x]*a+b2[x]*k);
	return 0;
	}
