#include <cstdio>
#include <algorithm>
using namespace std;
long long a[200005]={0};
struct node{
    node *lc,*rc;
    long long data,flag,left,right;
    node(long long l=0,long long r=0){
        lc=rc=NULL;
        data=flag=0;
        left=l;
        right=r;
    }
};
void build(node *now,long long l,long long r){
    if(l==r){
        now->data=a[l];
        return;
    }
    long long mid=(l+r-1)/2;
    now->lc=new node(l,mid);
    build(now->lc,l,mid);
    now->rc=new node(mid+1,r);
    build(now->rc,mid+1,r);
    now->data=now->lc->data+now->rc->data;
    return;
}
void add(node *now,long long l,long long r,long long x){
    if(now->left>=l&&now->right<=r){
        now->flag+=x;
        return;
    }
    now->lc->flag+=now->flag;
    now->lc->data+=now->flag*(now->lc->right-now->lc->left+1);
    now->lc->data+=min(now->lc->right,r)-max(l,now->lc->left)+1>0 ? x*(min(now->lc->right,r)-max(l,now->lc->left)+1) : 0;
    now->rc->flag+=now->flag;
    now->rc->data+=min(now->rc->right,r)-max(l,now->rc->left)+1>0 ? x*(min(now->rc->right,r)-max(l,now->rc->left)+1) : 0;
    now->rc->data+=now->flag*(now->rc->right-now->rc->left+1);
    now->flag=0;
    long long mid=(now->left+now->right-1)/2;
    if(l<=mid) add(now->lc,l,r,x);
    if(mid+1<=r) add(now->rc,l,r,x);
    return;
}
long long find(node *now,long long l,long long r){
    if(now->left>=l&&now->right<=r) return now->data;
    now->lc->flag+=now->flag;
    now->lc->data+=now->flag*(now->lc->right-now->lc->left+1);
    now->rc->flag+=now->flag;
    now->rc->data+=now->flag*(now->rc->right-now->rc->left+1);
    now->flag=0;
    long long mid=(now->left+now->right-1)/2;
    long long res=0;
    if(l<=mid) res+=find(now->lc,l,r);
    if(mid+1<=r) res+=find(now->rc,l,r);
    return res;
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    long long N,Q;
    scanf("%lld",&N);
    for(long long i=1; i<=N; i++) scanf("%lld",&a[i]);
    node *head=new node(1,N);
    build(head,1,N);
    scanf("%lld",&Q);
    long long x,a,b,c;
    while(Q--){
        scanf("%d",&x);
        if(x==0){
            scanf("%lld %lld %lld",&a,&b,&c);
            head->data+=c*(b-a+1);
            add(head,a,b,c);
        }
        else{
            scanf("%lld %lld",&a,&b);
            printf("%lld\n",find(head,a,b));
        }
    }
    return 0;
}