#include<iostream>
#include<cstdio>
#define N 100005
using namespace std;
int to[2*N],la[2*N],h[N],n,f[N],V[N],s[N],a[N],rt,g[N],i,u,v,sum,T[2*N],t[2*N],Mx,Mn,mx,mn,c[N],tt,rc,l,xx[N];long long ans,ss[N];
void R(int x,int fa){
	s[x]=1;f[x]=0;
	for(int i=h[x];i;i=la[i])if(!V[to[i]]&&to[i]!=fa)R(to[i],x),s[x]+=s[to[i]],f[x]=max(f[x],s[to[i]]);
	f[x]=max(f[x],sum-s[x]);if(f[x]<f[rt])rt=x;}
void B(){Mn=min(Mn,mn),Mx=max(Mx,mx);for(int i=mn;i<=mx;i++)T[i]+=t[i],t[i]=0;mx=-1;mn=200001;}
void C(){for(int i=Mn;i<=Mx;i++)T[i]=0;Mx=-1;Mn=200001;}
void D(int x,int f,int k){
	g[x]+=T[200000-rc-k];t[k]++;mn=min(mn,k);mx=max(mx,k);
	for(int i=h[x];i;i=la[i])if(to[i]!=f&&!V[to[i]])D(to[i],x,k+a[to[i]]);}
void W(int x){
	int i;V[x]=1;tt=0;rc=a[x];
	for(i=h[x];i;i=la[i])if(!V[to[i]])D(to[i],x,100000+a[to[i]]),B(),c[++tt]=to[i];C();T[100000]++;Mx=Mn=100000;
	for(i=tt;i;i--)D(c[i],x,100000+a[c[i]]),B();g[x]+=T[100000-rc];C();
	for(i=h[x];i;i=la[i])if(!V[to[i]])rt=0,sum=s[to[i]],R(to[i],0),W(rt);}
main(){
	cin>>n;for(i=1;i<=n;i++)scanf("%d",&a[i]),a[i]=(a[i]?1:-1);
	for(i=1;i<n;i++)scanf("%d%d",&u,&v),to[2*i-1]=v,la[2*i-1]=h[u],h[u]=2*i-1,to[2*i]=u,la[2*i]=h[v],h[v]=2*i;
	f[0]=sum=n;R(1,0);W(rt);for(i=1;i<=n;i++)scanf("%d",&xx[i]),ss[i]=ss[i-1]+g[xx[i]];l=n;
	for(i=n;i;i--){
		while(l>0&&2*(ss[i]-ss[l-1])<=ss[n])l--;
		ans+=l;}
	cout<<ans;}
