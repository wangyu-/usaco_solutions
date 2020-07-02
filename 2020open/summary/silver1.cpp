/*
ID: wangyu.1
LANG: C++11
TASK: socdist1
*/
#define TASKNAME "socdist"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
struct edge_t
{
	long long a,b;
};
bool cmp(const edge_t& x, const edge_t &y)
{
	return x.a<y.a;
}
const long long range=10000ll*10000ll*10000ll*10000ll*100+5;
int verify(long long  d, vector<edge_t> &e,int n)
{
#ifdef TEST
	printf("--------------%lld-------------\n",d);
#endif
	long long last=-range;
	int cnt=0;
	for(int i=0;i<e.size();i++)
	{
		long long a=e[i].a;int b=e[i].b;
		while(b-last>=d)
		{
			if(a-last>=d)
			{
				cnt++;
				last=a;
#ifdef TEST
				printf("<<%d>>",last);

#endif
			}
			else
			{
				cnt++;
				last=last+d;
#ifdef TEST
				printf("<%d>",last);
#endif
			}
			if(cnt==n) return 1;
		}
	
	}
	return -1;
}
int main() 
{
#ifndef TEST
	freopen (TASKNAME".in", "r",stdin);
	freopen (TASKNAME".out", "w",stdout);
#endif
	int n,m;
	vector<edge_t> e;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		edge_t tmp;
		long long a,b;
		scanf("%lld %lld",&a,&b);
		tmp.a=a;tmp.b=b;
		e.push_back(tmp);
	}
	sort(e.begin(),e.end(),cmp);	
	long long low=1;
	long long high=10000ll*10000ll*10000ll*10000ll*100+5;
	int r1,r2,r3;
	//r1=verify(1,e,n);
	//r2=verify(2,e,n);
	//r3=verify(3,e,n);
	//printf("%d %d %d\n",r1,r2,r3);
	while(high-low>1)
	{
		long long mid=(low+high)/2;
		if(verify(mid,e,n)==1) low=mid;
		else high=mid-1; 
	}
	long long res;
	if(verify(high,e,n)==1) res=high;
	else res=low;
	printf("%lld\n",res);
	return 0;
}

