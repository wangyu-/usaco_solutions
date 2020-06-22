/*
  ID: wangyu.1
  LANG: C++11
  TASK: ratios
*/
#define TASKNAME "ratios"

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

struct mix_t
{
    int r[3]={0};
    void prt()
	{
	    if(test) printf("<%d %d %d>",r[0],r[1],r[2]);
	}
    
}gre[3],goal;

int ans[4];
int best=999;
int verify(mix_t a,mix_t goal)
{
    int ratio=-1;
    for(int i=0;i<3;i++)
    {
	if(goal.r[i]==0)
	{
	    if(a.r[i]!=0) return -1;
	    continue;
	}
	if(a.r[i]%goal.r[i]!=0) return -1;
	int x=a.r[i]/goal.r[i];
	if(ratio==-1)
	{
	    ratio=x;
	}
	else if(ratio!=x) return -1;
    }
    return ratio;
    //return -1;
}
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif

    
    scanf("%d %d %d",&goal.r[0],&goal.r[1],&goal.r[2]);

    for(int i=0;i<3;i++)
    {
	scanf("%d %d %d",&gre[i].r[0],&gre[i].r[1],&gre[i].r[2]);
    }

    /*
    if(goal.r[0]==0&&goal.r[1]==0&&goal.r[2]==0)
    {
	printf("0 0 0 0\n");
	return 0;
	}*/
    
    
    for(int i=0;i<=100;i++)
    {
	for(int j=0;j<=100;j++)
	{
	    for(int k=0;k<=100;k++)
	    {
		mix_t t;
		int sum=i+j+k;
		if(sum==0) continue;
		for(int u=0;u<3;u++)
		{
		    t.r[u]+=gre[0].r[u]*i;
		    t.r[u]+=gre[1].r[u]*j;
		    t.r[u]+=gre[2].r[u]*k;
		}
		//t.prt();
		//goal.prt();
		int r=verify(t,goal);
		if(r!=-1)
		{
		    if(sum<best)
		    {
			best=sum;
			ans[0]=i;
			ans[1]=j;
			ans[2]=k;
			ans[3]=r;
		    }
		}
		
	    }
	}
    }
    if(best==999)
    {
	printf("NONE\n");
	return 0;
    }
    printf("%d %d %d %d\n",ans[0],ans[1],ans[2],ans[3]);
    
    return 0;
}

