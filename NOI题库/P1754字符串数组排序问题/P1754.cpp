//NOI题库 P1754 字符串数组排序问题
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
bool sgn(int x){
	return x>0;
	}
bool cmp1(string a,string b){
	string x=a,y=b;
	return sgn(y.compare(x));
	}
bool cmp2(string a,string b){
	string x=a,y=b;
	return sgn(x.compare(y));
	}
bool cmp3(string a,string b){
	string x=a,y=b;
	for(int i=0; i<x.size(); i++) x[i]=tolower(x[i]);
	for(int i=0; i<y.size(); i++) y[i]=tolower(y[i]);
	return sgn(y.compare(x));
	}
bool cmp4(string a,string b){
	string x=a,y=b;
	for(int i=0; i<x.size(); i++) x[i]=tolower(x[i]);
	for(int i=0; i<y.size(); i++) y[i]=tolower(y[i]);
	return sgn(x.compare(y));
	}
int main(){
	vector<string> p;
	map<string,string> an;
	string way,s;
	int n;
	cin>>way;
	cin>>n;
	getline(cin,s);
	for(int i=0; i<n; i++){
		getline(cin,s);
		string al=s;
		string::iterator it=s.begin();
		while(*it==' ') s.erase(it);
		it=s.end()-1;
		while(*it==' ') s.erase(it--);
		p.push_back(s);
		an[s]=al;
		}
	if(way=="inc") sort(p.begin(),p.end(),cmp1);
	else if(way=="dec") sort(p.begin(),p.end(),cmp2);
		else if(way=="ncinc") sort(p.begin(),p.end(),cmp3);
			else if(way=="ncdec") sort(p.begin(),p.end(),cmp4);
	for(vector<string>::iterator it=p.begin(); it!=p.end(); it++) cout<<an[*it]<<endl;
	return 0;
	}
