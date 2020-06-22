/*
  ID: wangyu.1
  LANG: C++11
  TASK: fence9
*/
#define TASKNAME "fence9"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <string>
#include <math.h>
using namespace std;

#ifdef TEST
int test=1;
#else
int test=0;
#endif

char in[30];
char pre[30];

typedef long long ll;
int sign(ll a)
{
    assert(a!=0);
    if(a>0) return 1;
    return -1;
}
struct pnt_t
{
    ll x;
    ll y;

    pnt_t add(pnt_t b)
	{
	    pnt_t res;
	    res.x=x+b.x;
	    res.y=y+b.y; 
	    return res;
	}
    pnt_t sub(pnt_t b)
	{
	    pnt_t res;
	    res.x=x-b.x;
	    res.y=y-b.y;
	    return res;
	}
    ll cross(pnt_t b)
	{
	    return x*b.y-y*b.x;
	}
    
};
struct line_t
{
    pnt_t u;
    pnt_t v;
    ll side(pnt_t a)
	{
	    ll r=v.sub(u).cross(a.sub(u));
	    //printf("[%lld]",r);
	    return r;
	}
    int on(pnt_t a)
	{
	    return side(a)==0;
	}
    int same_side(pnt_t a,pnt_t b)
	{
	    return sign(side(a))==sign(side(b));
	}
};
pnt_t o,m1;
pnt_t p1,p2;
line_t l1,l2;
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif
    int n,m,p;
    scanf("%d %d %d",&n,&m,&p);
    o.x=0;o.y=0;
    m1.x=-1;m1.y=1;
    p1.x=n;p1.y=m;
    p2.x=p;p2.y=0;
    l1.u=o;
    l1.v=p1;
    l2.u=p1;
    l2.v=p2;

    ll sum1=0;
    int hi=0;
    for(int i=0;i<=n;i++)
    {
	pnt_t tmp;
	tmp.x=i;
	tmp.y=hi;
	for(;;tmp.y++)
	{
	    //printf("<<%lld>>",tmp.y);
	    if(l1.on(tmp))
	    {
		if(test)printf("<break1>");
		break;
	    }
	    if(l1.same_side(tmp,m1))
	    {
		//if(test)printf("<break2>");
		break;
	    }
	    hi=tmp.y;
	    if(test)printf("[%d]",hi);
	}
	//printf("<i=%d hi=%d>",i,hi);
	sum1+=hi;
    }
    //printf("%lld\n",sum1);
    if(p==n)
    {
	printf("%lld\n",sum1-hi);
	return 0;
    }
    if(p>n)
    {
	pnt_t tt;
	tt.y=0;
	tt.x=p+1;
	hi=0;
	ll sum2=0;
	for(int i=p;i>n;i--)
	{
	    pnt_t tmp;
	    tmp.x=i;
	    tmp.y=hi;
	    for(;;tmp.y++)
	    {
		if(l2.on(tmp))break;
		if(l2.same_side(tt,tmp))break;
		hi=tmp.y;
	    }
	    if(test)printf("[%d]",hi);
	    sum2+=hi;
	}
	if(test)printf("<case2 %lld %lld>\n",sum1,sum2);
	printf("%lld\n",sum1+sum2);
    }
    else
    {
	sum1-=hi;
	pnt_t tt=m1;
	hi=0;
	ll sum2=0;
	for(int i=p;i<n;i++)
	{
	    pnt_t tmp;
	    tmp.x=i;
	    tmp.y=hi;
	    for(;;tmp.y++)
	    {
		if(l2.on(tmp)) goto l1;
		if(l2.same_side(tt,tmp))break;
	l1:
		hi=tmp.y;
	    }
	    sum2+=hi;
	}
	printf("%lld\n",sum1-sum2);		
    }
    return 0;
}

