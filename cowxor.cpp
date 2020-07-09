/*
  ID: wangyu.1
  LANG: C++11
  TASK: cowxor
*/
#define TASKNAME "cowxor"

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
int test=0;
#else
int test=0;
#endif

int n;
int num[100*1000+5];
//int xx[100+5][100+5];
int xacc[100*1000+5];
int cnt[20+5]={0};
string bin(int a,int len)
{
    string res;
    for(int i=len-1;i>=0;i--)
    {
	res+=(a>>i&0x1)?'1':'0';
    }
    return res;
}
int state[1024*1024*2+5]={0};
const int nb=21;
int get_bit(int a,int idx)
{
    return a>>(nb-1-idx)&0x1;
}
void set_bit(int &a,int idx)
{
    a|= 0x1<<(nb-1-idx);
}
void clr_bit(int &a,int idx)
{
    a&= ~(0x1<<(nb-1-idx));
}
int from,to;
int verify(int goal,int len)
{
    //printf("{verify,%s,%d}\n",bin(goal,nb).c_str(),len);
    memset(state,0,sizeof(state));
    memset(cnt,0,sizeof(cnt));
    state[0]=1;
    
    for(int i=1;i<=n;i++)
    {
	int mask=0;
	//int diff=0;
	int goal2=0;
	int ok=1;
	for(int j=0;j<len;j++)
	{
	    int nn=num[i];
	    int off=nb-1-j;
	    cnt[j]+=get_bit(nn,j);
	    if(get_bit(goal,j)==1&&cnt[j]<1)
		ok=0;
	    if(cnt[j]%2!=cnt[0]%2)
		set_bit(mask,j);
	    //if(get_bit(nn,j)!=get_bit(nn,0))
	    //set_bit(diff,j);
	    if(get_bit(goal,j)!=get_bit(goal,0))
		set_bit(goal2,j);
	}
	//int ok2=0;
	//ff(get_bil(goal2,0)==cnt[0])
	if(ok&&state[goal2^mask])
	{
	    /*
	    for(int j=0;j<len;j++)
	    {
		printf("<%d>",cnt[j]);
	    }
	    printf("\n");
	    printf("<%s %s>",bin(mask,nb).c_str(),bin(goal2,nb).c_str());*/
	    if(test)printf("<%d>",i);
	    //printf("<result=%d>\n",1);
	    to=i;
	    from=state[goal2^mask];
	    
	    int r=0;
	    /*for(int i=from;i<=to;i++)
	    {
		r^=num[i];
		}*/
	    r=xacc[to]^xacc[from-1];
	    for(int j=len;j<nb;j++)
		clr_bit(r,j);
	    if(r==goal)
	    {
		return 1;
	    }
	    else
	    {
		assert(r=~goal);
	    }
	    //printf("%d\n",r);
	    //if(r!=0)
	}
	state[mask]=i+1;
    }
    //printf("<result=%d>\n",0);
    return 0;
}
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif           
    scanf("%d",&n);
    xacc[0]=0;
    for(int i=1;i<=n;i++)
    {
	scanf("%d",&num[i]);
	xacc[i]=xacc[i-1]^num[i];
    }
    for(int i=1;i<=n;i++)
    {
	test&&printf("<%s>",bin(num[i],8).c_str());
    }
    test&&printf("\n");
    /*
    if(test)
    for(int i=1;i<=n;i++)
    {
	for(int j=1;j<=n;j++)
	{
	    if(j>=i)
	    printf("[%s]",bin(xacc[j]^xacc[i-1],8).c_str());
	    else
	    printf("[%s]",bin(0,8).c_str());
	}
	printf("\n");
	}*/
    test&&printf("\n");

    int guess=0;
    for(int i=0;i<nb;i++)
    {
	int len=i+1;
	test&&printf("====len=%d====\n",len);
        set_bit(guess,i);
	if(verify(guess,len))
	{
	}
	else
	{
	    clr_bit(guess,i);
	    verify(guess,len);
	}
    }
    printf("%d %d %d\n",guess,from,to);
    int r=0;
    for(int i=506;i<=1094;i++)
    {
	r^=num[i];
    }
    //printf("%d\n",r);
    r=0;
    for(int i=2995;i<=3773;i++)
    {
	r^=num[i];
    }
    //printf("%d\n",r);
    

    return 0;
}

