/*
  ID: wangyu.1
  LANG: C++11
  TASK: range
*/
#define TASKNAME "range"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <string>
#include <math.h>
using namespace std;

#ifdef TEST
int test=1;
#else
int test=0;
#endif

char mp[255][255];
int dp[255][255]={0};
int ans[255]={0};
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
	scanf("%s",mp[i+1]+1);
    }

    for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
	    if(mp[i][j]=='0')
		dp[i][j]=0;
	    else
	    {
		//printf("<%d %d>",i,j);
		int size=dp[i-1][j-1];
		int cnt=0;
		for(int k=0;k<size;k++)
		{
		    if(mp[i-1-k][j]=='0') break;
		    if(mp[i][j-1-k]=='0') break;
		    cnt++;
		}
		dp[i][j]=cnt+1;
	    }
	    for(int u=1;u<=dp[i][j];u++)
	    {
		ans[u]++;
	    }
	}
    if(test)
    for(int i=1;i<=n;i++)
    {
	for(int j=1;j<=n;j++)
	{
	    printf("<%d>",dp[i][j]);
	}
	printf("\n");
    }
    for(int i=2;i<=n;i++)
    {
	if(!ans[i])continue;
	printf("%d %d\n",i,ans[i]);
    }





    
    return 0;
}

