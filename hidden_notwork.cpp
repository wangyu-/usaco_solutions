/*
  ID: wangyu.1
  LANG: C++11
  TASK: hidden
*/
#define TASKNAME "hidden"

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

int n;
char s[100000*2+5];
//char s0[100000+5];
int len[100000*2+5];
//vector<int> cd;
//bool cd[100000+5];
vector<int> cd;
char get_min(int offset)
{
    char c=127;
    for(int i=0;i<cd.size();i++)
    {	
	int idx=cd[i]+offset;
	if(s[idx]<c)
	    c=s[idx];
    }
    return c;
}
int get_len(char c,int offset)
{
    int best=0;
    for(int i=2*n-1;i>=0;i--) //can be optimized to O(cd.size())
    {
	if(s[i]==c)
	{
	    len[i]=1;
	    if(i!=2*n-1)
		len[i]+=len[i+1];
	    if(len[i]>n-offset)
		len[i]=n-offset;
	}
	else len[i]=0;
    }
    for(int i=0;i<cd.size();i++)
    {
	int idx=cd[i];
	best=max(best,len[idx+offset]);
    }
    assert(best!=0);
    return best;
}

int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin); freopen (TASKNAME".out", "w",stdout);
#endif           
    
    //auto c=& &s;
    //printf("%ld %ld\n",long(s),long(&s));
    scanf("%d",&n);
    string s0;
    while(1)
    {
	char buf[80];
	if(scanf("%s",buf)!=1) break;
	s0+=buf;
    }
    s[0]=0;
    //scanf("%s",s);
    //strcpy(s0,s);
    strcat(s,s0.c_str());
    strcat(s,s0.c_str());
    for(int i=0;i<n;i++)
    {
	//cd[i]=1;
	cd.push_back(i);
    }
    int offset=0;
    for(int round=0;;round++)
    {
	//if(round>300) break;
	if(offset==n) break;
	if(cd.size()==1) break;
	char c=get_min(offset);
	//if(c==127) {printf("!!!\n");break;}
	int best_len=get_len(c,offset);
	//if(test)printf("<best_c=%c best_len=%d offset=%d>\n",c,best_len,offset);
	vector<int> tmp=cd;
	cd.clear();
	for(int i=0;i<tmp.size();i++)
	{
	    int idx=tmp[i];
	    if(len[idx+offset]==best_len)
	    {
		cd.push_back(idx);
		//if(test) printf("<%d>",idx);
		//cd[idx]=0;
	    }
	}
	//if(test) printf("\n");
	offset+=best_len;
	
    }
    printf("%d\n",cd[0]);

    //printf("%d",strlen(s));


    return 0;
}

