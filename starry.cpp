/*
  ID: wangyu.1
  LANG: C++11
  TASK: starry
*/
#define TASKNAME "starry"

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
char mp[100+5][100+5];
int W,H;
int nbs[8][2]={{0,1},{1,0},{0,-1},{-1,0},{1,1},{-1,-1},{-1,1},{1,-1}};
struct pnt_t
{
    int r,c; 
    int good()
    {
	if(r>=0&&r<H&&c>=0&&c<W)
	    return 1;
	return 0;
    }
};
bool cmp1(pnt_t &a,pnt_t &b)
{
    if(a.r!=b.r) return a.r<b.r;
    return a.c<b.c;
}
struct cluster_t
{
    int R,C;
    pnt_t start;
    vector<pnt_t> v;
    int id=-1;
    void process()
    {
	start.r=9999;
	start.c=9999;
	for(int i=0;i<(int)v.size();i++)
	{
	    start.r=min(start.r,v[i].r);
	    start.c=min(start.c,v[i].c);
	}
	R=0;C=0;
	for(int i=0;i<(int)v.size();i++)
	{
	    v[i].r-=start.r;
	    v[i].c-=start.c;
	    R=max(R,v[i].r);
	    C=max(C,v[i].c);
	}
	R++;C++;
	sort(v.begin(),v.end(),cmp1);
    }
    void reflection()
    {
	for(int i=0;i<(int)v.size();i++)
	{
	    v[i].c=C-1-v[i].c;
	}
	sort(v.begin(),v.end(),cmp1);
    }
    cluster_t rf()
    {
	cluster_t res=*this;
	res.reflection();
	//res.process();
	return res;
    }
    void rotate_c()
    {
	for(int i=0;i<(int)v.size();i++)
	{
	    pnt_t old=v[i];
	    v[i].c=R-1-old.r;
	    v[i].r=old.c;
	}
	int t=R;
	R=C;C=t;
	sort(v.begin(),v.end(),cmp1);
    }
    cluster_t rc()
    {
	cluster_t res=*this;
	res.rotate_c();
	//res.process();
	return res;
    }
    bool eq(const cluster_t &y)
    {
	if(R!=y.R||C!=y.C)
	{
	    return 0;
	}
	if(v.size()!=y.v.size()) return 0;
	for(int i=0;i<(int)v.size();i++)
	{
	    if(v[i].r!=y.v[i].r) return 0;
	    if(v[i].c!=y.v[i].c) return 0;
	}
	return  1;
    }
    bool eq2(cluster_t y)
    {
	for(int i=0;i<4;i++,y=y.rc())
	{
	    if(this->eq(y)||this->eq(y.rf()))
		return 1;
	}
	return 0;
    }
    void prt()
    {
	if(!test) return;
	//printf("{R=%d,c=%d,",R,C);
	//print
	    
    }
};
vector<cluster_t> cs;
void dfs(pnt_t x,cluster_t &c)
{
    if(!x.good()) return;
    if(mp[x.r][x.c]=='0') return ;
    if(mp[x.r][x.c]=='2') return ;
    mp[x.r][x.c]='2';
    c.v.push_back(x);
    for(int i=0;i<8;i++)
    {
	pnt_t y=x;
	y.r+=nbs[i][0];
	y.c+=nbs[i][1];
	dfs(y,c);
    }
}
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif
    scanf("%d %d",&W,&H);
    for(int i=0;i<H;i++)
    {
	scanf("%s",mp[i]);
    }
    cluster_t c;
    for(int i=0;i<H;i++)
    {
	for(int j=0;j<W;j++)
	{
	    if(mp[i][j]=='1')
	    {
		c.v.clear();
		pnt_t x;
		x.r=i;
		x.c=j;
		dfs(x,c);
		cs.push_back(c);
		cs[cs.size()-1].process();
	    }
	}
    }
    int cnt=0;
    for(int i=0;i<cs.size();i++)
    {
	cluster_t &x=cs[i];
	if(x.id!=-1) 
	    continue;
	x.id=cnt++;
	for(int j=i+1;j<cs.size();j++)
	{
	    cluster_t &y=cs[j];
	    if(y.id!=-1)
		continue;
	    if(x.eq2(y))
	    {
		y.id=x.id;
	    }
	}
    }
    for(int i=0;i<cs.size();i++)
    {
	cluster_t &x=cs[i];
	for(int j=0;j<x.v.size();j++)
	{
	    mp[x.start.r+x.v[j].r][x.start.c+x.v[j].c]='a'+x.id;
	}
	if(test)
	{
	    for(int j=0;j<x.v.size();j++)
	    {
		printf("<%d,%d>",x.v[j].r,x.v[j].c);
	    }
	    printf("\n");
	    cluster_t y=x.rf();
	    for(int j=0;j<y.v.size();j++)
	    {
		printf("<%d,%d>",y.v[j].r,y.v[j].c);
	    }
	    printf("\n");
	}
		    
    }
    if(test) printf("-------\n");
    for(int i=0;i<H;i++)
    {
	printf("%s\n",mp[i]);
    }
    

    return 0;
}

