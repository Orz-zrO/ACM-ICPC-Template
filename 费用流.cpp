#include<bits/stdc++.h>
#define N 40010
using namespace std;
int h[N],e[N],g[N],l[N],w[N],t=1,n,m,T=N-1,s[N],S,V[N],d[N],O=1<<30,i,j,x;
void A(int u,int v,int f,int c){e[++t]=v;g[t]=h[u];w[t]=f;l[t]=c;h[u]=t;e[++t]=u;g[t]=h[v];w[t]=0;l[t]=-c;h[v]=t;}
int W(int u,int f){if(u==T){S+=f*d[0];return f;}int i,p=f,t,q;V[u]=1;for(i=h[u];i;i=g[i])if(w[i]&&!V[e[i]])if(t=d[e[i]]+l[i]-d[u],!t){if(q=W(e[i],min(w[i],p)),w[i]-=q,w[i^1]+=q,p-=q,!p)return f;}else s[e[i]]=min(s[e[i]],t);return f-p;}
int C(){int i,t=O;for(i=0;i<=T;i++)if(!V[i])t=min(s[i],t),s[i]=O;for(i=0;i<=T;i++)if(V[i])d[i]+=t;return t!=O;}
main()
{
	for(cin>>n>>m,A(0,T-1,m,0),i=1;i<=n;i++)cin>>x,A(T-1,i,O,0),A(0,i+n,x,0),A(i,T,x,0);
	for(i=1;i<n;i++)for(j=i+1;j<=n;j++)if(cin>>x,~x)A(i+n,j,O,x); 
	do{do{memset(V,0,sizeof(V));}while(W(0,O));}while(C());
	cout<<S;
}
