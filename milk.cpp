/*
ID: wangyu.1
LANG: C++11
TASK: milk 
*/
#define TASKNAME "milk"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <iostream>
using namespace std;
#ifdef TEST
int test=1;
#else
int test=0;
#endif
struct farmer_t
{
	int p;
	int v;
};
int cmp(const farmer_t &a,const farmer_t &b)
{
	return a.p<b.p;
}
int main() 
{
#ifndef TEST
	freopen (TASKNAME".in", "r",stdin);
	freopen (TASKNAME".out", "w",stdout);
#endif
	int n,m;
	cin>>n>>m;
	vector<farmer_t> vec;
	for(int i=0;i<m;i++)
	{
		farmer_t tmp;
		cin>>tmp.p>>tmp.v;
		vec.push_back(tmp);
	}
	sort(vec.begin(),vec.end(),cmp);
	//reverse(vec.begin(),vec.end());
	int sum=0;
	int left=n;
	for(int i=0;i<vec.size();i++)
	{
		int price=vec[i].p;
		if(vec[i].v>=left)
		{
			sum+=price*left;
			left=0;
			break;
		}
		else
		{
			left-=vec[i].v;
			sum+=price*vec[i].v;
				
		}
	}
	cout<<sum<<endl;
	
	
	return 0;
}
