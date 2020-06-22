/*
  ID: wangyu.1
  LANG: C++11
  TASK: shopping 
*/
#define TASKNAME "shopping"

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


int dp[10][10][10][10][10]={0};
struct sp_t
{
    int n;
    map<int,int> mp;
    int not_ok=0;
    int p;
    int reduce;
};
vector<sp_t> sps;
map<int,int>price;
map<int,int>to_buy;
int total=0;
int ic[5]={1001,1002,1003,1004,1005};
int in[5]={0};
int ok(int a[5])
{
    for(int i=0;i<5;i++)
    {
	if(a[i]<0) return  0;
    }
    return 1;
}
int & dd(int a[5])
{
    return dp[a[0]][a[1]][a[2]][a[3]][a[4]];
}
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif

    int s;
    scanf("%d",&s);
    for(int i=0;i<s;i++)
    {
	sp_t sp;
	int &n=sp.n;
	map<int,int>& mp=sp.mp;
	int &p=sp.p;
	scanf("%d",&n);
	for(int j=0;j<n;j++)
	{
	    int c,k;
	    scanf("%d %d",&c,&k);
	    mp[c]=k;
	}
	scanf("%d",&p);
	sps.push_back(sp);
    }
    int b;
    scanf("%d",&b);
    for(int i=0;i<b;i++)
    {
	int c,k,p;
	scanf("%d %d %d",&c,&k,&p);
	price[c]=p;
	to_buy[c]=k;
	total+=p*k;
    }
    for(int i=0;i<(int)sps.size();i++)
    {
	sp_t &sp=sps[i];
	for(auto it=sp.mp.begin();it!=sp.mp.end();it++)
	{
	    int c=it->first;
	    if(to_buy.find(c)==to_buy.end())
		sp.not_ok=1;
	    
	}
	if(sp.not_ok==1) continue;
	int sum=0;
	for(auto it=sp.mp.begin();it!=sp.mp.end();it++)
	{
	    sum+=price[it->first]*it->second;
	}
	sp.reduce=sum-sp.p;
    }
    int idx=0;
    for(auto it=to_buy.begin();it!=to_buy.end();it++,idx++)
    {
	ic[idx]=it->first;
	in[idx]=it->second;
    }
    int i[5];
    int bb=0;
    for(i[0]=0;i[0]<=in[0];i[0]++)
    for(i[1]=0;i[1]<=in[1];i[1]++)
    for(i[2]=0;i[2]<=in[2];i[2]++)
    for(i[3]=0;i[3]<=in[3];i[3]++)
    for(i[4]=0;i[4]<=in[4];i[4]++)
    {
	int best=0;
	for(int u=0;u<(int)sps.size();u++)
	{

	    sp_t &sp=sps[u];
	    if(sp.not_ok) continue;
	    int j[5];
	    memcpy(j,i,sizeof(i));
	    for(int v=0;v<5;v++)
	    {
		if(sp.mp.find(ic[v])!=sp.mp.end())
		{
		    j[v]-=sp.mp[ic[v]];
		}
	    }
	    if(ok(j)==0)continue;
	    int current=dd(j)+sp.reduce;
	    if(current>best)
		best=current;
	     
	}
	dd(i)=best;
	if(best>bb)
	    bb=best;
    }
    printf("%d\n",total-bb);
	    
    
    return 0;
}

