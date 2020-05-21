/*
  ID: wangyu.1
  LANG: C++11
  TASK: sprime 
*/
#define TASKNAME "sprime"

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
int is_prime(int a)
{
    if(a<2) return 0;
    for(int i=2;i*i<=a;i++)
    {
	if(a%i==0) return 0;
    }
    return 1;
}
int n;
void dfs(int a,int depth)
{
    if(!is_prime(a)) return;
    if(depth==n) {printf("%d\n",a);return;}
    for(int i=1;i<=9;i+=2)
    {
	dfs(a*10+i,depth+1);
    }
}
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif
    scanf("%d",&n);
    for(int i=2;i<=9;i++)
    {
	dfs(i,1);
    }
    return 0;
}
