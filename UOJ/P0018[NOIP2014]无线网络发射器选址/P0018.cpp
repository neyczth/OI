//UOJ P0018 [NOIP2014]�������緢����ѡַ
#include <iostream>
using namespace std;
int g[129][129]={0};
int main(){
	int d,n,x,y,k,sum,ans=0,sl=0;
	cin>>d>>n;
	for(int i=1; i<=n; i++){
		cin>>x>>y>>k;
		g[x][y]=k;
		}
	for(int x=0; x<=128; x++){
		for(int y=0; y<=128; y++){
			sum=0;
			for(int i=x-d; i<=x+d; i++)
				for(int j=y-d; j<=y+d; j++)
					if(i>=0&&i<=128&&j>=0&&j<=128) sum+=g[i][j];
			if(sum==ans) sl++;
			else if(sum>ans){
				ans=sum;
				sl=1;
				}
			}
		}
	cout<<sl<<' '<<ans<<endl;
	return 0;
	}
