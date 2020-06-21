/*
  ID: wangyu.1
  LANG: C++11
  TASK: humble 
*/
#define TASKNAME "humble"

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


int k,n;
int pr[105];
vector<int> vec;
inline void swap(int &a,int &b)
{
    int t=a;
    a=b;
    b=t;
}
int part(int a[],int l,int r)
{
    int idx=rand()%(r-l)+l;
    swap(a[l],a[idx]);
    int m=a[l];
    int p1=l,p2=r-1;
    while(p1<p2)
    {
	while(p1<p2&&a[p2]>m )
	{
	    p2--;
	}
	if(p1<p2) a[p1]=a[p2];
	while(p1<p2&&a[p1]<=m)
	{
	    p1++;
	}
	if(p1<p2) a[p2]=a[p1];
    }
    a[p1]=m;
    return p1;
}
void qs(int a[],int l,int r)
{
    if(r-l<=1) return ;
    int mid=part(a,l,r);
    qs(a,l,mid);
    qs(a,mid+1,r);
}
int select(int a[],int l,int r,int k)
{
    assert(r-l>0);
    if(r-l==1) return a[l];
    int mid=part(a,l,r);
    if(mid==k) return a[mid];
    if(k<mid) return select(a,l,mid,k);
    else return select(a,mid+1,r,k-mid-1);
}
long long up_bound=10001;
int up_max=0x7fffffff;
void dfs(int idx,long long v)
{ 
    if(idx==k)
    {
	vec.push_back(int(v));
	return ;
    }
    while(1)
    {
	if(v>up_bound) return;
	dfs(idx+1,v);	 
	v*=pr[idx];	
    }
}
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif
    srand(1231231);
    int nn=5;
    int aaa[]={3,7,2,9,1};
    part(aaa,0,nn);
    if(test)
    for(int i=0;i<nn;i++)
    {
	printf("<%d>",aaa[i]);
    }
     
    scanf("%d %d",&k,&n);
    
    for(int i=0;i<k;i++)
    {
	scanf("%d",&pr[i]);
    }

    if(test) printf("<input done>\n");
    while(1)
    {	
	vec.clear();
	up_bound*=2;
	if(up_bound>up_max) up_bound=up_max;
	dfs(0,1);
	if(test)printf("<dfs done,%lld>",up_bound);

	if(vec.size()<n+1)
	{
	    if(test)
		for(int i=0;i<vec.size();i++)
		{
		    printf("[%d]",vec[i]);
		}
	    continue;
	}
	else
	{
	    //iassert(vec.size()>n+1);
	    //sort(vec.begin(),vec.end());
	    qs(&vec[0],0,vec.size());
	    if(test)
		for(int i=0;i<vec.size();i++)
		{
		    printf("[%d]",vec[i]);
		}
	    printf("%d\n",vec[n]);
	    break;
	    
	}
    }
    
    return 0;
}

