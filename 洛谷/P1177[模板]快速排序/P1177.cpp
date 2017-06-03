//Âå¹È P1177 [Ä£°å]¿ìËÙÅÅĞò
#include <iostream>
#include <queue>
using namespace std;
int main(){
	int N,x;
	priority_queue<int,vector<int>,greater<int> > q;
	cin>>N;
	for(int i=1; i<=N; i++){
		cin>>x;
		q.push(x);
		}
	while(!q.empty()){
		cout<<q.top()<<' ';
		q.pop();
		}
	cout<<endl;
	return 0;
	}
