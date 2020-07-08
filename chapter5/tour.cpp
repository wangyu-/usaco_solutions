/*
  ID: wangyu.1
  LANG: C++11
  TASK: tour
*/
#define TASKNAME "tour"

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


int n,m;
vector<int> nbs[100+5];
vector<int> inv[100+5];

map<string,int> to_idx;

int dp[100+5][100+5];

const int inf=1000*1000;
int dd(int x,int y)
{
    if(dp[x][y]!=-1) return dp[x][y];
    int &c=dp[x][y];
    c=-inf;
    //if(x==y&&x!=n) return c;
    for(int i=0;i<inv[x].size();i++)
    {
	int pre_x=inv[x][i];
	if(pre_x>y) continue;
	if(pre_x==y&&y!=1)continue;
	c=max(c,dd(pre_x,y)+1);
    }
    for(int i=0;i<inv[y].size();i++)
    {
	int pre_y=inv[y][i];
	if(pre_y>x) continue;
	if(pre_y==x&&x!=1)continue;
	c=max(c,dd(x,pre_y)+1);
    }
    return c;
}

int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif
    char buf[30];
    char buf2[30];
    memset(dp,-1,sizeof(dp));
    dp[1][1]=1;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
	scanf("%s",buf);
	to_idx[buf]=i;
    }
    for(int i=1;i<=m;i++)
    {
	scanf("%s %s",buf,buf2);
	int from=to_idx[buf];
	int to=to_idx[buf2];
	int a=min(from,to);
	int b=max(from,to);
	nbs[a].push_back(b);
	inv[b].push_back(a);
    }
    int res=dd(n,n);
    if(test)
    for(int i=1;i<=n;i++)
    {
	for(int j=1;j<=n;j++)
	{
	    printf("<%d %d %d>",i,j,dp[i][j]);
	}
	printf("\n");
    }
    if(res<0) printf("1\n");
    else
    {
	printf("%d\n",res-1);
    }
    //printf("%d\n",res);
   
    return 0;
}

