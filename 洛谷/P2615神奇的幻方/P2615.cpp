//Âå¹È P2615 ÉñÆæµÄ»Ã·½
#include <cstdio>
int a[40][40]={0};
int main(){
	int N;
	scanf("%d",&N);
	int k=1,i=1,j=(N+1)/2;
	a[i][j]=k;
	for(int k=2; k<=N*N; k++){
		if(i==1&&j!=N){
			i=N;
			j++;
			}
		else if(j==N&&i!=1){
			j=1;
			i--;
			}
		else if(i==1&&j==N) i++;
		else{
			if(a[i-1][j+1]==0){
				i--;
				j++;
				}
			else i++;
			}
		a[i][j]=k;
		}
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++) printf("%d ",a[i][j]);
		printf("\n");
		}
	return 0;
	}
