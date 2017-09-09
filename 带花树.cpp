#include<bits/stdc++.h>
#define N 505
using namespace std;
int u,v,i,j,k,n,m,to[N*N],la[N*N],h[N],t;
struct Work
{
	int ans,ma[N],st[N],pr[N],f[N],q[N],l,t,v[N],d;
	int lca(int x,int y)
	{
		for(d++;;swap(x,y))if(x)
		{
			if(v[x]==d)return x;
			v[x]=d;
			x=f[pr[ma[x]]];
		}
	}
	void up(int x,int y)
	{
		while(f[x]!=j)
		{
			pr[x]=y;
			if(st[ma[x]]>0)st[q[++t]=ma[x]]=0;
			if(f[x]==x)f[x]=j;
			if(f[ma[x]]==ma[x])f[ma[x]]=j;
			x=pr[y=ma[x]];
		}
	}
	int match(int x)
	{
		int i;
		for(i=1;i<=n;i++)f[i]=i,st[i]=-1;
		q[t=1]=x;
		st[x]=0;
		for(l=1;l<=t;l++)for(i=h[q[l]];i;i=la[i])if(st[to[i]]<0)
		{
			st[to[i]]=1;
			pr[to[i]]=q[l];
			if(!ma[to[i]])
			{
				for(j=q[l],i=to[i];j;j=pr[i=k])k=ma[j],ma[j]=i,ma[i]=j;
				return 1;
			}
			st[q[++t]=ma[to[i]]]=0;
		}
		else if(f[to[i]]!=f[q[l]]&&!st[to[i]])
		{
			j=lca(to[i],q[l]);
			up(to[i],q[l]);
			up(q[l],to[i]);
			for(j=1;j<=n;j++)f[j]=f[f[j]];
		}
		return 0;
	}
	void solve()
	{
		for(i=1;i<=n;i++)ans+=!ma[i]&&match(i);
		cout<<ans<<endl;
		for(i=1;i<=n;i++)printf("%d ",ma[i]);
	}
}x;
void link(int x,int y)
{
	to[++t]=y;
	la[t]=h[x];
	h[x]=t;
}
main()
{
	cin>>n>>m;
	for(i=1;i<=m;i++)scanf("%d%d",&u,&v),link(u,v),link(v,u);
	x.solve();
}

