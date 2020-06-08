/*
  ID: wangyu.1
  LANG: C++11
  TASK: hamming 
*/
#define TASKNAME "hamming"

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
int n,b,d;
int dis(int x,int y)
{
    int z=x^y;
    int d=0;
    for(int i=0;i<b;i++)
    {
	if(z&1) d++;
	z/=2;
    }
    return d;
}
int pow2(int x)
{
    int r=1;
    while(x--)
	r*=2;
    return r;
}
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif
    scanf("%d %d %d",&n,&b,&d);
    int range=pow2(b);
    vector<int> vec;
    vec.push_back(0);
    for(int i=1;i<range;i++)
    {
	int ok=1;
	for(int j=0;j<vec.size();j++)
	{
	    if(dis(i,vec[j])<d) {ok=0;break;}
	}
	if(ok) vec.push_back(i);
	if(vec.size()>=n)break;
    }
    int cnt=0;
    for(int i=0;i<n;i++)
    {
	if(cnt!=0) printf(" ");
	printf("%d",vec[i]);
	cnt++;
	if(cnt==10)
	{
	    printf("\n");
	    cnt=0;
	}
    }
    if(cnt)
    printf("\n");
    
    return 0;
}

