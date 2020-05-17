/*
ID: wangyu.1
LANG: C++11
TASK: crypt1
*/
#define TASKNAME "crypt1"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
#ifdef TEST
int test=1;
#else
int test=0;
#endif
int hh[255+10]={0};
int verify_ok(int r,int len)
{
		int ok=1;
		for(int x=0;x<len;x++)
		{
			int y=r%10;
			r=r/10;
			if(hh[y]==0){ok=0;break;}
		}
		if(r!=0) ok=0;
		return ok;
	
}
int main() 
{
#ifndef TEST
	freopen (TASKNAME".in", "r",stdin);
	freopen (TASKNAME".out", "w",stdout);
#endif	
	int n;
	scanf("%d",&n);
	vector<int> d;
	for(int i=0;i<n;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		d.push_back(tmp);
		hh[tmp]=1;
	}
	int cnt=0;
	for(int i=0;i<d.size();i++)
	for(int j=0;j<d.size();j++)
	for(int u=0;u<d.size();u++)
	for(int v=0;v<d.size();v++)
	for(int w=0;w<d.size();w++)
	{
		int a=d[i]*10+d[j];
		int b=d[u]*100+d[v]*10+d[w];
		int r=a*b;
		if(r>9999) continue;
		if(verify_ok(r,4) &&verify_ok(b*d[j],3)&&verify_ok(b*d[i],3))
		{
			cnt++;
		//	printf("%d %d %d\n",a,b,a*b);
		}
	}
	printf("%d\n",cnt);
	return 0;
}
