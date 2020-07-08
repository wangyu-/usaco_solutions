/*
  ID: wangyu.1
  LANG: C++11
  TASK: window 
*/
#define TASKNAME "window"

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
struct itv_t
{
    int l,r;
};
struct cal_t
{
    itv_t target;
    vector<itv_t> v;
    map<int,int> to_idx;
    map<int,int> idx_to;
    vector<int> lens;
    vector<int> filled;
    void st(int l,int r)
    {
	target.l=l;
	target.r=r;
    }
    void pb(int l,int r)
    {
	v.emplace_back();
	v.back().l=l;
	v.back().r=r;
    }
    void clear()
    {
	v.clear();
	to_idx.clear();
	idx_to.clear();
	lens.clear();
	filled.clear();
    }
    void process()
    {
        to_idx[target.l]=-1;
        to_idx[target.r]=-1;
	for(int i=0;i<v.size();i++)
	{
	    to_idx[v[i].l]=-1;
	    to_idx[v[i].r]=-1;
	}
	int cnt=0;
	for(auto it=to_idx.begin();it!=to_idx.end();it++)
	{
	    it->second=cnt;
	    idx_to[cnt]=it->first;
	    cnt++;
	}	
	lens.resize(to_idx.size()-1);	
	filled.resize(to_idx.size()-1);	
	std::fill(filled.begin(), filled.end(), 0);
	for(int i=0;i<lens.size();i++)
	{
	    lens[i]=idx_to[i+1]-idx_to[i];
	}
    }
    void fill(int l,int r)
    {
	assert(to_idx.find(l)!=to_idx.end());
	assert(to_idx.find(r)!=to_idx.end());
	for(int j=to_idx[l];j<to_idx[r];j++)
	{
	    filled[j]++;
	}
    }
    void unfill(int l,int r)
    {
	assert(to_idx.find(l)!=to_idx.end());
	assert(to_idx.find(r)!=to_idx.end());
	for(int j=to_idx[l];j<to_idx[r];j++)
	{
	    filled[j]--;
	}
    }
    int get_result()
    {
	int sum=0;
	for(int i=to_idx[target.l];i<to_idx[target.r];i++)
	{
	    if(filled[i]==0)
		sum+=lens[i];
	}
	return sum;
    }
};
int top=1;
int down=0;
struct win_t
{
    int u,b;
    int l,r; 
    int layer;
};
map<char,win_t> wins;
struct pnt_t
{
    int x;
    int u,b;
    char type;
    int is_t=0;
};
bool cmp1(pnt_t &a,pnt_t&b)
{
    return a.x<b.x;
}
void query(win_t t,vector<win_t> &v)
{
    cal_t cc;
    cc.st(t.u,t.b);
    for(int i=0;i<v.size();i++)
	cc.pb(v[i].u,v[i].b);
    cc.process();
    pnt_t bg;
    bg.type='s';
    pnt_t ed;
    ed.type='e';
    vector<pnt_t> pnts;
    for(int i=0;i<v.size();i++)
    {
	bg.x=v[i].l;
	bg.u=v[i].u;
	bg.b=v[i].b;
	
	ed.x=v[i].r;
	ed.u=v[i].u;
	ed.b=v[i].b;

	pnts.push_back(bg);
	pnts.push_back(ed);
    }
    bg.x=t.l;bg.u=t.u;bg.b=t.b;bg.is_t=1;
    ed.x=t.r;ed.u=t.u;ed.b=t.b;ed.is_t=1;
    pnts.push_back(bg);
    pnts.push_back(ed);
    sort(pnts.begin(),pnts.end(),cmp1);
    int in_t=0;
    long long sum=0;
    int pre_x=pnts[0].x;
    if(test)printf("<<%d>>",v.size());
    for(int i=0;i<pnts.size();i++)
    {
	pnt_t &p=pnts[i];
	if(test)printf("<%d %d %d %c>",p.x,p.u,p.b,p.type);
	if(p.x!=pre_x)
	{
	    sum+=cc.get_result()*in_t*(p.x-pre_x);
	    pre_x=p.x;
	}
	if(p.is_t)
	{
	    if(p.type=='s') in_t=1;
	    else in_t=0;
	    continue;
	}
	if(p.type=='s')
	{
	    cc.fill(p.u,p.b);
	    if(test) printf("{s,%d}",cc.get_result());
	}
	else
	{
	    cc.unfill(p.u,p.b);
	    if(test) printf("{e,%d}",cc.get_result());
	}
    }
    if(test)printf("%lld/%lld\n",sum,(long long)(t.r-t.l)*(t.b-t.u));
    printf("%.3f\n",100*(double)sum/double((t.r-t.l)*(t.b-t.u) ));
}
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif           
    char s[30];
    while(1)
    {
	if(scanf("%s",s)!=1)
	    break;
	if(s[0]=='w')
	{
	    char id;
	    int x1,y1,x2,y2;
	    sscanf(s,"w(%c,%d,%d,%d,%d)",&id,&x1,&y1,&x2,&y2);
	    win_t &w=wins[id];
	    w.u=min(y1,y2);
	    w.b=max(y1,y2);
	    w.l=min(x1,x2);
	    w.r=max(x1,x2);
	    w.layer=top++;
	}	
	else if(s[0]=='s')
	{
	    char id;
	    sscanf(s,"s(%c)",&id);
	    //wins[id].layer=top++;
	    win_t &w=wins[id];
	    vector<win_t> v;
	    for(auto it=wins.begin();it!=wins.end();it++)
	    {
		if(it->second.layer>w.layer)
		{
		    v.push_back(it->second);
		}
	    }
	    query(w,v);
	}
	else if(s[0]=='t')
	{
	    char id;
	    sscanf(s,"t(%c)",&id);
	    wins[id].layer=top++;
	}
	else if(s[0]=='b')
	{
	    char id;
	    sscanf(s,"b(%c)",&id);
	    wins[id].layer=down--;
	}
	else if(s[0]=='d')
	{
	    char id;
	    sscanf(s,"d(%c)",&id);
	    wins.erase(wins.find(id));
	}
    }

/*    cal_t cc;
    cc.st(10,20);
    cc.pb(15,30);
    cc.pb(14,40);
    cc.pb(9,13);
    int r=cc.cal();
    printf("<%d>",cc.cal());*/
    

    

    return 0;
}

