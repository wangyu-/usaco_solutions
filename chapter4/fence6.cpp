/*
  ID: wangyu.1
  LANG: C++11
  TASK: fence6 
*/
#define TASKNAME "fence6"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <math.h>
using namespace std;

#ifdef TEST
int test=1;
#else
int test=0;
#endif

struct edge_t
{
    int num;
    int len;
    set<int> ed[2];
    int cl[2];
};
int n;
vector<edge_t> e;

int parent[200+5];

int find(int i)
{
  return parent[i]==-1 ? i : parent[i]=find(parent[i]);
}

void link(int i, int j)   // link j to i, i' rooot is root;
{
    assert(i!=j);
  //if (rand() % 2) swap(i,j);
    if(test)printf("<link %d %d>\n",i,j);
  parent[find(j)] = find(i);
}
int mat[205][205];
const int inf=1000*1000*10;
int nn;
int dist(int s,int t)
{
    int d[205];
    int used[205]={0};
    for(int i=0;i<nn;i++)
    {
	d[i]=inf;
    }
    d[s]=0;
    while(1)
    {
	int best=inf;
	int p=-1;
	for(int i=0;i<nn;i++)
	{
	    if(used[i]==1) continue;
	    if(d[i]<best)
	    {
		best=d[i];
		p=i;
	    }
	}
	if(p==-1) break;
	used[p]=1;
	for(int i=0;i<nn;i++)
	{
	    if(used[i])  continue;
	    if(mat[p][i]+d[p]<d[i])
		d[i]=mat[p][i]+d[p];
	}
    }
    return d[t];
}
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif
    memset(parent,-1,sizeof(parent));
    scanf("%d",&n);
    int cnt=0;
    for(int i=0;i<n;i++)
    {
	edge_t tmp;
	int a,b,c,d;
        scanf("%d %d %d %d",&a,&b,&c,&d);
	tmp.num=a;
	tmp.len=b;
	for(int j=0;j<c;j++)
	{
	    int t;
	    scanf("%d",&t);
	    tmp.ed[0].insert(t);
	}
	for(int j=0;j<d;j++)
	{
	    int t;
	    scanf("%d",&t);
	    tmp.ed[1].insert(t);
	}
	tmp.cl[0]=cnt++;
	tmp.cl[1]=cnt++;
	e.push_back(tmp);
    }
    for(int i=0;i<n;i++)
    {
	edge_t &a=e[i];
	for(int j=0;j<n;j++)
	{
	    if(i==j) continue;
	    edge_t &b=e[j];
	    for(int u=0;u<2;u++)
	    {
		for(int v=0;v<2;v++)
		{
		    for(auto it=a.ed[u].begin();it!=a.ed[u].end();it++)
		    {
			if(b.num!=*it) continue;
			if(b.ed[v].find(a.num)!=b.ed[v].end())
			{
			    if(find(a.cl[u])!=find(b.cl[v]))
			    link(a.cl[u],b.cl[v]);
			}
		    }
		}
	    }
	    
	}
    }
    for(int i=0;i<n;i++)
    {
	edge_t &a=e[i];
	a.cl[0]=find(a.cl[0]);
	a.cl[1]=find(a.cl[1]);
	//printf("<%d %d>\n",a.cl[0],a.cl[1]);
    }
    cnt=0;
    map<int,int> mp;
    for(int i=0;i<n;i++)
    {
	edge_t &a=e[i];
	for(int j=0;j<2;j++)
	{
	    int &c=a.cl[j];
	    if(mp.find(c)==mp.end())
		mp[c]=cnt++;
	    c=mp[c];
	}
	if(test)printf("<%d %d %d>\n",a.cl[0],a.cl[1],a.len);
    }

    nn=cnt;
    for(int i=0;i<nn;i++)
	for(int j=0;j<nn;j++)
	{
	    mat[i][j]=inf;
	}
    for(int i=0;i<n;i++)
    {
	edge_t &a=e[i];
	int x=a.cl[0];
	int y=a.cl[1];
	mat[x][y]=a.len;
	mat[y][x]=a.len;
    }
    int best=inf;
    for(int i=0;i<nn;i++)
    {
	for(int j=0;j<nn;j++)
	{
	    if(i==j)continue;
	    if(mat[i][j]==inf) continue;
	    int save=mat[i][j];
	    mat[i][j]=mat[j][i]=inf;
	    int d=dist(i,j);
	    if(test)printf("[d=%d save=%d %d %d]",d,save,i,j);
	    best=min(best,d+save);
	    mat[i][j]=mat[j][i]=save;
	}
    }
    printf("%d\n",best);
    return 0;
}

