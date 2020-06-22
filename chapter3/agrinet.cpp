/*
  ID: wangyu.1
  LANG: C++11
  TASK: agrinet 
*/
#define TASKNAME "agrinet"

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
int mat[105][105];
int n;
int d[105];
const int inf=10000*10000;
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif

    scanf("%d",&n);
    for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	{
	    scanf("%d",&mat[i][j]);
	}
    for(int i=0;i<n;i++)
    {
	d[i]=mat[0][i];
    }
    d[0]=-1;
    int left=n-1;
    int sum=0;
    while(left--)
    {
	int best_d=inf;
	int p;
	for(int i=0;i<n;i++)
	{
	    if(d[i]==-1)continue;
	    if(d[i]<best_d)
	    {
		best_d=d[i];
		p=i;
	    }
	}
	d[p]=-1;
	sum+=best_d;
	for(int i=0;i<n;i++)
	{
	    if(d[i]==-1)continue;
	    d[i]=min(d[i],mat[p][i]);
	}
    }
    printf("%d\n",sum);
    


    
    return 0;
}

