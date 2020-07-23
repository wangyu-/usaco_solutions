/*
  ID: wangyu.1
  LANG: C++11
  TASK: rect1
*/
#define TASKNAME "rect1"

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
int R,C,N;
int cl_cnt[2500+5]={0};
struct itv_t
{
    int l,r;
};
struct cal_t
{
    vector<itv_t> v;
    map<int,int> to_idx;
    map<int,int> idx_to;
    vector<int> lens;
    vector<map<int,int>> filled;
    void pb(int l,int 
r)
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
	//std::fill(filled.begin(), filled.end(), 0);
	for(int i=0;i<lens.size();i++)
	{
	    lens[i]=idx_to[i+1]-idx_to[i];
	}
    }
    void fill(int l,int r,int layer,int color)
    {
	assert(to_idx.find(l)!=to_idx.end());
	assert(to_idx.find(r)!=to_idx.end());
	for(int j=to_idx[l];j<to_idx[r];j++)
	{
	    filled[j][layer]=color;
	}
    }
    void unfill(int l,int r,int layer)
    {
	assert(to_idx.find(l)!=to_idx.end());
	assert(to_idx.find(r)!=to_idx.end());
	for(int j=to_idx[l];j<to_idx[r];j++)
	{
	    filled[j].erase(filled[j].find(layer));
	}
    }
    void get_result(int times)
    {
	for(int i=0;i<(int)to_idx.size()-1;i++)
	{
	    if(filled[i].empty())
	    {
		//cl_cnt[1]+=times*lens[i];
	    }
	    else
	    {
		auto it=filled[i].end();
		it--;
		cl_cnt[it->second]+=times*lens[i];
	    }
	}
	//return sum;
    }
};
int myabs(int a)
{
    return a>=0?a:-a;
}
struct win_t
{
    int u,b;
    int l,r; 
    int layer;
    int color;
};
struct pnt_t
{
    int x;
    int u,b;
    char type;
    int layer;
    int color;
};
bool cmp1(pnt_t &a,pnt_t&b)
{
    if(a.x==b.x)
    {
	return a.type>b.type;
    
}
    return a.x<b.x;
}
void query(vector<win_t> &v)
{
    cal_t cc;
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
	bg.layer=v[i].layer;
	bg.color=v[i].color;
	
	ed.x=v[i].r;
	ed.u=v[i].u;
	ed.b=v[i].b;
	ed.layer=v[i].layer;
	ed.color=v[i].color;

	pnts.push_back(bg);
	pnts.push_back(ed);
    }
    sort(pnts.begin(),pnts.end(),cmp1);
    long long sum=0;
    int pre_x=pnts[0].x;
    if(test)printf("<<%d>>",v.size());
    for(int i=0;i<pnts.size();i++)
    {
	pnt_t &p=pnts[i];
	if(test)printf("<%d %d %d %c>\n",p.x,p.u,p.b,p.type);
	
	if(p.x!=pre_x)
	{
	    //sum+=cc.get_result()*(p.x-pre_x);
            //ans.push_back(cc.get_result());
	    cc.get_result(p.x-pre_x);
	    pre_x=p.x;
	}
	//r1=cc.get_result();
	//if(test)printf("<r1=%d>",r1);
	if(p.type=='s')
	{
	    cc.fill(p.u,p.b,p.layer,p.color);
	    //if(test) printf("{s,%d}",cc.get_result());
	}
	else
	{
	    cc.unfill(p.u,p.b,p.layer);
	    //if(test) printf("{e,%d}",cc.get_result());
	}
	//r2=cc.get_result();
	//if(test)printf("<r2=%d>\n",r2);
    }
    //if(test)printf("%lld\n",sum);
    //return sum;
}
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif           
    vector<win_t> v;
    scanf("%d %d %d",&C,&R,&N);
    win_t w0;
    w0.u=0; 
    w0.b=R;
    w0.l=0;
    w0.r=C;
    w0.layer=0;
    w0.color=1;
    v.push_back(w0);
    for(int i=0;i<N;i++)
    {
	    int x1,y1,x2,y2;
	    int c;
	    scanf("%d %d %d %d %d",&x1,&y1,&x2,&y2,&c);
	    win_t w;
	    w.color=c;
	    w.layer=i+1;
	    w.u=min(y1,y2);
	    w.b=max(y1,y2);
	    w.l=min(x1,x2);
	    w.r=max(x1,x2);
	    v.push_back(w);
    }
    query(v);
    for(int i=1;i<=2500;i++)
	if(cl_cnt[i])
	    printf("%d %d\n",i,cl_cnt[i]);

    return 0;
}

