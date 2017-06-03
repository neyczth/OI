//CodeVS P1298 凸包周长
#include <bits/stdc++.h>
using namespace std;
struct point{
    int x,y;
    point(int _x=0,int _y=0){x=_x,y=_y;}
}p[100005];
int st[200005]={0},head_st=0;
bool cmp(const point &a,const point &b){
    if(a.x<b.x) return 1;
    if(a.x>b.x) return 0;
    return a.y<b.y;
}
bool cj(point a,point b,point c){
    point s1(b.x-a.x,b.y-a.y);
    point s2(c.x-b.x,c.y-b.y);
    return s1.x*s2.y-s1.y*s2.x>0;
}
double dist(point a,point b){
    int x=a.x-b.x,y=a.y-b.y;
    return sqrt(x*x+y*y);
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++) scanf("%d %d",&p[i].x,&p[i].y);
    sort(p+1,p+n+1,cmp);
    st[++head_st]=1;
    st[++head_st]=2;
    for(int i=3; i<=n; i++){
        while(head_st>1&&!cj(p[st[head_st-1]],p[st[head_st]],p[i])) head_st--;
        st[++head_st]=i;
    }
    int t=head_st;
    for(int i=n-1; i>=1; i--){
        while(head_st>t&&!cj(p[st[head_st-1]],p[st[head_st]],p[i])) head_st--;
        st[++head_st]=i;
    }
    double ans=0;
    for(int i=1; i<head_st; i++) ans+=dist(p[st[i]],p[st[i+1]]);
    printf("%.1lf\n",ans);
    return 0;
}