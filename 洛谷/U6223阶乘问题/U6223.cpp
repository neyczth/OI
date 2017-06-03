//洛谷 U6223 阶乘问题(加强版)
#include <cstdio>
#include <cmath>
bool is_prime(long long n){
	for(long long i=2; i<=sqrt(n); i++) if(n%i==0) return 0;
	return 1;
	}
int main(){
	int T;
	long long n;
	scanf("%d",&T);
	while(T--){
		scanf("%lld",&n);
		if(n==4) printf("2\n");
		else if(is_prime(n)) printf("%lld\n",n-1);
			else printf("0\n");
		}
	return 0;
	}
