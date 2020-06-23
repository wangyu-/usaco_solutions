/*
  ID: wangyu.1
  LANG: C++11
  TASK: stall4 
*/
#define TASKNAME "stall4"

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

struct max_flow_t  //adapted from sidekicks.cpp
{
    static const int MAXV=1000+10;
    static const int inf=1000*1000*1000;

    struct edge_t
    {
	int cap=0;
	int flow=0;	
	int left(){return cap-flow;}
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

    void augment(int n, int delta) //agument a path
    {
	while (n != source) {
	    e[pre[n]][n].flow += delta;
	    e[n][pre[n]].flow -= delta;
	    n = pre[n];
	}
    }

    int bottleneck(int n)//find min cap along path
    {
	int bottle=inf;
	while (n!=source) 
	{
	    bottle=min(bottle,e[pre[n]][n].left());
	    n=pre[n];
	}
	return bottle;
    }
    int max_flow()
    {
	assert(source!=-1&&target!=-1);
	visited.clear();
	int total_flow = 0;
	while (dfs_visit(source)) //find a path to sink
	{
	    int bottle = bottleneck(target); // find the bottleneck of the path
	    total_flow += bottle;
	    augment(target, bottle);// augment the path
	    visited.clear();
	}
	return total_flow;
    }
    void add_edge(int x,int y,int c)//direct edge
    {
	if(e[x].find(y)==e[x].end())
	{
	    nbs[x].push_back(y);
	    nbs[y].push_back(x);
	    e[x][y];
	    e[y][x];
	}
	e[x][y].cap+=c;
	//e[y][x].cap+=c;
    }
}f;

int n,m;
int ln(int x) 
{
    return x;
}
int rn(int y)
{
    return n+y;
}
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif
    scanf("%d %d",&n,&m);
    f.source=0;
    f.target=m+n+1;
    for(int i=1;i<=n;i++)
    {
	int t;
	scanf("%d",&t);
	for(int j=0;j<t;j++)
	{
	    int b;
	    scanf("%d",&b);
	    f.add_edge(i,rn(b),1);
	}
	f.add_edge(0,i,1);
    }
    for(int i=1;i<=m;i++)
	f.add_edge(rn(i),f.target,1);

    int res=f.max_flow();
    printf("%d\n",res);
    return 0;
}

