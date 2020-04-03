/*
ID: wangyu.1
LANG: C++11
TASK: socdist1
*/
#define TASKNAME "socdist1"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
char s[100*1000+5];
int main() 
{
#ifndef TEST
	freopen (TASKNAME".in", "r",stdin);
	freopen (TASKNAME".out", "w",stdout);
#endif
	int n;
	scanf("%d",&n);
	scanf("%s",s);
	s[n]=0;
	strcat(s,"1");
	vector<int> dis;
	int cnt=1;
	for(int i=0;s[i]!=0;i++)
	{
		if(s[i]=='1')
		{ 
			dis.push_back(cnt);
			cnt=1;
		}
		else
		{
			cnt++;
		}
		
	}
#ifdef TEST
	for(int i:dis)
	{
		printf("<%d>",i);
	}
	printf("\n");
#endif
	int left=dis[0];
	int right=dis[dis.size()-1];
	if(dis.size()==1) 
	{
		printf("%d\n",dis[0]-2);
		return 0;
	}
	int min_d=10000*10000;
	int max_d=0;
	int max_middle_d=0;
	for(int i=0;i<dis.size();i++)
	{
		if(dis[i]>max_d) max_d=dis[i];
		if(i!=0&&i!=dis.size()-1)
		{
			if(dis[i]<min_d) min_d=dis[i];
			if(dis[i]>max_middle_d)
				max_middle_d=dis[i];
		}
	}
	int max_new_d=0;
	int tmp;
	tmp=(left-1)/2;
	//printf("[%d]",tmp);
	if(tmp>max_new_d) max_new_d=tmp;
	tmp=(right-1)/2; 
	//printf("[%d]",tmp);
	if(tmp>max_new_d) max_new_d=tmp;
	tmp=max_middle_d/3;
	//printf("[%d]",tmp);
	if(tmp>max_new_d) max_new_d=tmp;
	for(int i=1;i<dis.size()-1;i++)
	{
		dis[i]/=2;
	}
	dis[0]=dis[0]-1;
	dis[dis.size()-1]=dis[dis.size()-1]-1;
	sort(dis.begin(),dis.end());
	reverse(dis.begin(),dis.end());
	tmp=dis[1];
	//printf("[%d]",tmp);
	if(tmp>max_new_d) max_new_d=tmp;
	
	if(max_new_d<min_d) min_d=max_new_d;
	printf("%d\n",min_d);
	return 0;
}

