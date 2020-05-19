/*
  ID: wangyu.1
  LANG: C++11
  TASK: numtri
*/
#define TASKNAME "numtri"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
#ifdef TEST
int test=1;
#else
int test=0;
#endif
int num[1005][1005];
int dp[1005][1005];
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
	for(int j=0;j<=i;j++)
	{ 
	    scanf("%d",&num[i][j]); 
	}
    }
    dp[0][0]=num[0][0];
    for(int i=1;i<n;i++)
    {
	for(int j=0;j<=i;j++)
	{
	    dp[i][j]=-1;
	    if(j!=0)
	    {
		dp[i][j]=max(dp[i][j],dp[i-1][j-1]+num[i][j]);
	    }
	    if(j!=i)
	    {
		dp[i][j]=max(dp[i][j],dp[i-1][j]+num[i][j]);
	    }
	}
    }
    int result=-1;
    for(int j=0;j<n;j++)
    {
	result=max(result,dp[n-1][j]);
    }
    printf("%d\n",result);
    return 0;
}
