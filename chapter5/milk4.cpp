/*
  ID: wangyu.1
  LANG: C++11
  TASK: milk4
*/
#define TASKNAME "milk4"

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
using namespace std;

#ifdef TEST
int test=1;
#else
int test=0;
#endif
int Q,P;
int num[100+5];
const int mod=100+2;
char dp[mod][20000+2];
char d2[mod][20000+2];
char d3[mod][20000+2];
const int inf=110;

int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif           
    scanf("%d %d",&Q,&P);
    for(int i=1;i<=P;i++)
	scanf("%d",&num[i]);
    sort(num+1,num+1+P);
    reverse(num+1,num+1+P);
    for(int i=0;i<=Q;i++)
    {
	dp[0][i]=inf;
    }
    dp[0][0]=0;
    for(int i=1;i<=P;i++)
    {
	int n1=num[i];
	for(int j=0;j<=Q;j++)
	{
	    char &c=dp[i][j];
	    c=inf;
	    if(j>=n1)
	    {	
		char np=dp[i-1][j-n1]+1;
		char op=dp[i][j-n1];
		if(np<c)  //pick jth num ,new
		    c=np;
		if(op<c) //continue pick jth num
		    c=op;
	    }
	    d2[i][j]=dp[i][j];
	    // printf("<%d,%d,%d> ",i,j,dp[i][j]);
	}
	for(int j=0;j<=Q;j++)
	{
	    char &b=dp[i-1][j];
	    char &c=dp[i][j];
	    if(b<c)  // use old result  do not pick j
	    {
		c=b;
	    }
	}
    }
    printf("%d",dp[P][Q]);
    if(test) printf("\n");
    int left_n=dp[P][Q];
    vector<int>res;
    int last_idx=P;
    /*
    for(int i=P;i>=0;i--)
    {
	if(d2[i][Q]==left_n)
	{
	    res.push_back(num[i]);
	    last_idx=i;
	    left_n--;
	    break;
	}
	}*/
    for(int i=0;i<=Q;i++)
    {
	d3[0][i]=0;
    }
    d3[0][0]=1;
    for(int i=0;i<=dp[P][Q]&&left_n;i++)
    {
	int n1=res[i-1];
	for(int j=0;j<=Q;j++)
	{
	    d3[i][j]=0;
	    if(j>=n1&&i)
	    {
		if(d3[i-1][j-n1]) d3[i][j]=1;
		if(d3[i][j-n1]) d3[i][j]=1;
	    }
	}
	for(int j=last_idx-1;j>=0;j--)
	{
	    for(int k=0;k<=Q;k++)
	    {
		if(d3[i][Q-k]==1&&d2[j][k]==left_n)
		{
		    res.push_back(num[j]);
		    last_idx=j;
		    left_n--;
		    goto end;
		}
	    }
	}
	assert(0==1);
    end:;
    }
    for(auto x:res)
    {
	printf(" %d",x);
    }
    printf("\n");

    return 0;
}

