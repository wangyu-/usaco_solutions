/*
  ID: wangyu.1
  LANG: C++11
  TASK: humble 
*/
#define TASKNAME "humble"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <vector>
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


int k,n;
int pr[105];
vector<int> vec;
long long up_bound=10001;
int up_max=0x7fffffff;
void dfs(int idx,long long v)
{ 
    if(idx==k)
    {
	vec.push_back(int(v));
	return ;
    }
    while(1)
    {
	if(v>up_bound) return;
	dfs(idx+1,v);	 
	v*=pr[idx];	
    }
}
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif
    scanf("%d %d",&k,&n);
    
    for(int i=0;i<k;i++)
    {
	scanf("%d",&pr[i]);
    }

    if(test) printf("<input done>\n");
    while(1)
    {	
	vec.clear();
	up_bound*=2;
	if(up_bound>up_max) up_bound=up_max;
	dfs(0,1);
	if(test)printf("<dfs done,%lld>",up_bound);

	if(vec.size()<n+1)
	{
	    if(test)
		for(int i=0;i<vec.size();i++)
		{
		    printf("[%d]",vec[i]);
		}
	    continue;
	}
	else
	{
	    //iassert(vec.size()>n+1);
	    sort(vec.begin(),vec.end());
	    if(test)
		for(int i=0;i<vec.size();i++)
		{
		    printf("[%d]",vec[i]);
		}
	    printf("%d\n",vec[n]);
	    break;
	    
	}
    }
    
    return 0;
}

