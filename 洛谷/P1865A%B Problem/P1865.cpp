//Ве№И P1865 A%B Problem
#include <iostream>
using namespace std;
bool prime[1000005]={0};
int M,sum[1000005]={0};
void find(){
	prime[0]=1;
	prime[1]=1;
	for(int i=2; i<=M; i++)
		if(prime[i]==0){
			int S=i;
			while(S+i<=M){
				S+=i;
				prime[S]=1;
				}
			}
	return;
	}
int main(){
	int N,l,r;
	cin>>N>>M;
	find();
	for(int i=2; i<=M; i++)  prime[i]==0 ? sum[i]=sum[i-1]+1 : sum[i]=sum[i-1];
	while(N--){
		cin>>l>>r;
		if(l<1||r>M) cout<<"Crossing the line"<<endl;
		else cout<<sum[r]-sum[l-1]<<endl;
		}
	return 0;
	}
