//Âå¹È P2661 ÐÅÏ¢´«µÝ
#include <cstdio>
#include <algorithm>
using namespace std;
int ru[200005]={0},next[200005]={0};
bool vst[200005]={0};
int main(){
	int N,i,ans=999999999;
	scanf("%d",&N);
	for(int i=1; i<=N; i++){
		scanf("%d",&next[i]);
		ru[next[i]]++;
		}
	while(1){
		for(i=1; i<=N; i++)
			if(ru[i]==0&&vst[i]==0){
				vst[i]=1;
				ru[next[i]]--;
				break;
				}
		if(i==N+1) break;
		}
	while(1){
		for(i=1; i<=N; i++){
			if(vst[i]==0){
				vst[i]=1;
				int q=i,p=1;
				while(next[q]!=i){
					p++;
					q=next[q];
					vst[q]=1;
					}
				ans=min(ans,p);
				break;
				}
			}
		if(i==N+1) break;
		}
	printf("%d\n",ans);
	return 0;
	}
