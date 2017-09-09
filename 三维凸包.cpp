#include<iostream>
#include<cmath>
#include<cstdio>
#define D double
#define N 1005
using namespace std;
D E=1e-6,s;
int n,T,v[N][N],Q;
struct P
{
    D x,y,z;
    P(){}
    P(D X,D Y,D Z){x=X; y=Y; z=Z;}
    P operator-(P t){return P(x-t.x,y-t.y,z-t.z);}
    P operator*(P t){return P(y*t.z-t.y*z,z*t.x-x*t.z,x*t.y-y*t.x);}
    D operator^(P t){return x*t.x+y*t.y+z*t.z;}
}p[N],q;
struct M{int a,b,c,i;}m[N*10],e;
void W(int s,int t);
D V(P x,M y){return ((p[y.a]-x)*(p[y.b]-x))^(p[y.c]-x);}
void S(int x,int t1,int t2)
{
	int t=v[t1][t2];
	if(m[t].i) if(V(p[x],m[t])>E) W(x,t); else e.a=t2,e.b=t1,e.c=x,e.i=1,v[t2][t1]=v[t1][x]=v[x][t2]=++T,m[T]=e;
}
void W(int x,int t){m[t].i=0; S(x,m[t].b,m[t].a); S(x,m[t].a,m[t].c); S(x,m[t].c,m[t].b);}
D L(P x){return sqrt(x^x);}
int main()
{
	int i,j;
	while(1)
	{
		cin>>n; T=0; if(!n) break;
		for(i=0;i<n;i++) cin>>p[i].x>>p[i].y>>p[i].z;
	    for(i=0;i<4;i++)
		{
			e.a=i+1&3,e.b=i+2&3,e.c=i+3&3,e.i=1;
			if(V(p[i],e)>0) swap(e.a,e.b);
			v[e.a][e.b]=v[e.b][e.c]=v[e.c][e.a]=++T; m[T]=e;
		}
		for(i=4;i<n;i++) for(j=0;j<T;j++) if(m[j].i && V(p[i],m[j])>E){W(i,j); break;}
		cin>>Q;
		while(Q--)
		{
			scanf("%lf%lf%lf",&q.x,&q.y,&q.z); s=1e9;
			for(i=T;i;i--) if(m[i].i) s=min(s,fabs(V(q,m[i])/L((p[m[i].b]-p[m[i].a])*(p[m[i].c]-p[m[i].a]))));
			printf("%.4lf\n",s);
	    }
	}
}
