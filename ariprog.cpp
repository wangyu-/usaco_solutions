/*
  ID: wangyu.1
  LANG: C++11
  TASK: ariprog
*/
#define TASKNAME "ariprog"

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

int bs_table[2*300*300]={0};
int is_sq(int a)
{
    for(int i=0;i*i<=a;i++)
    {
	if(i*i==a) return 1;
    }
    return 0;
}
int is_bs(int a)
{
    for(int i=0;i*i<=a;i++)
    {
	if (is_sq(a-i*i)) return 1;
    }
    return 0;
}
int n,m;
int okay(int b,int a)
{
    for(int i=0;i<n;i++)
    {
	if(bs_table[a+i*b]==0) return 0;
    }
    return 1;
}
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif
    scanf("%d %d",&n,&m);
    for(int i=0;i<=m;i++)
    {
	for(int j=0;j<=m;j++)
	{
	    bs_table[i*i+j*j]=1;
	}
    }
    //if(test)printf("\n");
    int cnt=0;
    for(int i=1;i*(n-1)<=2*m*m;i++)
    {
	for(int j=0;j+i*(n-1)<=2*m*m;j++)
	{
	    if(okay(i,j))
	    {	
		printf("%d %d\n",j,i);
		cnt++;
	    }
	}
    }
    if(cnt==0)
    {
	printf("NONE\n");
    }
    return 0;
}
