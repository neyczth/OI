//CodeVS P1081 线段树练习2
#include <cstdio>
using namespace std;
int a[100005]={0};
struct node{
    struct node *lc,*rc;
    int data,flag,left,right;
    node(int l=0,int r=0){
        lc=rc=NULL;
        data=flag=0;
        left=l,right=r;
    }
};
void build(node *now,int l,int r){
    if(l==r){
        now->data=a[l];
        return;
    }
    int mid=(l+r-1)/2;
    now->lc=new node(l,mid);
    build(now->lc,l,mid);
    now->rc=new node(mid+1,r);
    build(now->rc,mid+1,r);
    return;
}
void add(node *now,int l,int r,int x){
    if(now->left>=l&&now->right<=r){
        now->flag+=x;
        return;
    }
    now->lc->flag+=now->flag;
    now->rc->flag+=now->flag;
    now->flag=0;
    int mid=(now->left+now->right-1)/2;
    if(l<=mid) add(now->lc,l,r,x);
    if(r>=mid+1) add(now->rc,l,r,x);
    return;
}
int find(node *now,int sit){
    if(now->left==now->right&&now->left==sit){
        now->data+=now->flag;
        now->flag=0;
        return now->data;
        }
    now->lc->flag+=now->flag;
    now->rc->flag+=now->flag;
    now->flag=0;
    int mid=(now->left+now->right-1)/2;
    if(sit<=mid) return find(now->lc,sit);
    else return find(now->rc,sit);
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int N,Q;
    scanf("%d",&N);
    for(int i=1; i<=N; i++) scanf("%d",&a[i]);
    node *head=new node(1,N);
    build(head,1,N);
    scanf("%d",&Q);
    int x,a,b,c;
    while(Q--){
        scanf("%d",&x);
        if(x==1){
            scanf("%d %d %d",&a,&b,&c);
            add(head,a,b,c);
        }
        else{
            scanf("%d",&a);
            printf("%d\n",find(head,a));
        }
    }
    return 0;
}