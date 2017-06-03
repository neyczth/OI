//Tyvj P3243 快速排序
#include <cstdio>
#include <algorithm>
using namespace std;
int a[100005]={0};
bool cmp(const int &a,const int &b){
    if(a>b) return 1;
    return 0;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1,cmp);
    for(int i=1; i<=n; i++) printf("%d ",a[i]);
    putchar('\n');
    return 0;
}