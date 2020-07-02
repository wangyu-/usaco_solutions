/*
ID: wangyu.1
LANG: C++11
TASK: socdist1
*/
#define TASKNAME "moop"

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

const int MAXN=100*1000+5;
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

struct pnt_t
{
	int x;
	int y;
};
bool cmp(const pnt_t& a, const pnt_t &b)
{
        return a.x<b.x;
}
int main() 
{
#ifndef TEST
	freopen (TASKNAME".in", "r",stdin);
	freopen (TASKNAME".out", "w",stdout);
#endif
	int n;
	scanf("%d",&n);
	vector<pnt_t> e;
	memset(parent,-1,sizeof(parent));
	for(int i=0;i<n;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		pnt_t tmp;
		tmp.x=x;tmp.y=y;
		e.push_back(tmp);
	}
	int component=e.size();
	for(int i=0;i<e.size();i++)
		for(int j=0;j<i;j++)
		{
			if(e[i].x<=e[j].x&&e[i].y<=e[j].y   ||e[i].x>=e[j].x&&e[i].y>=e[j].y )
			{
				if(find(i)!=find(j))
				{
					link(i,j);
					component--;
				}
			}
		}
	printf("%d\n",component);
	return 0;
}

