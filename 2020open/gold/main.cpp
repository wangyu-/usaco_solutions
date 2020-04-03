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
#include <math.h>
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


int max_prime;
bool is[10000+100]; int prm[10000+50];
int getprm(int n){   //old tempate
	int i, j, k = 0;
	//prm[k++]=1;
	int s, e = (int)(sqrt(0.0 + n) + 1);
	memset(is, 1, sizeof(is));
	prm[k++] = 2; is[0] = is[1] = 0;
	for (i = 4; i < n; i += 2) is[i] = 0;
	for (i = 3; i < e; i += 2) if (is[i]) {
		prm[k++] = i;
		for (s = i * 2, j = i * i; j < n; j += s) is[j] = 0;
		// 因为j是奇数，所以+奇数i后是偶数，不必处理！
	}
	for ( ; i < n; i += 2) if (is[i]) prm[k++] = i;
	return k; // 返回素数的个数
}

const int dp_mod=2;
long long dp[dp_mod][10000+50]; 
int main() 
{
#ifndef TEST
	freopen (TASKNAME".in", "r",stdin);
	freopen (TASKNAME".out", "w",stdout);
#endif
 	max_prime=getprm(10000+50);
	//prm[0]=2;
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<max_prime;i++)
	{
		if(prm[i]>n) {max_prime=i;break;}
	}
	if(test)
	{
		for(int i=0;i<max_prime;i++)
			printf("<%d>",prm[i]);
		printf("\n");
	}
	memset(dp,0,sizeof(dp));
	for(int j=0;j<=n;j++)
	{
		dp[1%dp_mod][j]=1;
	}
	for(int i=0;i<max_prime;i++)
	{
		int p=prm[i];
		long long amt=1;
		int sum=0;
		for(int j=0;j<=n;j++)
		{
			dp[(i+2)%dp_mod][j]=dp[(i+1)%dp_mod][j];
		}
		//for(int j=0;j<=n;j++)
		{
			for(amt=p;amt<=n;amt*= p)
			{
				/*if(j>=amt)
				{
					dp[i+2][j]+=dp[i+1][j-amt]*amt;
					dp[i+2][j]%=m;
				}*/
				
				for(int j=amt;j<=n;j++)
				{
					dp[(i+2)%dp_mod][j]+=dp[(i+1)%dp_mod][j-amt]*amt;
					dp[(i+2)%dp_mod][j]%=m;
				}
			}
		}
	}


	printf("%lld\n",dp[(max_prime+1)%dp_mod][n]);

	
	return 0;
}

