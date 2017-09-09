#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;

#define ll long long
ll p[500005],cnt,B[700000],C[700000];
ll l,r,z,a[700000],P[700000],f[700000],g[700000];
bool pr[2000005];
ll solve(ll n){
	if(n==0)return 0;
	for(z=sqrt(n);(z+1)*(z+1)<=n;z++);
	ll m,pn;
	for(m=1;m<=z;m++)a[m]=m;
	if(n/z!=z)a[m++]=n/z;
	for(ll i=z-1;i>0;i--)a[m++]=n/i;
	for(pn=0;p[pn]<=z;pn++);
	for(ll i=1;i<m;i++)P[i]=a[i];
	memset(B,0,sizeof(B));
	for(ll i=0,l=1;i<pn;i++){
		ll q=p[i];
		for(;a[l]<(long long)q*q;l++);
		for(ll j=m-1;j>=l;j--){
			ll t=a[j]/q,x;if(t<=z)x=t;else x=m-n/t;
			P[j]-=P[x]-(i-B[x]);
			B[j]=i+1;
		}
	}
	for(ll i=1;i<=z;i++)P[i]=0;
	for(ll i=z+1;i<m;i++)P[i]-=pn-B[i]+1;
	ll ans=0;
	memset(f,0,sizeof(f));memset(g,0,sizeof(g));memset(C,0,sizeof(C));memset(B,0,sizeof(B));
	f[m-1]=1;
	for(ll i=1,j=0;i<m;i++){
		for(;j<pn && p[j]<=a[i];j++);C[i]=j;
	}
	for(ll i=0,l=1;i<pn;i++){
		ll q;for(q=p[i];a[l]<(long long)q*q;l++);
		for(ll j=m-1;j>=l;j--){
			B[j]=i+1;
			ll t=a[j]/q,x;if(t<=z)x=t;else x=m-n/t;
			if(x<l){
				if(C[x]>=i)ans+=f[j]*q*(C[x]-i);
			}else f[x]+=f[j],g[x]+=f[j]*q;
			ans+=P[x]*f[j]*q+g[j];
		}
	}
	for(ll i=1;i<m;i++)ans+=g[i]*(C[i]-B[i]);
	return ans;
}
int main(){
	scanf("%lld%lld",&l,&r);
	z=800000;
	for(ll i=2;i<=z;i++)if(!pr[i]){
		p[cnt++]=i;
		for(ll j=i+i;j<=z;j+=i)pr[j]=1;
	}
	ll ans=solve(r)-solve(l-1);
	printf("%lld\n",ans);
	return 0;
}

