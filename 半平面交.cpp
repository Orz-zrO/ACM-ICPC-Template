#include<bits/stdc++.h>
#define N 222222
#define D double
#define O operator
#define R return
#define S(a,b,c,d) b.x-a.x+c.x-d.x!=0
#define G(a,b,c,d) (b.x*a.y-a.x*b.y+c.x*d.y-d.x*c.y)/(b.x-a.x+c.x-d.x)
#define H(a,b,c,d) (b.x*a.y-a.x*b.y+c.x*d.y-d.x*c.y-a.y+b.y-d.y+c.y)/(b.x-a.x+c.x-d.x)
#define I(a,b,c,d) (b.x*a.y-a.x*b.y+c.x*d.y-d.x*c.y)/(a.y-b.y+d.y-c.y)
#define J(a,b,c,d) (b.x*a.y-a.x*b.y+c.x*d.y-d.x*c.y-b.x+a.x-c.x+d.x)/(a.y-b.y+d.y-c.y)
using namespace std;
int n,r,h,i,t;D S,A;
struct P{D x,y;P(){}P(D X,D Y){x=X;y=Y;}P O-(P A){R P(x-A.x,y-A.y);}P O+(P A){R P(x+A.x,y+A.y);}D O*(P A){R x*A.y-y*A.x;}P O*(D A){R P(x*A,y*A);}}p[N];
struct L{P u,v;D A;L(){}L(P x,P y){u=x;v=y-x;A=atan2(v.y,v.x);}P O*(L k){R u+v*((k.v*(u-k.u))/(v*k.v));}bool O<(const L a)const{R A<a.A;}D O^(P a){R (u-a)*v;}}l[N],q[N];
D C(P x,P y,P z){return (x.x-z.x)*(y.y-z.y)-(y.x-z.x)*(x.y-z.y);}
L X(P x,P y){if(C(p[1],p[2],P(y.x,y.y+1))>C(p[i],p[i+1],P(y.x,y.y+1)))swap(x,y);return L(x,y);}
L Y(P x,P y){if(C(p[1],p[2],P(y.x-1,y.y))>C(p[i],p[i+1],P(y.x-1,y.y)))swap(x,y);return L(x,y);}
void W()
{
	for(h=1,r=S=0,sort(l+1,l+t+1),i=1;i<=t;i++)
	{
		while(r>h&&(l[i]^(q[r]*q[r-1]))<=0)r--;
		while(r>h&&(l[i]^(q[h]*q[h+1]))<=0)h++;
		if(r>=h&&l[i].v*q[r].v==0)q[r]=(q[r]^l[i].u)<=0?q[r]:l[i];else q[++r]=l[i];
	}
	while(r>h&&(q[r]^(q[h]*q[h+1]))<=0)h++;
	while(r>h&&(q[h]^(q[r]*q[r-1]))<=0)r--;
	for(q[h-1]=q[r],q[r+1]=q[h],i=h;i<=r;i++)S+=C(q[i-1]*q[i],q[i]*q[i+1],P(0,0));
}
main()
{
	for(cin>>n,i=1;i<=n;i++)scanf("%lf%lf",&p[i].x,&p[i].y);
	for(p[n+1]=p[1],t=n,i=1;i<=n;i++)l[i]=L(p[i],p[i+1]);
	for(W(),A=S,i=2;i<=n;i++)if(S(p[1],p[2],p[i],p[i+1]))l[++t]=X(P(0,G(p[1],p[2],p[i],p[i+1])),P(1,H(p[1],p[2],p[i],p[i+1])));else l[++t]=Y(P(I(p[1],p[2],p[i],p[i+1]),0),P(J(p[1],p[2],p[i],p[i+1]),1));W();printf("%.4lf",S/A);
}
