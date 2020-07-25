/*
  ID: wangyu.1
  LANG: C++11
  TASK: fence4
*/
#define TASKNAME "fence4"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>
#include <math.h>
#include <typeinfo>
#include <iostream>
using namespace std;

#ifdef TEST
int test=1;
#else
int test=0;
#endif
int n;
const double eps=0.000001;
double my_abs(double a)
{
    return a>=0?a:-a;
}
int eq(double a,double b)
{
    return my_abs(a-b)<eps;
}
int cmp(double a,double b)
{
    if(eq(a,b)) return 0;
    return a<b?-1:1;
}
int zero(double a)
{
	return eq(a,0);
}
struct pnt_t
{
    double x,y;
    int idx=-1;
    pnt_t add(pnt_t b)
    {
	pnt_t res=*this;
	res.x+=b.x;
	res.y+=b.y;
	return res;
    }
    pnt_t minus(pnt_t b)
    {
	pnt_t res=*this;
	res.x-=b.x;
	res.y-=b.y;
	return res;
    }
    double cross(pnt_t b)
    {
	return x*b.y-b.x*y;
    }
    double dis(pnt_t b)
    {
	double xx=x-b.x;
	double yy=y-b.y;
	return sqrt(xx*xx+yy*yy);
    }
    pnt_t div(double a)
    {
	    pnt_t ans=*this;
	    ans.x/=a;
	    ans.y/=a;
	    return ans;
    }
    int eq(pnt_t &other)
    {
	    return ::eq(x,other.x)&&::eq(y,other.y);
    }
    double atan2()
    {
	    return ::atan2(x,y);
    }
    pnt_t normalize()
    {
	    pnt_t o; 
	    o.x=0;o.y=0;
	    double d=dis(o);
	    pnt_t ans=*this;
	    //ans.x/=d;
	    //ans.y/=d;
	    //ans.div(d);
	    return ans.div(d);
    }
    void prt()
    {
	if(test) printf("{%f,%f}",x,y);
    }
}vp;
vector<pnt_t> pnts;
struct fence_t
{
	pnt_t a,b;
	int vis=0;
	int parallel(fence_t other)
	{
		return ::zero(b.minus(a).cross( other.b.minus(other.a) ));
	}
	int open_on(pnt_t c)
	{
		if(a.eq(c)||b.eq(c)) return 0;
		if(!::zero(b.minus(a).cross(c.minus(a)))) return 0;
		return ::eq(c.dis(a)+c.dis(b), b.dis(a));
	}
	int over_lap(fence_t other)
	{
		if(!parallel(other)) return 0;
		if(open_on(other.a)||open_on(other.b)) return 1;
		if(other.open_on(a)||other.open_on(b)) return 1;
		return 0;
	}
	int side(pnt_t c)
	{
		return cmp(b.minus(a).cross(c.minus(a)),0);	
	}
	int intersect(fence_t other)
	{
		if(other.side(a)==0||other.side(b)==0) return 0;
		if(side(other.a)==0||side(other.b)==0) return 0;
		return other.side(a)!=other.side(b) && side(other.a)!=side(other.b);
	}

};

