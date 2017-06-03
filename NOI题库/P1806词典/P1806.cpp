//NOIÃ‚ø‚ P1806 ¥ µ‰
#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
int main(){
	map<string,string> g;
	char ch;
	string x;
	while(getline(cin,x)&&x.size()){
		string a,b;
		a=x.substr(0,x.find(' '));
		b=x.substr(x.find(' ')+1);
		g[b]=a;
		}
	while(getline(cin,x)&&x.size()){
		if(g.count(x)) cout<<g[x]<<endl;
		else cout<<"eh"<<endl;
		}
	return 0;
	}
