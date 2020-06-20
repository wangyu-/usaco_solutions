/*
  ID: wangyu.1
  LANG: C++11
  TASK: fence
*/
#define TASKNAME "fence"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <math.h>
using namespace std;

#ifdef TEST
int test=1;
#else
int test=0;
#endif


map<int,int> adj[500+5];
int sum[500+5]={0};
vector<int> res;

void dfs(int a)
{
    //printf("!\n");
    auto & ad=adj[a];
    for(auto it=ad.begin();it!=ad.end();it++)
    {
	int b=it->first;
	if(it->second==0) continue;
	it->second--;
	adj[b][a]--;
	dfs(b);
    }
    res.push_back(a);
}
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif
    int n;
    scanf("%d",&n);
    int min_node=999;
    for(int i=0;i<n;i++)
    {
	int a,b;
	scanf("%d %d",&a,&b);
	if(adj[a].find(b)==adj[a].end())
	{
	    adj[a][b]=1; adj[b][a]=1;
	}
	else
	{
	    adj[a][b]++; adj[b][a]++;
	}
	min_node=min(min_node,a);
	min_node=min(min_node,b);
	sum[a]++;
	sum[b]++;
    }
    int min_odd=999;
    for(int i=1;i<=500;i++)
    {
	if(sum[i]%2==1)
	{
	    min_odd=min(min_odd,i);
	    if(test) printf("<%d>\n",i);
	}
    }
    if(min_odd==999)
	dfs(min_node);
    else
	dfs(min_odd);
    reverse(res.begin(),res.end());
    for(int i=0;i<res.size();i++)
    {
	//if(i)printf(" ");
	printf("%d\n",res[i]);
    }
    //printf("\n");

    

    
    
    return 0;
}

