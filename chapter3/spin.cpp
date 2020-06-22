/*
  ID: wangyu.1
  LANG: C++11
  TASK: spin
*/
#define TASKNAME "spin"

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

int speed[5];
int tr[5][360]={0};
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif
    for(int i=0;i<5;i++)
    {
	scanf("%d",&speed[i]);
	speed[i]=360-speed[i];
	int n;
	scanf("%d",&n);
	for(int j=0;j<n;j++)
	{
	    int a,b;
	    scanf("%d %d",&a,&b);
	    for(int k=0;k<=b;k++)
	    {
		tr[i][(a+k)%360]=1;
	    }
	}
    }



    for(int i=0;i<400;i++)
    {
	for(int j=0;j<360;j++)
	{
	    int ok=1;
	    for(int k=0;k<5;k++)
	    {
		int idx=(j+speed[k]*i)%360;
		if(tr[k][idx]==0) ok=0;
	    }
	    if(ok)
	    {
		printf("%d\n",i);
		return 0;
	    }
	}
    }
    printf("none\n");



    
    return 0;
}

