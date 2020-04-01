/*
ID: wangyu.1
LANG: C++11
TASK: socdist1
*/
#define TASKNAME "exercise"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#ifdef TEST
int test=1;
#else
int test=0;
#endif

int m;
#define lint long long
lint ex_gcd(lint a,lint b,lint &x,lint &y)//扩展欧几里得（扩展gcd）
{
	if (a==0&&b==0) return -1;
	if (b==0){x=1;y=0;return a;}
	lint d=ex_gcd(b,a%b,y,x);
	y-=a/b*x;
	return d;
}
 
lint mod_inverse(lint a,lint n)//乘法逆元
{
	lint x,y;
	lint d = ex_gcd(a,n,x,y);
	return (x%n+n)%n;
}
map<int,int> cache;
long long binpow(long long a, long long b) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res%m;
}

long long gcd(long long a, long long b) {   //from wiki
	a%=m;
	b%=m;
	if(b) while((a %= b) && (b %= a));
	return (a + b)%m;
}
long long lcm(long long a, long long b) {
	a%=m;
	b%=m;
	return ( ((a* b)%m)  *  mod_inverse(gcd(a, b),m-2)  )%m;
}

int main() 
{
#ifndef TEST
	freopen (TASKNAME".in", "r",stdin);
	freopen (TASKNAME".out", "w",stdout);
#endif
	map<long long,long long> mp;
	int n;long long sum=0;
	scanf("%d %d",&n,&m);
	for(long long i=1;i<=n;i++)
	{
		mp[i]=i;
	}
	while(1)
	{
		int cnt=0;
		for(long long i=1;i<=n;i++)
		{
			for(auto it=mp.begin();it!=mp.end();it++)
			{
				long long j=it->first;
				long long result=lcm(i,j)%m;
				long long sum=it->second+i;
				if(sum>n) continue;
				if(mp.find(result)==mp.end())
				{
					mp[result]=sum;
				}
				else
				{
					if(sum<mp[result])
					{
						mp[result]=sum;
					}
				}
			}
		}
		if(cnt==0) break;
	}
	long long real_sum=0;
	for(auto it=mp.begin();it!=mp.end();it++)
	{
		if(test)printf("<%lld>",it->first);
		real_sum+=it->first;
		real_sum%=m;
	}
	printf("%lld\n",real_sum);
	return 0;
}

