/*
  ID: wangyu.1
  LANG: C++11
  TASK: money
*/
#define TASKNAME "money"

//#include <bits/stdc++.h>

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

int coin[30];
long long dp[30][10000+10]={0};
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif
    int v,n;
    scanf("%d %d",&v,&n);
    for(int i=0;i<v;i++)
	scanf("%d",&coin[i]); 
    dp[0][0]=1;
    for(int i=1;i<=v;i++)
    {
	int x=coin[i-1];
	for(int j=0;j<=n;j++)
	{
	    //dp[i][j]=dp[i-1][j]+dp[i-1][j-x].... 
	    for(int k=0;;k++)
	    {
		if(k*x>j) break;
		dp[i][j]+=dp[i-1][j-k*x];
	    }
	}
    }
    printf("%lld\n",dp[v][n]);


    return 0;
}

