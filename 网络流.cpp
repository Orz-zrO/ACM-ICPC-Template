#include<bits/stdc++.h>
#define N 20010
using namespace std;
int T,h[N],l[N],e[N],c[N],v[N],f[N],t=1,O=1<<30,n,i,x,y,s,I[N];
void A(int x,int y,int z){e[++t]=y,l[t]=h[x],h[x]=t,c[t]=z;e[++t]=x,l[t]=h[y],h[y]=t,c[t]=0;}
int S(int x,int F)
{
	if(x==T)return F;
	int r=0,t,i;
	for(i=h[x];i;i=l[i])if(c[i]&&f[x]==f[e[i]]+1)if(t=S(e[i],min(F-r,c[i])),c[i]-=t,c[i^1]+=t,(r+=t)>=F||f[0]>T)return r;
	if(!--v[f[x]])f[0]=T+1;++v[++f[x]];
	return r;
}
main()
{
	for(cin>>n,T=n+3,A(T-1,T-2,O),i=1;i<=n;i++)for(cin>>x;x--;)cin>>y,A(i,y,O),I[i]--,I[y]++;
	for(i=1;i<=n;A(T-2,i,O),A(i,T-1,O),i++)if(I[i]>0)A(0,i,I[i]);else A(i,T,-I[i]);
	while(f[0]<=T)S(0,O);
	for(i=h[0];i;i=l[i])c[i]=c[i^1]=0;
	for(i=h[T];i;i=l[i])c[i]=c[i^1]=0;
	for(i=h[T-1];i;i=l[i])if(e[i]==T-2)s=c[i^1],c[i]=c[i^1]=0;
	A(0,T-1,O);A(T-2,T,O);memset(v,0,sizeof(v));memset(f,0,sizeof(f));
	while(f[0]<=T)s-=S(0,O);
	cout<<s;
}
