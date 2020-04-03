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

void link(int i, int j)   // link j to i, i' rooot is root;
{
  //if (rand() % 2) swap(i,j);
  parent[find(j)] = find(i);
}


map<int,int> e[MAXN];
int c[MAXN];
int blocked[MAXN];
int main() 
{
#ifndef TEST
	freopen (TASKNAME".in", "r",stdin);
	freopen (TASKNAME".out", "w",stdout);
#endif
	memset(parent,-1,sizeof(parent));
	memset(c,-1,sizeof(c));
	memset(blocked,0,sizeof(blocked));
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		e[a][b]=1;
	}
	vector<int> v;
	for(int i=1;i<=n;i++)
	{
		v.push_back(i);
	}
	while(1)
	{
		int cnt=0;
		map<int,int> mp_root;
		for(int idx=0;idx<v.size();idx++)
		{
			int i=v[idx];

			if(i!=find(i)) continue;
			map<int,int> tmp_e2;
			for(auto it=e[i].begin();it!=e[i].end();it++)
			{
				int j=it->first;
				tmp_e2[find(j)]=1;
			}
			e[i]=tmp_e2;
			
			
			if(e[i].find(i)!=e[i].end())
			{
				int x=i;
				map<int,int> tmp_e;
				tmp_e=e[i];
				for(auto it=e[i].begin();it!=e[i].end();it++)
				{
					int j=it->first;
					if(j==i) continue;
					//if(find(j)!=j) continue; //already been removed 

					int y=j;
					link(x,y);
					cnt++;
					for (auto it2=e[y].begin();it2!=e[y].end();it2++)
					{
						tmp_e[it2->first]=1;		
					}
					e[y].clear();
					//blocked[y]=1;
					mp_root[x]=1;
				}
				e[i]=tmp_e;
				
			}
			else
			{
				int x=-1;
				for(auto it=e[i].begin();it!=e[i].end();it++)
				{
					int j=it->first;
					//if(find(j)!=j) continue; //already been removed 

					if(x==-1)
					{
						x=j;
						continue;
					}
					int y=j;
					link(x,y);
					cnt++;
					for (auto it2=e[y].begin();it2!=e[y].end();it2++)
					{
						e[x][it2->first]=1;		
					}
					e[y].clear();
					//blocked[y]=1;
					mp_root[x]=1;
				}
			}
		}
		v.clear();
		for(auto it=mp_root.begin();it!=mp_root.end();it++)
		{
			v.push_back(it->first);
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

