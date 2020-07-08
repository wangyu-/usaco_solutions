/*
  ID: wangyu.1
  LANG: C++11
  TASK: bigbrn
*/
#define TASKNAME "bigbrn"

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

char mp[1005][1005]={0};
short dp[1005][1005]={0};
short up[1005][1005]={0};
short lft[1005][1005]={0};

int n,m;
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif           
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++)
    {
	int r,c;
	scanf("%d %d",&r,&c);
	mp[r][c]=1;
    }
    for(int i=1;i<=n;i++)
    {
	for(int j=1;j<=n;j++)
	{
	    if(mp[i][j]==1) up[i][j]=0;
	    else up[i][j]=up[i-1][j]+1;

	    if(mp[i][j]==1) lft[i][j]=0;
	    else lft[i][j]=lft[i][j-1]+1;
	}
    }
    if(test)
    for(int i=1;i<=n;i++)
    {
	for(int j=1;j<=n;j++)
	{
	    printf("<%d>",up[i][j]);
	}
	printf("\n");
    }
    short best=0;
    for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
	    if(mp[i][j]==1) dp[i][j]=0;
	    else
	    {
		short size=dp[i-1][j-1]+1;
		size=min(size,(short)up[i][j]);
		size=min(size,(short)lft[i][j]);
		dp[i][j]=size;
		best=max(best,size);
	    }
	}
    printf("%d\n",(int)best); 

    

    return 0;
}

