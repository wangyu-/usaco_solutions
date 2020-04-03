/*
ID: wangyu.1
LANG: C++11
TASK: socdist1
*/
#define TASKNAME "socdist2"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
struct edge_t
{
	int p;
	int s;
};
int cow[1000*1000+5];
int main() 
{
#ifndef TEST
	freopen (TASKNAME".in", "r",stdin);
	freopen (TASKNAME".out", "w",stdout);
#endif
	int n;
	scanf("%d",&n);
	if(n==1)
	{
		int a,b;
		scanf("%d %d\n",&a,&b);
		if(b==1)
			printf("1\n");
		else
			printf("0\n");
		return 0;
	}
	int sick_cnt=0;
	vector<edge_t> e;
	memset(cow,-1,sizeof(cow));
	for(int i=0;i<n;i++)
	{
		int a,b;
		scanf("%d %d\n",&a,&b);
		cow[a]=b;
		if(b==1) sick_cnt++;
	}
	if(sick_cnt==0)
	{
			printf("0\n");
			return 0;
	}
	for(int i=0;i<=1000*1000;i++)
	{
		if(cow[i]!=-1)
		{
			edge_t tmp;
			tmp.p=i;tmp.s=cow[i];
			e.push_back(tmp);
		}
	}
#ifdef TEST
	for(auto x:e)
	{
		printf("<%d,%d>",x.p,x.s);
	}
	printf("\n");
#endif
	int max_r=1000*1000+5;
	for(int i=1;i<e.size();i++)
	{
		if(e[i-1].s!=e[i].s)
		{
			int r=e[i].p-e[i-1].p;
			if(r<max_r) max_r=r;
		}
	}
	e.clear();
	for(int i=0;i<=1000*1000;i++)
	{
		if(cow[i]==1)
		{
			edge_t tmp;
			tmp.p=i;tmp.s=cow[i];
			e.push_back(tmp);
		}
	}
#ifdef TEST
	for(auto x:e)
	{
		printf("<%d,%d>",x.p,x.s);
	}
	printf("\n");
	printf("max_r=%d\n",max_r);
#endif
	int cnt=1;
	for(int i=1;i<e.size();i++)
	{
		if(e[i].p-e[i-1].p>=max_r)
			cnt++;
	}
	printf("%d\n",cnt);
	return 0;
}

