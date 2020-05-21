/*
ID: wangyu.1
LANG: C++11
TASK: namenum
*/
#define TASKNAME "namenum"

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

int to_num[255+10]={0};
void init_data(string a,int num)
{
	for(auto i:a)
	{
		to_num[i]=num;
	}
}
string trans(string a)
{
	string r;
	for(auto i:a)
	{
		r.push_back('0'+to_num[i]);
	}
	return r;
}
map<string,vector<string>> mp;
int main() 
{
	init_data("ABC",2);
	init_data("DEF",3);
	init_data("GHI",4);
	init_data("JKL",5);
	init_data("MNO",6);
	init_data("PRS",7);
	init_data("TUV",8);
	init_data("WXY",9);
	FILE *fp=fopen ("dict.txt", "r");
	assert(fp);
	char s[100];
	int cnt=0;
	while(fscanf(fp,"%s",s)==1)
	{
		cnt++;
		//printf("%s\n",trans(s).c_str());	
		string key=trans(s);
		mp[key].push_back(s);
	}
	//printf("<%d>",cnt);
	fclose(fp);
	
#ifndef TEST
	freopen (TASKNAME".in", "r",stdin);
	freopen (TASKNAME".out", "w",stdout);
#endif
	scanf("%s",s);
	vector<string > &value=mp[s];
	//printf("<%s>",s);
	if(value.size()==0) value.push_back("NONE");
	for(auto i:value)
	{
		printf("%s\n",i.c_str());	
	}
	
	return 0;
}

