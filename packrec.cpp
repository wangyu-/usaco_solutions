/*
  ID: wangyu.1
  LANG: C++11
  TASK: packrec
*/
#define TASKNAME "packrec"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <vector>
#include <queue>
#include <deque>
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
struct rec_t
{
    int h,w;
    rec_t rotate(int rot)
    {
	rec_t res;
	if(rot==0)
	    res=*this;
	else
	{
	res.w=h;
	res.h=w;
	}
	return res;
    }
}rs[4];
int used[4]={0};
int choice[4];
int best=9999*9999;
vector<rec_t> ans;
int my_max(int a,int b,int c=0,int d=0)
{
    return max(max(a,b),max(c,d));
}
void verify()
{
    rec_t r[4];
    for(int i=0;i<16;i++)
    {
	for(int j=0;j<4;j++)
	{
	    r[j]=rs[choice[j]].rotate((i>>j)&0x1);
	}
	rec_t &a=r[0];
	rec_t &b=r[1];
	rec_t &c=r[2];
	rec_t &d=r[3];
	int w[10];
	int h[10];
	w[0]=a.w+b.w+c.w+d.w;
	h[0]=my_max(a.h,b.h,c.h,d.h);
	w[1]=my_max(a.w+b.w+c.w,d.w);
	h[1]=my_max(a.h,b.h,c.h)+d.h;
	w[2]=my_max(a.w+b.w,c.w)+d.w;
	h[2]=my_max(my_max(a.h,b.h)+c.h,d.h);
	w[3]=a.w+my_max(b.w,c.w)+d.w;
	h[3]=my_max(a.h,b.h+c.h,d.h);
	w[4]=9999;
	h[4]=9999;
	w[5]=my_max(a.w+b.w,c.w+d.w,a.w+c.w,b.w+d.w);
	h[5]=my_max(a.h+c.h,b.h+d.h,a.h+d.h,b.h+c.h);
	if(a.h>=b.h&&d.h>=c.h&&c.w>=a.w&&b.w>=d.w)
	{
	    w[5]=my_max(a.w+b.w,c.w+d.w);
	    h[5]=my_max(a.h+c.h,b.h+d.h);
	}
	w[6]=my_max(a.w+b.w,c.w+d.w);
	h[6]=my_max(a.h,b.h)+max(c.h,d.h);
	int idx;
	for(int j=0;j<7;j++)
	{
	    int area=w[j]*h[j];
	    //printf("<%d>",area);
	    if(area<best)
	    {
		ans.clear();
		best=area;
		//idx=j;
	    }
	    if(area==best)
	    {
		ans.emplace_back();
		ans.back().w=min(w[j],h[j]);
		ans.back().h=max(w[j],h[j]);
	    }
	}
    }
}
void dfs(int depth=0)
{
    if(depth==4)
    {
	verify();
	return ;
    }
    for(int i=0;i<4;i++)
    {
	if(used[i]) continue;
	used[i]=1;
	choice[depth]=i;
	dfs(depth+1);
	used[i]=0;
    }
}
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif
    for(int i=0;i<4;i++)
    {
	scanf("%d %d",&rs[i].h,&rs[i].w);
    }
    dfs();
    printf("%d\n",best);
    sort(ans.begin(),ans.end(),[](rec_t &a,rec_t &b){return a.w<b.w;});
    auto it=unique(ans.begin(),ans.end(),[](rec_t &a,rec_t &b){return a.w==b.w;});
    ans.erase(it,ans.end());
    for(int i=0;i<ans.size();i++)
    {
	printf("%d %d\n",ans[i].w,ans[i].h);
    }


    return 0;
}

