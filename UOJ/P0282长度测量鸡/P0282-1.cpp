//UOJ P0282 长度测量鸡
#include <cstdio>
using namespace std;
int main(){
    int T,N;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        if(N<=3) printf("1\n");
        else printf("-1\n");
    }
    return 0;
}