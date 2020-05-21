/*
ID: wangyu.1
LANG: C++11
TASK: barn1
*/
#define TASKNAME "barn1"

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
int main() 
{
#ifndef TEST
	freopen (TASKNAME".in", "r",stdin);
	freopen (TASKNAME".out", "w",stdout);
#endif	
	int m,s,c;
	scanf("%d %d %d",&m,&s,&c);
	vector<int> vec;
	for(int i=0;i<c;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		vec.push_back(tmp);
	}	
	sort(vec.begin(),vec.end());
	int my_min=vec[0];
	int my_max=vec[vec.size()-1];
	int blocked=my_max-my_min+1;
	vector<int> vec2;
	for(int i=1;i<vec.size();i++)
	{
		vec2.push_back(vec[i]-vec[i-1]);
	}
	sort(vec2.begin(),vec2.end());
	reverse(vec2.begin(),vec2.end());	
	for(int i=0;i<m-1;i++)
	{
		if(i>=vec2.size()) break;
		blocked-=(vec2[i]-1);
	}
	printf("%d\n",blocked);
	return 0;
}
