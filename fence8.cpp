/*
  ID: wangyu.1
  LANG: C++11
  TASK: fence8
*/
#define TASKNAME "fence8"

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
int test=1;
#else
int test=0;
#endif

int B,R;
int b[50+5];
int r[1023+5];
int idb(int a)
{
	return a+2;
}
int idr(int a)
{
	return a+2+B;
}
int stat[128+5];
int cnt;
int found;
int sum_r;
int sum_b;
int ll=9999;
int hh=0;
void dfs(int idx,int item_idx)
{
	if(sum_b<sum_r) return ;
	//printf("<%d>",cnt);
	if(cnt==0)
		found=1;

	if(found)return ;

	if(idx==B)
	{
		return;
	};
	if(item_idx==hh+1)
	{
		sum_b-=b[idx];
		dfs(idx+1,ll);
		sum_b+=b[idx];
		return ;
	}
	for(int i=stat[item_idx];i>=0;i--)
	{
		//if(idx==0&&i!=0)
		//printf("<tried %d %d %d>",i,cnt,stat[item_idx]);
		if(b[idx]-i*item_idx>=0)
		{
			b[idx]-=i*item_idx;
			stat[item_idx]-=i;
			cnt-=i;
			sum_r-=-i*item_idx;
			sum_b-=-i*item_idx;
			dfs(idx,item_idx+1);
			sum_r+=-i*item_idx;
			sum_b+=-i*item_idx;
			cnt+=i;
			stat[item_idx]+=i;
			b[idx]+=i*item_idx;
		}
	}
}
int verify(int n)
{
	int sum_b=0;
	int sum_r=0;
	for(int i=0;i<B;i++)
	{
		sum_b+=b[i];
	}
	memset(stat,0,sizeof(stat));
	for(int i=0;i<n;i++)
	{
		ll=min(r[i],ll);
		hh=max(r[i],hh);
		sum_r+=r[i];
		stat[r[i]]++;
	}
	::sum_r=sum_r;
	::sum_b=sum_b;
	//ll=1;
	//hh=128;
	cnt=n;
	//printf("<cnt=%d>\n",cnt);
	//if(sum_r>sum_b)
	//	return 0;
	//printf("<before dfs>");
	found=0;
	dfs(0,0);
	if(found) return 1;
	return 0;
}
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif           
    scanf("%d",&B);
    for(int i=0;i<B;i++)
    {
	    scanf("%d",&b[i]);
    }
    sort(b,b+B);

    scanf("%d",&R);
    for(int i=0;i<R;i++)
    {
	    scanf("%d",&r[i]);
    }
    sort(r,r+R);
    for(int i=1;i<=R;i++)
    {
	    if(test) printf("trying %d\n",i);
	    if(verify(i)==0)
	    {
	    	printf("%d\n",i-1);
		return 0;
	    }
	    else
	    {
		    if(i==R)
		    {
			    printf("%d\n",i);
		    }
	    }
    }
    //printf("%d\n",R-1);
    /*
    int l=0;int h=R;
    while(l+1<h)
    {
	    int mid=(l+h)/2;
	    if(verify(mid))
		    l=mid;
	    else h=mid-1;
    }
    int ans=l;
    if(verify(h))
	    ans=h;
    printf("%d\n",ans);*/
	    
    return 0;
}

