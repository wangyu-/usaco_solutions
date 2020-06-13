/*
  ID: wangyu.1
  LANG: C++11
  TASK: frac1
*/
#define TASKNAME "frac1"

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
struct frac_t
{
    int x;
    int y; // x/y
};
int cmp(const frac_t &a,const frac_t &b)
{
    int r=a.x*b.y-a.y*b.x;
    if(r<0 ) return 1;
    else if(r>0) return 0;
    else
    //if(r==0)
    {
	return a.y<b.y;
    }
}
int eq(const frac_t &a,const frac_t &b)
{
    int r=a.x*b.y-a.y*b.x;
    if(r==0) return 1;
    else return 0;
}

vector<frac_t> vec;
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif
    int n;
    scanf("%d",&n);
    frac_t tmp;
    for(int j=1;j<=n;j++)
    {
	for(int i=0;i<=j;i++)
	{
	    tmp.x=i;
	    tmp.y=j;
	    vec.push_back(tmp);
	}
    }
    sort(vec.begin(),vec.end(),cmp);
    for(int i=0;i<vec.size();i++)
    {
	frac_t & c=vec[i];
	if(i==0|| !eq(c,vec[i-1]))
	printf("%d/%d\n",c.x,c.y);
    }


    return 0;
}

