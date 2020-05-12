/*
ID: wangyu.1
LANG: C++11
TASK: palsquare
*/
#define TASKNAME "palsquare"

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
char to_char(int a)
{
	if(a<=9) return '0' +a;
	else return 'A'+a-10;
}
string to_string(int a,int b)
{
	string res;
	while(1)
	{
		res.push_back(to_char(a%b));
		a/=b;
		if(a==0) break;
	}
	reverse(res.begin(),res.end());
	return res;
}
int pa(string &a)
{
	for(int i=0,j=a.length()-1;i<j;i++,j--)
	{
		if(a[i]!=a[j]) return 0;
	}
	return 1;
}
int main() 
{
#ifndef TEST
	freopen (TASKNAME".in", "r",stdin);
	freopen (TASKNAME".out", "w",stdout);
#endif
	int b;
	scanf("%d",&b);
	for(int i=1;i<=300;i++)
	{
		string r=to_string(i*i,b);
		if(pa(r))
		{
			printf("%s %s\n",to_string(i,b).c_str(),r.c_str());
		}
	}
	
	return 0;
}

