#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
# define N 100005
using namespace std;
struct p{double x,y;}a[N],c[N];
bool cmp(p u,p v){return (u.x<v.x) || (u.x==v.x && u.y<v.y);}
int n;
double mx;
double mult(p i,p j,p k){return (j.x-i.x)*(k.y-i.y)-(k.x-i.x)*(j.y-i.y);}
double dis(p i,p j){return sqrt((i.x-j.x)*(i.x-j.x)+(i.y-j.y)*(i.y-j.y));}
double getmin(int l,int r)
{
    double mn=1e20;
    if(l>=r) return mn;
    int m=(l+r)/2,i,j;
    mn=min(mn,min(getmin(l,m),getmin(m+1,r)));
    int ll=m,rr=m+1;
    while(a[ll-1].x>=a[m].x-mn && ll>l) ll--; while(a[rr+1].x<=a[m].x+mn && rr<r) rr++;
    for(i=ll;i<=m;i++) for(j=m+1;j<=rr;j++) mn=min(mn,dis(a[i],a[j]));
    return mn;
}
int main()
{
	int i,j,t,top=1;
	cin>>n;
	for(i=1;i<=n;i++) scanf("%lf%lf",&a[i].x,&a[i].y);
	sort(a+1,a+n+1,cmp);
	c[1]=a[1];
	for(i=2;i<=n;i++)
	{
		while(top>1 && mult(c[top-1],c[top],a[i])<=0) top--;
		c[++top]=a[i];
	}
	t=top;
	for(i=n-1;i>=1;i--)
	{
		while(top>t && mult(c[top-1],c[top],a[i])<=0) top--;
		c[++top]=a[i];
	}
	j=2; top--;
	for(i=1;i<=top;i++) 
	{
		while(mult(c[i+1],c[j+1],c[i])>mult(c[i+1],c[j],c[i])) j=j%top+1;
		mx=max(mx,max(dis(c[i],c[j]),dis(c[i+1],c[j+1])));
	}
	printf("%.2lf %.2lf",getmin(1,n),mx);
	return 0;
}
