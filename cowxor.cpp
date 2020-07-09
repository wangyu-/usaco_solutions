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
const int nb=21; 
int state[1024*1024*2+5]={0}; 
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
	    if(cnt[j]%2!=0)
		set_bit(mask,j);
	    if(get_bit(goal,j)!=0)
		set_bit(goal2,j);
	}
	if(ok&&state[goal2^mask])
	{
	    if(test)printf("<%d>",i);
	    //printf("<result=%d>\n",1);
	    to=i;
	    from=state[goal2^mask];
	    
	    return 1;
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
    //xacc[0]=0;
    for(int i=1;i<=n;i++)
    {
	scanf("%d",&num[i]);
    }
    for(int i=1;i<=n;i++)
    {
	test&&printf("<%s>",bin(num[i],8).c_str());
    }
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
	    //verify(guess,len);
	}
    }
    if((guess&0x1)==0) verify(guess,nb); //set from and to
    printf("%d %d %d\n",guess,from,to);
    

    return 0;
}

