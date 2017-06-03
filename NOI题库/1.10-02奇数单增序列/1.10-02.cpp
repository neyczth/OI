//NOI题库 1.10-02 奇数单增序列
#include <iostream>
#include <queue>
using namespace std;
int main(){
	priority_queue<int,vector<int>,greater<int> > p;
	int N,x;
	cin>>N;
	while(N--){
		cin>>x;
		if(x%2==1) p.push(x);
		}
	cout<<p.top();
	p.pop();
	while(!p.empty()){
		cout<<','<<p.top();
		p.pop();
		}
	cout<<endl;
	return 0;
	}
