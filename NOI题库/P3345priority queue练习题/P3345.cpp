//NOI题库 P3345 priority queue练习题
#include <iostream>
#include <queue>
#define MAXN 500000
using namespace std;
bool prime[10000005]={0};
void found_prime(){
	for(int i=2; i<=MAXN; i++) prime[i]=1;
	for(int i=2; i<=MAXN; i++)
		if(prime[i]==1){
			int x=i;
			while(x+i<=MAXN){
				x+=i;
				prime[x]=0;
				}
			}
	return;
	}
int cnt(int n){
	if(prime[n]==1) return 0;
	int ans=0;
	for(int i=2; i<=MAXN; i++)
		if(prime[i]==1&&n%i==0) ans++;
	return ans;
	}
struct cmp1{
	bool operator()(const int &a,const int &b){
		if(cnt(a)>cnt(b)) return 0;
		else if(cnt(a)==cnt(b)){
			if(a>b) return 0;
			}
		return 1;
		}
	};
struct cmp2{
	bool operator()(const int &a,const int &b){
		if(cnt(a)>cnt(b)) return 1;
		else if(cnt(a)==cnt(b)){
			if(a>b) return 1;
			}
		return 0;
		}
	};
int main(){
	priority_queue<int,vector<int>,cmp1> p1;
	priority_queue<int,vector<int>,cmp2> p2;
	int sum,x;
	found_prime();
	cin>>sum;
	for(int i=1; i<=sum; i++){
		for(int j=1; j<=10; j++){
			cin>>x;
			p1.push(x);
			p2.push(x);
			}
		cout<<p1.top()<<' '<<p2.top()<<endl;
		p1.pop();
		p2.pop();
		}
	return 0;
	}
