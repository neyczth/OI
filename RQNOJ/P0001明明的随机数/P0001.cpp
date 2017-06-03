//RQNOJ P0001 明明的随机数 
#include <cstdio>
#include <algorithm>
using namespace std;
int a[105]={0},b[105]={0};
int main(){
	int N,k=0;
	scanf("%d",&N);
	for(int i=1; i<=N; i++) scanf("%d",&a[i]);
	sort(a+1,a+N+1);
	for(int i=1; i<=N; i++)
		if(a[i]!=a[i-1]){
			k++;
			b[k]=a[i];
			}
	printf("%d\n",k);
	for(int i=1; i<=k; i++) printf("%d ",b[i]);
	printf("\n");
	return 0;
	}
