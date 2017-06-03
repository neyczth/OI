//Âå¹È P1111 ÐÞ¸´¹«Â·
#include <iostream>
#include <algorithm>
using namespace std;
struct road{
	int l,r,t;
	road(){
		l=0;
		r=0;
		t=0;
		}
	}a[100005];
int fa[100005]={0};
bool cmp(struct road x,struct road y){
	return x.t<y.t;
	}
int find(int n){
	if(fa[n]==n) return n;
	else{
		fa[n]=find(fa[n]);
		return fa[n];
		}
	}
int main(){
	int N,M,ans=0;
	cin>>N>>M;
	for(int i=1; i<=M; i++) fa[i]=i;
	for(int i=1; i<=M; i++) cin>>a[i].l>>a[i].r>>a[i].t;
	sort(a+1,a+M+1,cmp);
	for(int i=1; i<=M; i++){
		int x=a[i].l,y=a[i].r;
		if(find(x)!=find(y)){
			fa[find(x)]=find(y);
			ans=max(ans,a[i].t);
			}
		}
	for(int i=1; i<=N; i++) fa[i]=find(i);
	for(int i=2; i<=N; i++) if(fa[i]!=fa[1]) ans=-1;
	cout<<ans<<endl;
	return 0;
	}
