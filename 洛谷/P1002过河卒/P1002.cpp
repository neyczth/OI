//Âå¹È P1002 ¹ýºÓ×ä
#include <iostream>
using namespace std;
int n,m;
long long a[25][25]={0};
bool ma[25][25]={0};
void check(int x,int y){
	if(x>=0&&x<=n&&y>=0&&y<=m) ma[x][y]=1;
	return;
	}
int main(){
	int x,y;
	cin>>n>>m>>x>>y;
	check(x-2,y-1);
	check(x-1,y-2);
	check(x-2,y+1);
	check(x-1,y+2);
	check(x+2,y+1);
	check(x+1,y+2);
	check(x+2,y-1);
	check(x+1,y-2);
	check(x,y);
	a[0][0]=1;
	for(int i=1; i<=m; i++){
		if(ma[0][i]==1) break;
		a[0][i]=1;
		}
	for(int i=1; i<=n; i++){
		if(ma[i][0]==1) break;
		a[i][0]=1;
		}
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			if(ma[i][j]==0) a[i][j]=a[i-1][j]+a[i][j-1];
	cout<<a[n][m]<<endl;
	return 0;
	}
	
