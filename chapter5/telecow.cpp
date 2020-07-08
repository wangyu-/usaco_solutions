/*
  ID: wangyu.1
  LANG: C++11
  TASK: telecow 
*/
#define TASKNAME "telecow"

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

struct max_flow_t  //adapted from sidekicks.cpp
{
    static const int MAXV=1000+10;
    static const int inf=1000*1000*1000;

    struct edge_t
    {
	int cap=0;
	int flow=0;	
	int tried=0;
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
	if(x==-1||y==-1) return; // special for this problem
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
int s,t;
void clear()
{
    for(int i=2*1;i<=2*n+1;i++)
    {
	for(int j=2*1;j<=2*n+1;j++)
	{
	    f.e[i][j].flow=0;
	}
    }
}
int in(int x)
{
    if(x==s) return -1;
    return 2*x;
}
int out(int x)
{
    if(x==t) return -1;
    return 2*x+1;
}
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif
    scanf("%d %d %d %d",&n,&m,&s,&t);
    f.source=out(s);
    f.target=in(t);
    for(int i=1;i<=m;i++)
    {
	int a,b;
	scanf("%d %d",&a,&b);
	f.add_edge(out(a),in(b),10000);
	f.add_edge(out(b),in(a),10000);
    }
    for(int i=1;i<=n;i++)
    {
	f.add_edge(in(i),out(i),1);
    }
    int ans=f.max_flow();
    printf("%d\n",ans);
    vector<int> vec;
    while(ans--)
    {
	for(int i=1;i<=n;i++)
	{
	    if(i==s||i==t) continue; 
	    if(f.e[in(i)][out(i)].tried) continue;
	    f.e[in(i)][out(i)].tried=1;
	    f.e[in(i)][out(i)].cap=0;
	    clear();
	    if(f.max_flow()==ans)
	    {
		vec.push_back(i);
		break;
		//printf("%d\n");
	    }
	    f.e[in(i)][out(i)].cap=1;
	}
    }
    for(int i=0;i<vec.size();i++)
    {
	if(i) printf(" ");
	printf("%d",vec[i]);
    }
    printf("\n");
    
   
    return 0;
}

