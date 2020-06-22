/*
  ID: wangyu.1
  LANG: C++11
  TASK: msquare
*/
#define TASKNAME "msquare"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <math.h>
using namespace std;

#ifdef TEST
int test=1;
#else
int test=0;
#endif


struct sq_t
{
    char a[10]={0};
    int eq(sq_t other)
	{
	    char *b=other.a;
	    if(memcmp(a,b,10)==0) return 1;
	    return 0;
	}
    
    void prt()
	{
	    if(test) printf("<%s>",a+1);
	}
    string step;
    int hash()
	{
	    int res=0;
	    for(int i=1;i<=7;i++)
	    {
		res+=(a[i]-'0');
		res*=10;
	    }
	    return res;
	}

    sq_t trans(int type)
	{
	    sq_t res=(*this);
	    char *x=this->a;
	    char *a=res.a;
	    int t;
	    switch(type)
	    {
	    case 0:
		swap(a[4],a[5]);
		swap(a[3],a[6]);
		swap(a[2],a[7]);
		swap(a[1],a[8]);
		break;
	    case 1:
		t=a[4];
		a[4]=a[3];
		a[3]=a[2];
		a[2]=a[1];
		a[1]=t;
		t=a[5];
		a[5]=a[6];
		a[6]=a[7];
		a[7]=a[8];
		a[8]=t;
		break;
	    case 2:
		a[2]=x[7];
		a[3]=x[2];
		a[7]=x[6];
		a[6]=x[3];
	
		break;
	    }
	    return res;
    
	}
};
void swap(char &a,char&b)
{
    char t=a;
    a=b;
    b=t;
}
sq_t goal;
sq_t init;

unordered_set <int> hh;

int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif
    char *a=goal.a;
    for(int i=1;i<=8;i++)
    {
	init.a[i]='0'+i;
	int t;
	scanf("%d",&t); 
	a[i]='0'+t;
    }

    queue<sq_t> q;
    q.push(init);
    hh.insert(init.hash());
    while(!q.empty())
    {
	sq_t e=q.front();
	q.pop();
	if(e.eq(goal))
	{
	    printf("%d\n%s\n",(int)e.step.length(),e.step.c_str());
	    return 0;
	}
	for(int i=0;i<3;i++)
	{
	    sq_t new_e=e.trans(i);
	    new_e.step+='A'+i;
	    int h=new_e.hash();
	    if(hh.find(h)!=hh.end())
	    {
		continue;
	    }
	    hh.insert(h);
	    q.push(new_e);
	}
    }
    
    return 0;
}

