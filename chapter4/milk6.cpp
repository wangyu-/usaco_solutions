/*
  ID: wangyu.1
  LANG: C++11
  TASK: milk6
*/
#define TASKNAME "milk6"

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
typedef long long ll;
struct max_flow_t  //adapted from sidekicks.cpp
{
    static const int MAXV=1000+10;
    static const ll inf=1000*1000*1000*10000ll;

    struct edge_t
    {
	ll cap=0;
	ll flow=0;	
	ll left(){return cap-flow;}
	vector<int> vec;
    };
    int source=-1,target=-1;
    unordered_map<int,edge_t> e[MAXV];
    vector<int> nbs[MAXV];
    int pre[MAXV];
    unordered_set<int> visited;

    bool dfs_visit(int x) //visit node x, hopping to reach sink
    {
	if (x == target) return true;
	visited.insert(x);
	for (int n : nbs[x]) 
	    if (visited.find(n)==visited.end() && e[x][n].left()>0) 
	    {
		pre[n] = x;
		if (dfs_visit(n)) return true;
	    }
	return false;
    }

    void augment(int n, ll delta) //agument a path
    {
	while (n != source) {
	    e[pre[n]][n].flow += delta;
	    e[n][pre[n]].flow -= delta;
	    n = pre[n];
	}
    }

    ll bottleneck(int n)//find min cap along path
    {
	ll bottle=inf;
	while (n!=source) 
	{
	    bottle=min(bottle,e[pre[n]][n].left());
	    n=pre[n];
	}
	return bottle;
    }
    ll max_flow()
    {
	assert(source!=-1&&target!=-1);
	visited.clear();
	ll total_flow = 0;
	while (dfs_visit(source)) //find a path to sink
	{
	    ll bottle = bottleneck(target); // find the bottleneck of the path
	    total_flow += bottle;
	    augment(target, bottle);// augment the path
	    visited.clear();
	}
	return total_flow;
    }
    void add_edge(int x,int y,ll c,int idx)//direct edge
    {
	if(e[x].find(y)==e[x].end())
	{
	    nbs[x].push_back(y);
	    nbs[y].push_back(x);
	    e[x][y];
	    e[y][x];
	}
	e[x][y].cap+=c;
	e[x][y].vec.push_back(idx);
	//e[y][x].cap+=c;
    }
    void change_cap(int x,int y,ll c)
    {
	e[x][y].cap+=c;
    }
}f;

int n,m;
void clear()
{
    for(int i=1;i<=n;i++)
    {
	for(int j=1;j<=n;j++)
	{
	    f.e[i][j].flow=0;
	}
    }
}

struct e_t
{
    int a,b,c;
};
const ll scale=10000;
vector<e_t> e;
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif
    vector<e_t> e;
    scanf("%d %d",&n,&m);
    f.source=1;
    f.target=n;
    for(int i=1;i<=m;i++)
    {
	int a,b,c;
	e_t tmp;
	scanf("%d %d %d",&a,&b,&c);
	f.add_edge(a,b,c*scale+1,i);
	tmp.a=a;tmp.b=b;tmp.c=c;
	e.push_back(tmp);
    }
    ll mf=f.max_flow();
    printf("%lld ",mf/scale);
    vector<int> vec;
    for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
	    if(f.e[i][j].flow>=1&&f.e[i][j].left()==0)
	    {	
		for(auto x:f.e[i][j].vec)
		    vec.push_back(x);
	    }
	}
    if(test) printf("<<%d>>",(int)vec.size());
    sort(vec.begin(),vec.end());
    vector<int> res;
    for(auto x:vec)
    {
	clear();
	e_t ee=e[x-1];
	f.change_cap(ee.a,ee.b,-(ee.c*scale+1));
	//f.change_cap(ee.a,ee.b,0);
	ll mf2=f.max_flow();
	//if(test) printf("<%d %d %d>",mf,mf2,ee.c*scale+1);
	if(mf2+ee.c*scale+1==mf)
	{
	    res.push_back(x);
	    mf-=ee.c*scale+1;
	}
	else
	{
	f.change_cap(ee.a,ee.b,(ee.c*scale+1));
	}
	if(mf==0) break;
    }
    printf("%d\n",(int)res.size());
    for(int i=0;i<(int)res.size();i++)
    {
	//if(i)printf(" ");
	printf("%d\n",res[i]);
    }
    //if(res.size()) printf("\n");
    return 0;
}

