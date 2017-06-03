//UOJ P0145 [NOIP2015]ÉñÆæµÄ»Ã·½
#include <iostream>
using namespace std;
int a[40][40]={0};
int main(){
	int N;
	cin>>N;
	int i=1,j=(1+N)/2;
	a[i][j]=1;
	for(int k=2; k<=N*N; k++){
		if(i==1&&j!=N){
			i=N;
			j++;
			a[i][j]=k;
			}
		else if(i!=1&&j==N){
			j=1;
			i--;
			a[i][j]=k;
			}
		else if(i==1&&j==N){
			i
			++;
			a[i][j]=k;
			}
		else{
			if(a[i-1][j+1]==0){
				i--;
				j++;
				a[i][j]=k;
				}
			else{
				i++;
				a[i][j]=k;
				}
			}
		}
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++) cout<<a[i][j]<<' ';
		cout<<endl;
		}
	return 0;
	}
