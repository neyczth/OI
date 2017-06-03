//洛谷 P1046 陶陶摘苹果
#include <cstdio>
using namespace std;
int a[11]={0};
int main(){
    int x,ans=0;
    for(int i=1; i<=10; i++) scanf("%d",&a[i]);
    scanf("%d",&x);
    x+=30;
    for(int i=1; i<=10; i++)
        if(a[i]<=x) ans++;
    printf("%d\n",ans);
    return 0;
}