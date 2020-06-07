/*
  ID: wangyu.1
  LANG: C++11
  TASK: holstein
*/
#define TASKNAME "holstein"

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
int pow2(int a)
{
    int r=1;
    while(a--)
    {
	r*=2;
    }
    return r;
}
int v,g;
int V[25+5];
int G[15+5][25+5];
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif
    scanf("%d",&v);
    for(int i=0;i<v;i++)
    {
	scanf("%d",&V[i]);
    }
    scanf("%d",&g);
    for(int i=0;i<g;i++)
    {
	for(int j=0;j<v;j++)
        {
	    scanf("%d",&G[i][j]);
	}
    }
    int range=pow2(g);
    int best_size=999;
    int sol=0;
    for(int i=0;i<range;i++)
    {
	if(test)printf("<%d>",i);
	int t=i;
	int cv[25+5]={0};
	int size=0;
	for(int j=0;j<g;j++)
	{

	    //if(t&1) printf("1");
	    //else printf("0");
	    if(t&1)
	    {
		size++;
		for(int k=0;k<v;k++)
		{
		    cv[k]+=G[j][k]; 
		}
	    }
	    t=t/2;
	}

	int ok=1;
	for(int k=0;k<v;k++)
	{
	    if(cv[k]<V[k]) ok=0;
	}
	if(!ok)continue;
	if(size<best_size)
	{
	    best_size=size;
	    sol=i;
	}
	
	if(test)printf("\n");
    }
    printf("%d",best_size);
    int t=sol;
    for(int j=0;j<g;j++)
    {

	if(t&1)
	{
	    printf(" %d",j+1);
	}
	t=t/2;
    }
    printf("\n");

    return 0;
}

