//Âå¹È U6253 ËÍAKºÃÌâ
#include <cstdio>
int gcd(int x,int y){
	return x%y ? gcd(y,x%y) : y;
	}
int main(){
	int k,x,y;
	scanf("%d",&k);
	for(int x=k+1; x<=2*k; x++){
		if(gcd(x*k,x-k)==x-k){
			y=x*k/(x-k);
			printf("1/%d=1/%d+1/%d\n",k,x,y);
			}
		}
	return 0;
	}
