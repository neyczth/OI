//UOJ P0009 [UTR#1]vfk的数据
#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
int N;
char name[105]={0};
string a[100005];
bool cmp(const string a,const string b){
    if(a.length()<b.length()) return 1;
    if(a.length()>b.length()) return 0;
    return a>b ? 0 : 1;
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&N);
    char ch=' ';
    for(; ch==' '||ch=='\n'; ch=getchar());
    int head=0;
    for(; (ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||(ch=='_'); ch=getchar()) name[head++]=ch;
    for(; ch>='0'&&ch<='9'; ch=getchar()) a[1]=a[1]+ch;
    for(int i=2; i<=N; i++){
        for(; ch!='\n'; ch=getchar());
        for(int j=0; j<=head; j++) ch=getchar();
        for(; ch>='0'&&ch<='9'; ch=getchar()) a[i]=a[i]+ch;
    }
    sort(a+1,a+N+1,cmp);
    for(int i=1; i<=N; i++){
        for(int j=0; j<head; j++) putchar(name[j]);
        cout<<a[i];
        printf(".in\n");
    }
    return 0;
}