pnt_t intersect(pnt_t a,pnt_t b, pnt_t c,pnt_t d)
{
	pnt_t ans;
	double A1=a.x-c.x;
	double B1=b.x-a.x;
	double C1=c.x-d.x;

	double A2=a.y-c.y;
	double B2=b.y-a.y;
	double C2=c.y-d.y;

	double i=(A1*C2-A2*C1)/(B2*C1-B1*C2);
	double j=(A1*B2-A2*B1)/(C2*B1-C1*B2);
	double j2=(A2+B2*i)/(-C2);
	ans.x=i;
	ans.y=j;
	if(test)
	{
		a.prt();
		b.prt();
		c.prt();
		d.prt();
		printf("\n");
		ans.prt();
		printf("<%f>",j2);
		printf("\n");
		//assert(eq(j,j2));
	}
	return ans;
}
vector<fence_t> fs;
vector<pnt_t> dirs0;
vector<pnt_t> dirs;
int cmp1(pnt_t &a,pnt_t &b)
{
	return cmp(a.atan2(),b.atan2())==-1;
}
int eq1(pnt_t &a,pnt_t &b)
{
	return cmp(a.atan2(),b.atan2())==0;
}
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif           
    //printf("%f\n",atan2(-1,-1));
    scanf("%d",&n);
    scanf("%lf %lf",&vp.x,&vp.y);
    pnts.resize(n);
    for(int i=0;i<n;i++)
    {
	    scanf("%lf %lf",&pnts[i].x,&pnts[i].y);
	    pnts[i].idx=i;
    }
    fs.resize(n);
    for(int i=0;i<n;i++)
    {
	    fs[i].a=pnts[i];
	    fs[i].b=pnts[(i+1)%n];
    }
    for(int i=0;i<n;i++)
	    for(int j=i+1;j<n;j++)
	    {
		    if(pnts[i].eq(pnts[j]))
		    {
			    if(test) printf("<nofence1>");
			    printf("NOFENCE\n");
			    return 0;
		    }
		    if(fs[i].over_lap(fs[j]))
		    {
			    if(test) printf("<nofence2>");
			    printf("NOFENCE\n");
			    return 0;
		    }
	    }
    for(int i=0;i<n;i++)
	    for(int j=0;j<n;j++)
	    {
		    if(fs[j].open_on(pnts[i]))
		    {
			    if(test) printf("<nofence3>");
			    printf("NOFENCE\n");
			    return 0;
		    }
	    }
    for(int i=0;i<n;i++)
	    for(int j=i+1;j<n;j++)
	    {
		    if(fs[i].intersect(fs[j]))
		    {
			    if(test) printf("<nofence4>");
			    printf("NOFENCE\n");
			    return 0;
		    }
	    }
    for(int i=0;i<n;i++)
    {
	    dirs0.push_back(pnts[i].minus(vp).normalize());
    }
    sort(dirs0.begin(),dirs0.end(),cmp1);
    auto it=unique(dirs0.begin(),dirs0.end(),eq1);
    dirs0.erase(it,dirs0.end());
    for(int i=0;i<dirs0.size();i++)
	    dirs0[i].prt();
    if(test) printf("\n");
    dirs.resize(dirs0.size());
    for(int i=0;i<dirs.size();i++)
    {
	    dirs[i]= dirs0[i].add(dirs0[(i+1)%dirs.size()]).div(2).normalize();
    }
    for(int i=0;i<dirs.size();i++)
	    dirs[i].prt();
    if(test) printf("\n");
    for(int i=0;i<dirs.size();i++)
    {
	    double best=9999999;
	    int vis=-1;
	    pnt_t a=vp;
	    pnt_t b=vp.add(dirs[i]);
	    for(int j=0;j<fs.size();j++)
	    {
		    pnt_t ans=intersect(a,b,fs[j].a,fs[j].b);
		    //assert(!zero(ans.x));
		    //assert(!eq(ans.y,0));
		    //assert(!eq(ans.y,1));
		    if(cmp(ans.x,0)==-1) continue;
		    if(cmp(ans.y,0)<=0) continue;
		    if(cmp(ans.y,1)>=0) continue;
		    assert(!eq(ans.x,best));
		    if(ans.x<best)
		    {
			    best=ans.x;
			    vis=j;
		    } 
	    }
	    if(vis!=-1)
	    {
		    fs[vis].vis=1;
	    }
    }
    vector<fence_t> v;
    for(int i=0;i<fs.size();i++)
    {
	    if(fs[i].vis)
	    {
		    v.push_back(fs[i]);
	    }
    }
    printf("%d\n",(int)v.size());
    for(int i=0;i<v.size();i++)
    {
	    if(v[i].a.idx>v[i].b.idx)
	    {
		    auto tmp=v[i].a;
		    v[i].a=v[i].b;
		    v[i].b=tmp;
	    }
    }
    sort(v.begin(),v.end(), [](fence_t &x, fence_t &y) { if(x.b.idx==y.b.idx) return x.a.idx<y.a.idx; else return x.b.idx<y.b.idx;  }     );

    for(int i=0;i<v.size();i++)
    {
	    printf("%.0f %.0f %.0f %.0f\n",v[i].a.x,v[i].a.y,v[i].b.x,v[i].b.y);
    }

    return 0;
}

