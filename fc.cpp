/*
  ID: wangyu.1
  LANG: C++11
  TASK: fc
*/
#define TASKNAME "fc"

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
using namespace std;

#ifdef TEST
int test=1;
#else
int test=0;
#endif
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
struct pnt_t
{
    double x,y;
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
    void prt()
    {
	if(test) printf("{%f,%f}",x,y);
    }
};

pnt_t min_y_l;
bool cmp1(const pnt_t &a,const pnt_t &b)
{
    if(cmp(a.y,b.y)==0) return cmp(a.x,b.y)<0;
    else return cmp(a.y,b.y)<0;
}
bool equal1(const pnt_t &a,const pnt_t &b)
{
    return cmp(a.x,b.x)==0&&cmp(a.y,b.y)==0;
}
bool cmp2(pnt_t &a,pnt_t &b)
{
    double cross=a.minus(min_y_l).cross(b.minus(min_y_l));
    if (cmp(cross,0)==0)
    {
	return cmp(a.dis(min_y_l),b.dis(min_y_l))>0;
    }
    else return cmp(cross,0)>0;
	      
}
bool equal2(pnt_t &a,pnt_t &b)
{
    double cross=a.minus(min_y_l).cross(b.minus(min_y_l));
    return cmp(cross,0)==0;
}
void cn(vector<pnt_t> in,vector<pnt_t> &out)
{
    out.clear();
    if(in.size()==0) return ;
    sort(in.begin(),in.end(),cmp1);
    auto it=unique(in.begin(),in.end(),equal1);
    in.erase(it,in.end());
    min_y_l=in[0];
    in.erase(in.begin());
    sort(in.begin(),in.end(),cmp2);
    it=unique(in.begin(),in.end(),equal2);
    in.erase(it,in.end());
    out.push_back(min_y_l);
    if(in.size()<=2)
    {
	for(auto x:in)
	    out.push_back(x);
	return ;
    }
    out.push_back(in[0]);
    out.push_back(in[1]);
    for(int i=2;i<(int)in.size();i++)
    {
	while(1)
	{
	    int top=out.size()-1;
	    assert(top>=1);
	    double cross=out[top].minus(out[top-1]).cross(in[i].minus(out[top-1]));
	    if(cmp(cross,0)<=0)
		out.pop_back();
	    else
		break;	    
	}
	out.push_back(in[i]);
    }
}
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif
    int n;
    vector<pnt_t> in,out;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
	pnt_t tmp;
	scanf("%lf %lf",&tmp.x,&tmp.y);
	in.push_back(tmp);
    }
    cn(in,out);
    double sum=0;
    for(int i=0;i<(int)out.size();i++)
    {
	sum+=out[i].dis(out[(i+1)%out.size()]);
    }
    for(auto x:out)
	x.prt();
    printf("%.2f\n",sum);


    return 0;
}

