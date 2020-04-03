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

struct pnt_t
{
	int x;
	int y;
	int num;
};
bool cmpx(const pnt_t& a, const pnt_t &b)
{
        if(a.x==b.x) return a.y<b.y;
 	return a.x<b.x;
}
bool cmpy(const pnt_t& a, const pnt_t &b)
{
        if(a.y==b.y) return a.x<b.x;
 	return a.y<b.y;
}

const int MAXN=100*1000+5;
const int MAXC=1000*1000*1000+5;
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

int main() 
{
#ifndef TEST
	freopen (TASKNAME".in", "r",stdin);
	freopen (TASKNAME".out", "w",stdout);
#endif
	int n;
	memset(parent,-1,sizeof(parent));
	scanf("%d",&n);
	vector<pnt_t> e0;
	for(int i=0;i<n;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		pnt_t tmp;
		tmp.x=x;tmp.y=y;tmp.num=i;
		e0.push_back(tmp);
	}
	
	sort(e0.begin(),e0.end(),cmpx);
	int pre_x=-MAXC;int pre_y=-MAXC;
	vector<pnt_t> e;
	for(int i=0;i<e0.size();i++)
	{
		if(e0[i].x!=pre_x||e0[i].y!=pre_y)
		{
			e.push_back(e0[i]);
			pre_x=e0[i].x;
			pre_y=e0[i].y;
		}
	}
	reverse(e.begin(),e.end());
	vector<pnt_t>e1;
	vector<pnt_t> nd;
	int last_x=MAXC;
	for(int i=0;i<e.size();i++)
	{
		int x=e[i].x;
		int y=e[i].y;
		if(x!=last_x)
		{
			last_x=x;
			e1.push_back(e[i]);
		}
		else
		{
			nd.push_back(e[i]);
		}
	}
	sort(e1.begin(),e1.end(),cmpy);
	reverse(e1.begin(),e1.end()); 
	int last_y=MAXC;
	vector<pnt_t> e2;
	for(int i=0;i<e1.size();i++)
	{
		int x=e1[i].x;
		int y=e1[i].y;
		if(y!=last_y)
		{
			last_y=y;
			e2.push_back(e1[i]);
		}
		else
		{
			nd.push_back(e1[i]);
		}
	}
	
	vector<pnt_t> d;
	int max_y=-MAXC;
        sort(e2.begin(),e2.end(),cmpx);
        reverse(e2.begin(),e2.end());

	for(int i=0;i<e2.size();i++)
	{
		int x=e2[i].x;int y=e2[i].y;
		if(y>max_y)
		{
			max_y=y;
			d.push_back(e2[i]);
		}
		else
		{
			nd.push_back(e2[i]);
		}
		//cnt++;
	}

	if(test)
	{
		for(int i=0;i<e0.size();i++)
		{
			printf("<e0:%d,%d;num=%d>",e0[i].x,e0[i].y,e0[i].num);
		}
		printf("\n");
		for(int i=0;i<e.size();i++)
		{
			printf("<e:%d,%d;num=%d>",e[i].x,e[i].y,e[i].num);
		}
		printf("\n");
		for(int i=0;i<e2.size();i++)
		{
			printf("<e2:%d,%d;num=%d>",e2[i].x,e2[i].y,e2[i].num);
		}
		printf("\n");
		for(int i=0;i<d.size();i++)
		{
			printf("<d:%d,%d;num=%d>",d[i].x,d[i].y,d[i].num);
		}
		printf("\n");
		for(int i=0;i<nd.size();i++)
		{
			printf("<nd:%d,%d;num=%d>",nd[i].x,nd[i].y,nd[i].num);
		}
		printf("\n");
	}
	vector<pnt_t> ee;
	for(int i=0;i<d.size();i++) ee.push_back(d[i]);
	for(int i=0;i<nd.size();i++) ee.push_back(nd[i]);

	int component=e.size();
	assert(e.size()==nd.size()+d.size());
	for(int i=0;i<d.size();i++)
		for(int j=0;j<nd.size();j++)
		{
			if(d[i].x>=nd[j].x&&d[i].y>=nd[j].y )
			{
				int num1=d[i].num;
				int num2=nd[j].num;
				if(find(num1)!=find(num2))
				{
					if(test) printf("%d %d unconnected\n",num1,num2);
					//printf("!!!!!\n");
					link(num1,num2);
					component--;
				}
				else
				{
					if(test) printf("%d %d already connected\n",num1,num2);
				}
			}
		}
	printf("%d\n",component);
	//printf("%d\n",cnt);*/
	/*
	int component=ee.size();
	for(int i=0;i<ee.size();i++)
		for(int j=0;j<i;j++)
		{
			if(ee[i].x<=ee[j].x&&ee[i].y<=ee[j].y   ||ee[i].x>=ee[j].x&&ee[i].y>=ee[j].y )
			{
				if(find(i)!=find(j))
				{
					link(i,j);
					component--;
				}
			}
		}
	printf("%d\n",component);*/

	return 0;
}

