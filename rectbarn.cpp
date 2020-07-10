/*
  ID: wangyu.1
  LANG: C++11
  TASK: rectbarn
*/
#define TASKNAME "rectbarn"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>
#include <math.h>
#include <typeinfo>
#include <iostream>
using namespace std;

#ifdef TEST
const int test=0;
#else
const int test=0;
#endif
int R,C,P;
const int size=3000;
const int half=size/2;
struct seg_t
{
    short huge=0;
    short stat[half+5]={0};
    short top=half;
    void remove(int a)
    {
	if(test)printf("<remove %d>\n",a);
	if(a==0) return;
	if(a>half)
	{
	    assert(huge==a);
	    huge=0;
	}
	else
	{
	    //printf("<%d>\n",stat[a]);
	    stat[a]--;
	    assert(stat[a]>=0);
	}
    }
    void add(int a)
    {
	if(test)printf("<add %d>\n",a);
	if(a==0) return;
	if(a>half)
	{
	    assert(huge==0);
	    huge=a;
	}
	else
	{
	    stat[a]++;
	}
    }
    short get_max()
    {
	if(huge) return huge;
	while(top>0&&stat[top]==0)
	{
	    top--;
	}
	return top;
    }
};
int height[size+5]={0};
seg_t sg[size+5];
vector<int> obs[size+5];
int ll[size+5];
int rr[size+5];
void update(int m,int inc )
{
    int top;
    assert(inc==-1||inc==1);
    int *dist=ll;
    if(inc==1) dist=rr;
    top=height[m];
    dist[top]=m;
    for(int k=m+inc;k>=0&&k<=C+1;k+=inc)
    {
	int h=height[k];
	//printf("<%d %d %d %d>\n",m,inc,k,h);
	if(h>=top)
	{
	    dist[top]=k;
	    continue;
	}
	else //if(h<top)
	{
	    while(top!=h)
	    {
		top--;
		dist[top]=dist[top+1];
	    }
	    dist[top]=k;
	    if(top==0) break;
	}
    }
}
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif           
    scanf("%d %d %d",&R,&C,&P);
    //memset(mp,0,sizeof(0));
    for(int i=0;i<P;i++)
    {
	int r,c;
	scanf("%d %d",&r,&c);
	obs[r].push_back(c);
    }
    int best=0;
    for(int i=1;i<=R;i++)
    {
	if(test) printf("=======row %d=======\n",i);
	sg[i].add(C);
	for(int j=1;j<=C;j++)
	{
	    height[j]++;
	}
	for(int j=0;j<obs[i].size();j++)
	{
	    if(test)printf("<point %d>\n",j);
	    int m=obs[i][j];
	    update(m,-1);
	    update(m,1);
	    for(int k=height[m];k>=1;k--)
	    {
		int idx=i-(k-1);
		if(test)printf("height=%d rr=%d ll=%d m=%d idx=%d %d\n",k,rr[k],ll[k],m,idx,height[ll[k]]);
		sg[idx].remove(rr[k]-ll[k]+1);
		sg[idx].add(rr[k]-m);
		sg[idx].add(m-ll[k]);
	    }
	    height[m]=0;
	}
	for(int j=1;j<=i;j++)
	{
	    best=max(best,sg[j].get_max()*(i-j+1));
	}
    }
    printf("%d\n",best);

    

    return 0;
}

