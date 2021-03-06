/*
ID: wangyu.1
LANG: C++11
TASK: socdist1
*/
#define TASKNAME "fcolor"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#ifdef TEST
int test=1;
#else
int test=0;
#endif

const int MAXN=2*100*1000+5;
int parent[MAXN];

int find(int i)
{
  return parent[i]==-1 ? i : parent[i]=find(parent[i]);
}

void link(int i, int j)
{
  if (rand() % 2) swap(i,j);
  parent[find(i)] = find(j);
}


vector<int> e[MAXN];
int c[MAXN];
int main() 
{
#ifndef TEST
	freopen (TASKNAME".in", "r",stdin);
	freopen (TASKNAME".out", "w",stdout);
#endif
	memset(parent,-1,sizeof(parent));
	memset(c,-1,sizeof(c));
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		e[a].push_back(b);
	}
	while(1)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(i!=find(i)) continue;
			for(int j=1;j<e[i].size();j++)
			{
				int x=e[i][0];
				int y=e[i][j];
				int r_x=find(x);
				int r_y=find(y);
				if(r_x!=r_y)
				{
					link(x,y);
					cnt++;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			int root=find(i);
			if(i==root) continue;
			else
			{
				for(int j=0;j<e[i].size();j++)
				{
					e[root].push_back(e[i][j]);
				}
			}
		}
		
		if(cnt==0) break;
	}
	int idx=0;
	if(test) 
	{
		for(int i=1;i<=n;i++)
		{
			printf("<root%d=%d>",i,find(i));
		}
		printf("\n");
	}
	for(int i=1;i<=n;i++)
	{
		int root=find(i);
		if(c[root]==-1)
		{
			idx++;
			c[root]=idx;		
			c[i]=c[root];
		}
		else
		{
			c[i]=c[root];
		}
		
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d\n",c[i]);
	}
	return 0;
}

