#include <cstdio>
using namespace std;
char p[10005],s[1000005];
int next[10005]={0};
int readln_str(char *s){
    char ch=' ';
    for(; ch==' '||ch=='\n'; ch=getchar());
    int head=0;
    for(; ch!=' '&&ch!='\n'&&ch!=EOF; ch=getchar()) s[++head]=ch;
    return head;
}
void get_next(char *p,int lenp){
    int k=0;
    for(int i=2; i<=lenp; i++){
        while(k>0&&p[i]!=p[k+1]) k=next[k];
        if(p[i]==p[k+1]) k++;
        next[i]=k;
    }
    return;
}
int find(char *s,int lens,char *p,int lenp){
    get_next(p,lenp);
    int k=0,res=0;
    for(int i=1; i<=lens; i++){
        while(k>0&&s[i]!=p[k+1]) k=next[k];
        if(s[i]==p[k+1]) k++;
        if(k==lenp){
            res++;
            k=next[k];
        }
    }
    return res;
}
int main(){
    freopen("input.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--){
        int lenp=readln_str(p);
        int lens=readln_str(s);
        printf("%d\n",find(s,lens,p,lenp));
    }
    return 0;
}