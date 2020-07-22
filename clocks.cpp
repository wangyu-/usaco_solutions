/*
  ID: wangyu.1
  LANG: C++11
  TASK: clocks
*/
#define TASKNAME "clocks"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>
#include <math.h>
#include <typeinfo>
#include <iostream>
using namespace std;

#ifdef TEST
int test=1;
#else
int test=0;
#endif
int N;

char affect[9][9]={"ABDE","ABC","BCEF","ADG","BDEFH","CFI","DEGH","GHI","EFHI"};

int cl[9];
int op_cnt[9];
map<int,vector<string> > mp;
int verify_ok()
{
	int cc[9];
	memcpy(cc,cl,sizeof(cl));
	for(int i=0;i<9;i++)  //for each op
	{
		for(int j=0;affect[i][j];j++)
		{
			cc[affect[i][j]-'A']+=op_cnt[i];
		}
	}
	for(int i=0;i<9;i++)
	{
		if(cc[i]%4!=0) return 0;
	}
	return 1;
}
void dfs(int depth)
{
	if(depth==9)
	{
		if(verify_ok())
		{
			int sum=0;
			string tmp;
			for(int i=0;i<9;i++)
			{
				sum+=op_cnt[i];
				for(int j=0;j<op_cnt[i];j++)
				{
					if(tmp!="") tmp+=' ';
					tmp+='1'+i;
				}
			}
			mp[sum].push_back(tmp);
			//printf("<%d>",sum);
		}	
		return ;
	}
	for(int i=0;i<4;i++)
	{
		op_cnt[depth]=i;
		dfs(depth+1);
	}
}
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif           
    for(int i=0;i<9;i++)
    {
	    scanf("%d",&cl[i]);
	    cl[i]/=3;
	    cl[i]%=4;
    }
    dfs(0);
    vector<string> &v=mp[mp.begin()->first];
    sort(v.begin(),v.end());
    string &s=v[0];
    printf("%s\n",s.c_str());
    return 0;
}

