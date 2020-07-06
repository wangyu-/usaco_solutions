/*
  ID: wangyu.1
  LANG: C++11
  TASK: picture 
*/
#define TASKNAME "picture"

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
    vector<itv_t> v;
    map<int,int> to_idx;
    map<int,int> idx_to;
    vector<int> lens;
    vector<int> filled;
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
	for(int i=0;i<(int)to_idx.size()-1;i++)
	{
	    if(filled[i]!=0)
		sum+=lens[i];
	}
	return sum;
    }
};
int myabs(int a)
{
    return a>=0?a:-a;
}
int top=1;
int down=0;
struct win_t
{
    int u,b;
    int l,r; 
//    int layer;
};
struct pnt_t
{
    int x;
    int u,b;
    char type;
};
bool cmp1(pnt_t &a,pnt_t&b)
{
    if(a.x==b.x)
    {
	return a.type>b.type;
    }
    return a.x<b.x;
}
long long query(vector<win_t> &v)
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
	
	ed.x=v[i].r;
	ed.u=v[i].u;
	ed.b=v[i].b;

	pnts.push_back(bg);
	pnts.push_back(ed);
    }
    sort(pnts.begin(),pnts.end(),cmp1);
    long long sum=0;
    int pre_x=pnts[0].x;
    if(test)printf("<<%d>>",v.size());
    vector<int> ans;
    ans.push_back(cc.get_result());
    for(int i=0;i<pnts.size();i++)
    {
	pnt_t &p=pnts[i];
	if(test)printf("<%d %d %d %c>\n",p.x,p.u,p.b,p.type);
	
	/*if(p.x!=pre_x)
	{
	    //sum+=cc.get_result()*(p.x-pre_x);
            ans.push_back(cc.get_result());
	    pre_x=p.x;
	}
	*/
	int r1,r2;
	r1=cc.get_result();
	if(test)printf("<r1=%d>",r1);
	if(p.type=='s')
	{
	    cc.fill(p.u,p.b);
	    //if(test) printf("{s,%d}",cc.get_result());
	}
	else
	{
	    cc.unfill(p.u,p.b);
	    //if(test) printf("{e,%d}",cc.get_result());
	}
	r2=cc.get_result();
	//if(test)printf("<r2=%d>\n",r2);
	sum+=myabs(r2-r1);
    }
    /*ans.push_back(cc.get_result());
    ans.push_back(0);
    for(int i=1;i<ans.size();i++)
    {
	sum+=abs(ans[i]-ans[i-1]);
    }
    */

    //if(test)printf("%lld/%lld\n",sum,(long long)(t.r-t.l)*(t.b-t.u));
    //printf("%.3f\n",100*(double)sum/double((t.r-t.l)*(t.b-t.u) ));
    //return sum;
    if(test)printf("%lld\n",sum);
    return sum;
}
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif           
    vector<win_t> v;
    vector<win_t> v2;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
	    int x1,y1,x2,y2;
	    scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
	    win_t w;
	    w.u=min(y1,y2);
	    w.b=max(y1,y2);
	    w.l=min(x1,x2);
	    w.r=max(x1,x2);
	    v.push_back(w);
	    swap(w.u,w.l);
	    swap(w.b,w.r);
	    v2.push_back(w);
    }
    long long ans1=query(v); 
    long long ans2=query(v2); 
    printf("%lld\n",ans1+ans2);

    return 0;
}

