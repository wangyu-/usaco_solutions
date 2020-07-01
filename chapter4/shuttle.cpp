/*
  ID: wangyu.1
  LANG: C++11
  TASK: shuttle
*/
#define TASKNAME "shuttle"

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
using namespace std;

#ifdef TEST
int test=1;
#else
int test=0;
#endif
typedef unsigned char u8;
typedef unsigned int u32;
int n;
void set_bit(unsigned int &a,int p,bool v)
{
    if(v==0)
    {
	a&=~(1u<<p);
    }
    else
    {
	a|=(1u<<p);
    }
}
bool get_bit(unsigned &a,int p)
{
    return (a&1u<<p)!=0;
}
u8 glc(unsigned int &a)
{
    return (u8)(a>>24);
}
void slc(u32 &a,u8 c)
{
    a&=0x00ffffff;
    a|=c<<24u;
}

struct state_t
{
    unsigned int s=0;
    u8 get_p()
    {
	return glc(s);
    }
    void set_as_init()
    {
	for(int i=0;i<n;i++)
	    set_bit(s,i,1);
	for(int i=n;i<2*n;i++)
	    set_bit(s,i,0);
	slc(s,n);
    }
    void set_as_goal()
    {
	for(int i=0;i<n;i++)
	    set_bit(s,i,0);
	for(int i=n;i<2*n;i++)
	    set_bit(s,i,1);
	slc(s,n);
	
    }
    void next_state(state_t *r)
    {
	memset(r,0,sizeof(state_t)*4);
	u8 p=glc(s);
	if(p>0)
	{
	    bool m1=get_bit(s,p-1);
	    if(m1==1)
	    {
		r[2].s=s;
		slc(r[2].s,p-1);
	    }
	    //p-1
	}
	if(p<2*n)
	{
	    bool m1=get_bit(s,p);
	    if(m1==0)
	    {
	    r[1].s=s;
	    slc(r[1].s,p+1);
	    }
	    //p+1
	}
	if(p>=2)
	{
	    bool m1=get_bit(s,p-1),m2=get_bit(s,p-2);
	    if(m1!=m2)
	    {
		if(m2==1)
		{
		    r[3].s=s;
		    slc(r[3].s,p-2);
		    set_bit(r[3].s,p-1,m2);
		    set_bit(r[3].s,p-2,m1);
		    r[1].s=0;
		    r[2].s=0;
		}
	    }
	    //p-2
	}
	if(p<=2*n-2)
	{
	    bool m1=get_bit(s,p+1),m2=get_bit(s,p);
	    if(m1!=m2)
	    {
		if(m2==1)
		{
		    r[0].s=s;
		    slc(r[0].s,p+2);
		    set_bit(r[0].s,p+1,m2);
		    set_bit(r[0].s,p,m1);
		    r[1].s=0;
		    r[2].s=0;
		}
		//p+2
	    }
	}
	
    }
    void prt()
    {
	if(test) printf("<%x>\n",s);
    }
}init,goal;
int get_move(int p, int idx)
{
    int a[4]={+2,+1,-1,-2};
    int r=p+a[idx];
    return 2*n+1-r;
}
unordered_map<u32,u32> hh;
int dfs(state_t s,int depth)
{
    //if(test) printf("!");
    if(s.s==goal.s)
    {
	if(test) printf("ok");
	return 1;
    }
    if(depth==0) return 0;
    state_t ns[4];
    s.next_state(ns);
    for(int i=0;i<4;i++)
    {
	if(ns[i].s!=0)
	    if(dfs(ns[i],depth-1)) return 1;
    }
    return 0;
}
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif
    //for(int i=0;i<32;i++)
    //mask[i]=1u<<i;
    //printf("<%d>",0|(1u<<1));

    scanf("%d",&n);
    init.set_as_init();
    goal.set_as_goal();
    init.prt();
    goal.prt();
    state_t ns[4];
    init.next_state(ns);
    for(int i=0;i<4;i++)
	ns[i].prt();

    queue<state_t> q;
    q.push(init);
    while(!q.empty())
    {
	state_t e=q.front();
	q.pop();
	e.next_state(ns);
	for(int i=0;i<4;i++)
	{
	    if(ns[i].s!=0)
	    {
		auto it=hh.find(ns[i].s);
		if(it!=hh.end())
		{
		    continue;
		}
		int p=glc(e.s);
		hh[ns[i].s]=e.s;
		if(ns[i].s==goal.s) goto end;
		q.push(ns[i]);
	    }
	}
    }
end:
    if(test) printf("--------\n");
    state_t x=goal;
    vector<int> res;
    for(int i=0;;i++)
    {
	if(x.s==init.s) break;
	state_t pre;
	pre.s=hh[x.s];
	//x.prt();
	state_t ns[4];
	pre.next_state(ns);
	for(int j=0;j<4;j++)
	{
	    if(ns[j].s==x.s)
	    {
		res.push_back(get_move(pre.get_p(),j));
	    }
	}
	x.s=pre.s;
    }
    reverse(res.begin(),res.end());
    for(int i=0;i<(int)res.size();i++)
    {
	if(i&&i%20==0) printf("\n");
	if(i%20!=0) printf(" ");
	printf("%d",res[i]);
    }
    printf("\n");
    if(test) printf("<<%d>>\n",(int)hh.size());
    /*
    for(int i=0;;i++)
    {
	if(dfs(init,i))
	{
	    printf("%d\n",i);
	    break;
	}
	}*/
    
    
    return 0;
}

