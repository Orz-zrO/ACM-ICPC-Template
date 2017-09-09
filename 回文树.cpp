#include<bits/stdc++.h>
#define N 100010
using namespace std;
int T,n,i,x,y,S,a[N][4],f[N],r[N],F[N],l[N],L,t,q[N],h;
char s[N];
int G(int x){while(s[i-l[x]-1]!=s[i])x=f[x];return x;}
void A(int w){if(x=G(L),!a[x][w]){if(l[t]=l[x]+2,f[t]=a[G(f[x])][w],l[t]<3)r[t]=f[t];else{y=r[x];while(s[i-l[y]-1]!=s[i]||l[y]*2+4>l[t])y=f[y];r[t]=a[y][w];}a[x][w]=t++;}L=a[x][w];}
main()
{
	for(cin>>T,s[0]='#';T--;cout<<S<<endl)
	{
		for(memset(a,0,sizeof(a)),scanf("%s",s+1),S=n=strlen(s+1),f[0]=1,l[1]=-1,L=0,t=2,i=1;i<=n;i++)A(s[i]=='A'?1:s[i]=='T'?2:s[i]=='C'?3:0);
		for(i=2;i<t;i++)if(l[i]&1)F[i]=l[i];F[q[0]=h=t=0]=1;
		while(h<=t)for(x=q[h++],i=0;i<4;i++)if(a[x][i])F[y=a[x][i]]=F[x]+1,F[y]=min(F[y],l[y]/2-l[r[y]]+F[r[y]]+1),S=min(S,n-l[y]+F[y]),q[++t]=y;
	}
}
