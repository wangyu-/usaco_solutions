/*
  ID: wangyu.1
  LANG: C++11
  TASK: wormhole
*/
#define TASKNAME "wormhole"

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
struct point_t
{
    int x,y;
    int pair;
    int right;
};
int n;
vector<point_t> vec;
int cnt=0;
int verify()
{
    if(test)
    {
	for(int i=0;i<n;i++)
	{
	    printf("%d:%d ",i,vec[i].pair);
	}
	printf("\n");
    }
    for(int i=0;i<n;i++)
    {
	int p=i;
	for(int j=0;j<2*n;j++)
	{
	    assert(p!=-1);
	    p=vec[p].pair;
	    assert(p!=-1);
	    p=vec[p].right;
	    if(p==-1) break;
	}
	if(p!=-1) return 1;
    }
    return 0;
}
int rec()
{
    //printf("!\n");
    int i;
    for(i=0;i<n;i++)
    {
	if(vec[i].pair==-1) break;
    }
    if(i==n)
    {
	if(verify())
	    cnt++;
	//all paired
	return 0;
    }

    for(int j=i+1;j<n;j++)
    {
	if(vec[j].pair==-1)
	{
	    vec[j].pair=i;
	    vec[i].pair=j;
	    rec();
	    vec[i].pair=vec[j].pair=-1;
	}
    }
    return 0;

}
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
	point_t tmp;
	scanf("%d %d",&tmp.x,&tmp.y);
	tmp.pair=-1;
	tmp.right=-1;
	vec.push_back(tmp);
    }
    //printf("%d\n",n);
    for(int i=0;i<n;i++)
    {
	for(int j=0;j<n;j++)
	{
	    if(j==i) continue;
	    if(vec[j].y!=vec[i].y) continue;
	    if(vec[j].x>vec[i].x )
	    {
		if(vec[i].right==-1)
		{
		    vec[i].right=j;
		}
		else if(vec[j].x<vec[vec[i].right].x)
		{
		    vec[i].right=j;
		}
	    }
	}
	if(test) printf("<%d>",vec[i].right);
    }
    if(test)printf("\n");
    rec();
    printf("%d\n",cnt);
    return 0;
}
