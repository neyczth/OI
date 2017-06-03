//UOJ P0034 多项式乘法
#include <bits/stdc++.h>
using namespace std;
const double pi=acos(-1.0);
typedef complex<double> cd;
cd a[262144]={0},b[262144]={0};
int rev[262144]={0};
void get_rev(int wei){
    rev[1]=wei>>1;
    for(int i=2; i<wei; i++) rev[i]=(rev[i>>1]>>1)|(rev[i&1]);
    return;
}
void fft(cd *a,int wei,int dft){
    for(int i=0; i<wei; i++) if(i>rev[i]) swap(a[i],a[rev[i]]);
    for(int step=1; step<wei; step<<=1){
        cd wn=exp(cd(0,dft*pi/step));
        for(int j=0; j<wei; j+=step<<1){
            cd wnk(1,0);
            for(int k=j; k<j+step; k++){
                cd x=a[k];
                cd y=wnk*a[k+step];
                a[k]=x+y;
                a[k+step]=x-y;
                wnk*=wn;
            }
        }
    }
    if(dft==-1) for(int i=0; i<wei; i++) a[i]/=wei;
    return;
}
int main(){
    freopen("input.txt","r",stdin);
    int N,M;
    scanf("%d %d",&N,&M);
    int x;
    for(int i=0; i<=N; i++) scanf("%d",&x),a[i]=cd(x,0);
    for(int i=0; i<=M; i++) scanf("%d",&x),b[i]=cd(x,0);
    int wei=1;
    while(wei<N+M+1) wei<<=1;
    get_rev(wei);
    fft(a,wei,1);
    fft(b,wei,1);
    for(int i=0; i<wei; i++) a[i]*=b[i];
    fft(a,wei,-1);
    for(int i=0; i<N+M+1; i++) printf("%d ",(int)(a[i].real()+0.5));
    printf("\n");
    return 0;
}