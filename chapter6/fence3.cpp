/*
  ID: wangyu.1
  LANG: C++11
  TASK: fence3
*/
#define TASKNAME "fence3"

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

double dist(double x1,double y1,double x2,double y2)
{
	x2-=x1;
	y2-=y1;
	return sqrt(x2*x2+y2*y2);
}
struct pnt_t
{
	int x,y;
	double dist(double xx,double yy)
	{
		return ::dist(x,y,xx,yy);
	}
};

double my_abs(double a)
{
	if(a<0.0)return -a;
	return a;
}

const double eps=0.000001;
int cmp1(double a,double b)
{
	if(my_abs(a-b)<0.000001)
		return 0;
	else if(a>b) return 1;
	else return -1;
}

struct fence_t
{
	pnt_t a;
	pnt_t b;
	double dist(double x,double y)
	{
		if(a.x==b.x)
		{
			double y_min=min(a.y,b.y);
			double y_max=max(a.y,b.y);
			if(cmp1(y,y_max)==1)
			{
				return ::dist(a.x,y_max,x,y);
			}
			else if(cmp1(y,y_min)==-1)
			{
				return ::dist(a.x,y_min,x,y);
			}
			else
			{
				return abs(x-a.x);
			}
		}
		else
		{
			assert(a.y==b.y);
			double x_min=min(a.x,b.x);
			double x_max=max(a.x,b.x);
			if(cmp1(x,x_max)==1)
			{
				return ::dist(x_max,a.y,x,y);
			}
			else if(cmp1(x,x_min)==-1)
			{
				return ::dist(x_min,a.y,x,y);
			}
			else
			{
				return abs(y-a.y);
			}
		}
	}
};

vector<fence_t> fs;
double d(double x,double y)
{
	double sum=0;
	for(int i=0;i<fs.size();i++)
	{
		sum+=fs[i].dist(x,y);
	}
	return sum;
}
struct ans_t
{
	double x;
	double y;
	double d;
};
vector<ans_t> as;
int cmp2(ans_t &a,ans_t&b)
{
	return a.d<b.d;
}
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif           
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
	    fs.emplace_back();
	    fence_t &f=fs.back();
	    scanf("%d %d %d %d",&f.a.x,&f.a.y,&f.b.x,&f.b.y);
    }
    double best=999999;
    double best_x,best_y;
    for(int i=0;i<=100;i++)
	    for(int j=0;j<=100;j++)
	    {
		    double x=i/1.0;
		    double y=j/1.0;
		    double r=d(x,y);
		    as.emplace_back();
		    as.back().x=x;
		    as.back().y=y;
		    as.back().d=r;
	    }
    sort(as.begin(),as.end(),cmp2);
    for(int idx=0;idx<100;idx++)
    {
	    for(int i=-5;i<=5;i++)
		    for(int j=-5;j<=5;j++)
		    {
			    double x=as[idx].x+i/10.0;
			    double y=as[idx].y+j/10.0;
			    double r=d(x,y);
			    if(r<best)
			    {
				    best=r;
				    best_x=x;
				    best_y=y;
			    }
		    }
    }
    printf("%.1f %.1f %.1f\n",best_x,best_y,best);
    return 0;
}

