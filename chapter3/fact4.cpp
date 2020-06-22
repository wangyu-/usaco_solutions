/*
  ID: wangyu.1
  LANG: C++11
  TASK: fact4
*/
#define TASKNAME "fact4"

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

int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif

    vector<int> vec;
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
	vec.push_back(i);
    }
    int cnt2=0;
    int cnt5=0;
    for(int i=0;i<vec.size();i++)
    {
	int &x=vec[i];
	while(x%2==0)
	{
	    cnt2++;
	    x=x/2;
	}
	while(x%5==0)
	{
	    cnt5++;
	    x=x/5;
	}	
    }
    //assert(cnt2>=cnt5);
    if(cnt2>=cnt5)
    {
	cnt2-=cnt5;
	cnt5=0;
    }
    else
    {
	cnt5-=cnt2;
	cnt2=0;
    }
    if(test)
    printf("<%d %d>",cnt2,cnt5);
    int res=1;
    for(int i=0;i<cnt2;i++)
    {
	res*=2;
	res%=10;
    }
    if(test) printf("<<%d>>",res);
    for(int i=0;i<cnt5;i++)
    {
	res*=5;
	res%=10;
    }
    if(test) printf("<<%d>>",res);
    for(int i=0;i<vec.size();i++)
    {
	res*=vec[i];
	res%=10;
    }
    if(test) printf("<<%d>>",res);
    printf("%d\n",res);
    
    return 0;
}

