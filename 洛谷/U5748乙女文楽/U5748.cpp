//��� U5748 ��Ů�ĘS
#include <cstdio>
int a[1005]={0},b[1005]={0};//a[i]=n��ʾ��i��ǰλ��Ϊn 
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; i++) a[i]=i;
	for(int i=2; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(a[j]%i==1){
				a[j]=a[j]-1+i;
				if(a[j]>n) a[j]=n;
				}
			else a[j]--;
			}
		}
	for(int i=1; i<=n; i++) b[a[i]]=i;
	for(int i=1; i<=n; i++) printf("%d ",b[i]);
	printf("\n");
	return 0;
	}
