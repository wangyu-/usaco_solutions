/*
ID: wangyu.1
LANG: C++11
TASK: socdist1
*/
#define TASKNAME "cereal"

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
bool cmp(const pnt_t& a, const pnt_t &b)
{
        return a.x<b.x;
}

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

int main() 
{
#ifndef TEST
	freopen (TASKNAME".in", "r",stdin);
	freopen (TASKNAME".out", "w",stdout);
#endif
	int n;
	memset(parent,-1,sizeof(parent));
	scanf("%d",&n);
	vector<pnt_t> nd;
	for(int i=0;i<n;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		if(mp1.find(x)==mp1.end()) {mp1[x]=y;mp1_num[x]=i;}
		else 
		{
			if(y>mp1[x]) {
				mp1[x]=y;mp1_num[x]=i;
				pnt_t tmp;
				tmp.x
			}
			else
			{
				pnt_t tmp;
				tmp.x=x;tmp.y=y;
				tmp.num=i;
				nd.push_back(tmp);
			}
		}
	}
	map<int,int> mp2;
	map<int,int> mp2_num;
	for(auto it=mp1.begin();it!=mp1.end();it++)
	{
		int x=it->first;
		int y=it->second;
		int num=mp1_num[x];
		if(mp2.find(y)==mp2.end()) {mp2[y]=x;mp2_num[y]=num;}
		else 
		{
			if(x>mp2[y]) {mp2[y]=x;mp2_num[y]=num;}
			else
			{
				pnt_t tmp;
				tmp.x=x;tmp.y=y;
				tmp.num=num;
				nd.push_back(tmp);
			}
		}
	}
	vector<pnt_t> e;
	for(auto it=mp2.begin();it!=mp2.end();it++)
	{
		int x=it->second;
		int y=it->first;
		int num=mp2_num[y];
		pnt_t tmp;
		tmp.x=x;tmp.y=y;
		tmp.num=num;
		e.push_back(tmp);
	}
	sort(e.begin(),e.end(),cmp);
	reverse(e.begin(),e.end());
	int max_y=-1000*1000*1000-5;
	int cnt=0;
	vector<pnt_t> d;
	
	for(int i=0;i<e.size();i++)
	{
		int x=e[i].x;int y=e[i].y;
		if(max_y>y)
		{
			nd.push_back(e[i]);
		}
		else
		{
			d.push_back(e[i]);
		}
		cnt++;
		max_y=y;
	}

	if(test)
	{
		for(int i=0;i<d.size();i++)
		{
			printf("<d:%d,%d;num=%d>",d[i].x,d[i].y,d[i].num);
		}
		printf("\n");
		for(int i=0;i<nd.size();i++)
		{
			printf("<nd:%d,%d;num=%d>",nd[i].x,nd[i].y,d[i].num);
		}
		printf("\n");
	}
	int component=n;
	for(int i=0;i<d.size();i++)
		for(int j=0;j<nd.size();j++)
		{
			if(d[i].x>=nd[j].x&&d[i].y>=nd[j].y )
			{
				int num1=d[i].num;
				int num2=nd[i].num;
				//printf("????\n");
				if(find(num1)!=find(num2))
				{
					printf("!!!!!\n");
					link(num1,num2);
					component--;
				}
			}
		}
	printf("%d\n",component);
	//printf("%d\n",cnt);
	return 0;
}

