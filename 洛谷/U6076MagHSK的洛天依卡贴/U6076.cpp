//Âå¹È U6076 MagHSKµÄÂåÌìÒÀ¿¨Ìù
#include <cstdio>
using namespace std;
long long gcd(long long x,long long y){
	return x%y ? gcd(y,x%y) : y;
	}
long long lcm(long long x,long long y){
	return x*y/gcd(x,y);
	}
int main(){
	int T;
	long long a,b,c,d,p,fz1,fz2,fm,ans;
	scanf("%d",&T);
	while(T--){
		scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
		p=gcd(a,b);
		a/=p;
		b/=p;
		p=gcd(c,d);
		c/=p;
		d/=p;
		fz1=a*d;
		fz2=b*c;
		ans=lcm(fz1,fz2);
		fm=b*d;
		p=gcd(ans,fm);
		ans/=p;
		fm/=p;
		if(fm==1) printf("%lld\n",ans);
		else printf("%lld/%lld\n",ans,fm);
		}
	return 0;
	}
