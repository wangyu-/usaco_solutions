/*
  ID: wangyu.1
  LANG: C++11
  TASK: buylow 
*/
#define TASKNAME "buylow"

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

int p[5000+5];
int n;
const int mod=20;
int dp[5000+5];
vector<int> pre[5000+5];
int inf=1000*1000*1000;
set<int> st;
vector<int> uni;
const int len=10;
struct bn_t
{
    int d[len]={0};
    void add(bn_t& y)
    {
	int *e=y.d;
	int c=0;
	for(int i=len-1;i>=0;i--)
	{
	    d[i]+=e[i]+c;
	    c=d[i]/inf;
	    d[i]%=inf;
	}
    }
    void prt()
    {
	int i;
	for(i=0;i<len-1;i++)
	{
	    if(d[i])break;
	}
	int cnt=0;
	for(;i<len;i++)
	{
	    if(cnt++==0)
		printf("%d",d[i]);
	    else
		printf("%09d",d[i]);
	}
	//printf("\n");
	   
    }
};
bn_t d2[5000+5];
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
	scanf("%d",&p[i]);
	st.insert(p[i]);
    }
    for(auto i:st)
	uni.push_back(i);
    p[0]=inf;
    dp[0]=0;
    int best=0;
    for(int i=1;i<=n;i++)
    {
	dp[i]=0;
	for(int j=0;j<i;j++)
	{
	    if(p[i]<p[j])
	    {
		if(dp[j]+1>dp[i])
		{
		    pre[i].clear();
		    pre[i].push_back(j);
		    dp[i]=dp[j]+1;
		}
		else if(dp[j]+1==dp[i])
		    pre[i].push_back(j);
	    }
	}
	best=max(best,dp[i]);
	if(test)
	{
	    printf("<%d>",dp[i]);
	    //for(int j=0;j<(int)pre[i].size();j++)
	    //	printf("[%d]",pre[i][j]);
	}
    }
    if(test) printf("\n");
    d2[0].d[len-1]=1;
    //d2[0].prt();
    for(int i=1;i<=n;i++)
    {
	//d2[i]=0;
	set<int> used;
	for(int j=i-1;j>=0;j--)
	{
	    if(used.find(p[j])!=used.end())
		continue;
	    if(p[i]<p[j])
	    {
		if(dp[j]==dp[i]-1)
		{
		    used.insert(p[j]);
		    d2[i].add(d2[j]);
		}
	    }
	}
	//if(test)printf("<%d>",d2[i]);
    }
    if(test)printf("\n");
    bn_t sum;
    set<int> used;
    for(int i=n;i>=0;i--)
    {
	if(used.find(p[i])!=used.end()) continue;
	if(dp[i]==best)
	{
	    used.insert(p[i]);
	    sum.add(d2[i]);
	}
    }
    printf("%d ",best);
    sum.prt();
    printf("\n");
    return 0;
    

    return 0;
}

