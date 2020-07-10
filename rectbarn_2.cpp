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
const int size2=30;
struct seg_t
{
    unsigned char stat[size-size2+5]={0};  
    short stat2[size2]={0};      //use a trick to keep memory below 16mb
    int top=size;
    void remove(int a)
    {
	if(test)printf("<remove %d>\n",a);
	if(a==0) return;
	if(a<size2)
	    stat2[a]--;
	else
	    stat[a-size2]--;
    }
    void add(int a)
    {
	if(test)printf("<add %d>\n",a);
	if(a==0) return;
	if(a<size2)
	    stat2[a]++;
	else
	    stat[a-size2]++;
    }
    short get_max()
    {
	while(1)
	{
	    short a=top<size2?stat2[top]:stat[top-size2];
	    if(a!=0||top==0) return top;
	    else top--;
	}
    }
};
int height[size+5]={0};
seg_t sg[size+5];
vector<int> obs[size+5];
int ll[size+5];
int rr[size+5];
void scan(int m,int inc )
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
	for(int j=0;j<(int)obs[i].size();j++)
	{
	    if(test)printf("<point %d>\n",j);
	    int m=obs[i][j];
	    scan(m,-1);
	    scan(m,1);
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

