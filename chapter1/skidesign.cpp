/*
  ID: wangyu.1
  LANG: C++11
  TASK: skidesign
*/
#define TASKNAME "skidesign"

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

int h[1000+5];
int n;
int sq(int a)
{
    return a*a;
}

int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif
    scanf("%d",&n);
    int my_min=99999;
    int my_max=-1;
    for(int i=0;i<n;i++)
    {
	scanf("%d",h+i);
	my_min=min(h[i],my_min);
	my_max=max(h[i],my_max);
    }
    if(my_max-my_min<=17)
    {
	printf("0\n");
	return 0;
    }
    int low=9999999;
    for(int i=my_min;;i++)
    {
	int new_min=i;
	int new_max=new_min+17;
	if(new_max>my_max) break;
	int sum=0;
	for(int j=0;j<n;j++)
	{
	    if(h[j]<new_min)
		sum+=sq(new_min-h[j]);
	    else if(h[j]>new_max)
		sum+=sq(h[j]-new_max);
	}
	
	low=min(low,sum);
    }

    printf("%d\n",low);
    return 0;
}
