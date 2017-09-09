#include<bits/stdc++.h>
#define N 200010
using namespace std;
int a,c,g,i,n,m,l[N],h[N],f[N],d[N],b[N],s[N],p[N],q,z,L[N],H[N],K[N],G[N],e[N];long long T,S[N],X[N],Y[N];
void D(int x){s[x]=1;for(int i=h[x];i;i=l[i])if(i!=f[x])d[i]=d[x]+1,D(i),s[x]+=s[i];}
void F(int x,int k)
{
	int w=0,i;
	for(p[x]=++m,b[x]=k,i=h[x];i;i=l[i])if(i!=f[x]&&s[i]>s[w])w=i;
	if(w)F(w,k);
	for(i=h[x];i;i=l[i])if(i!=f[x]&&i!=w)F(i,i);
}
void B(int x,int y){while(x)X[x]+=y,x-=x&-x;}
void C(int x,int y){while(x<=n)Y[x]+=y,x+=x&-x;}
void P(int x,int y){while(x<=n)T+=X[x]*y,x+=x&-x;}
void R(int x,int y){while(x)T+=Y[x]*y,x-=x&-x;}
void A(int l,int r){B(r,1);C(r,r);if(l>1)B(l-1,-1),C(l-1,1-l);}
void Q(int l,int r){P(r,r);R(r-1,1);if(l>1)P(l-1,1-l),R(l-2,-1);}
main()
{
	for(cin>>n>>q,i=2;i<=n;i++)scanf("%d",f+i),f[i]++,l[i]=h[f[i]],h[f[i]]=i;
	for(i=1;i<=q;i++)scanf("%d%d%d",&a,&c,&g),a++,c++,g++,e[++z]=i,L[z]=H[a-1],H[a-1]=z,K[z]=-1,e[++z]=i,L[z]=H[c],H[c]=z,K[z]=1,G[z]=G[z-1]=g;
	for(D(1),F(1,1),i=1;i<=n;i++)
	{
		a=i;
		while(a)A(p[b[a]],p[a]),a=f[b[a]];
		for(c=H[i];c;c=L[c])
		{
			a=G[c];T=0;
			while(a)Q(p[b[a]],p[a]),a=f[b[a]];
			S[e[c]]+=T*K[c];
		}
	}
	for(i=1;i<=q;i++)printf("%lld\n",S[i]);
}
