/*
  ID: wangyu.1
  LANG: C++11
  TASK: ditch
*/
#define TASKNAME "ditch"

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

struct flow_t
{
	struct edge_t
	{
		int flow=0;
		int cap=-1;
		int remain()
		{
			return cap-flow;
		}	
	};
	vector<vector<int>> nbs;
	vector<vector<edge_t>> e;
	vector<bool> visited;
	vector<int> pre;
	int source=-1,target=-1;
	const int inf=1000*1000*1000;
	void init(int n) //number of nodes
	{
		nbs=decltype(nbs)(n);
		e=decltype(e)(n,(decltype(e)::value_type)(n));
		visited=decltype(visited)(n);
		pre=decltype(pre)(n);
	}
	void add_edge(int a,int b,int cap) //add direct edge
	{
		if(e[a][b].cap==-1)
		{
			nbs[a].push_back(b);
			nbs[b].push_back(a);
			e[a][b].cap=0;
			e[b][a].cap=0;
		}
		e[a][b].cap+=cap;
	}
	bool dfs(int x)
	{
		if(x==target) return true;
		visited[x]=1;
		for(auto y:nbs[x])
		{
			if(visited[y]) continue;
			if(e[x][y].remain()<=0) continue;
			pre[y]=x;
			if(dfs(y)) return true;
		}
		return false;
	}
	int bottleneck()
	{
		int x=target;
		int min_value=inf;
		while(x!=source)
		{
			min_value=min(min_value,e[pre[x]][x].remain());
			x=pre[x];
		}
		return min_value;
	}
	void augment(int delta)
	{
		int x=target;
		while(x!=source)
		{
			e[pre[x]][x].flow+=delta;
			e[x][pre[x]].flow-=delta;
			x=pre[x];
		}
	}
	int max_flow()
	{
		assert(source!=-1&&target!=-1);
		int total_flow=0;
		while(1)
		{
			fill(visited.begin(),visited.end(),0);
			if(!dfs(source)) break;
			int delta=bottleneck();
			total_flow+=delta;
			augment(delta);
		}
		return total_flow;
	}
}f;

int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif
    int m,n;
    scanf("%d %d",&m,&n);
    f.init(n+5);
    for(int i=0;i<m;i++)
    {
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	f.add_edge(a,b,c);
    }
    f.source=1;
    f.target=n;
    int res=f.max_flow();
    printf("%d\n",res);
    return 0;
}

