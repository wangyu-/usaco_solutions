/*
  ID: wangyu.1
  LANG: C++11
  TASK: prime3
*/
#define TASKNAME "prime3"

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
bool is_p[100005];
const int max_p=100000;
void init_prime()
{
	memset(is_p,1,sizeof(is_p));
	is_p[0]=0;is_p[1]=0;
	for(int i=2;i*i<=max_p;i++)
	{
		if(is_p[i])
		{
			for(int j=i;j*i<=max_p;j++)
			{
				is_p[i*j]=0;
			}
		}
	}
	
}
struct trie_t
{
	trie_t *cld[128]={0};
	vector<string> nums;
	void insert(char *p,char *s)
	{
		int c=*p;
		nums.push_back(s);
		if(c==0) return;
		if(cld[c]==0)
		{
			cld[c]=new trie_t;
		}
		cld[c]->insert(p+1,s);
	}
	trie_t * find(char *p)
	{
		int c=*p;
		if(c==0) return this;
		if(cld[c]==0) 
		{
			return 0;
		}
		return cld[c]->find(p+1);
	}
}root;
char arr[7][7];
vector<string> ans;
vector<string> nums;
int cnt=1;
//unordered_map<string,vector<int>> cache;
vector<int> *cache[161051]={0};
int cal_hash(char *a)
{
	int res=0;
	for(int i=0;i<5;i++)
	{
		res*=11;
		if(a[i]!=0)
			res+=a[i]-'0'+1;
		else
			res+=0;
	}
	return res;
}
vector<int> * get_idx(char *pat)
{
	int hh=cal_hash(pat);
	//static string s(5,0);
	//memcpy(&s[0],pat,5);
	//string s(pat,pat+5);
	if(cache[hh]!=0) return cache[hh];
	cache[hh]=new vector<int>;
	//if(cache.find(s)!=cache.end()) return &cache[s];

	vector<int> &vec=*cache[hh];
	for(int i=0;i<nums.size();i++)
	{
		char *s=(char*)nums[i].c_str();
		int not_ok=0;
		for(int j=0;j<5;j++)
		{
			if(pat[j]!=0&&s[j]!=pat[j]) {not_ok=1;break;}
		}
		if(not_ok) continue;
		vec.push_back(i);
	}
	return &vec;

}
int ok()
{
	const int test1=0;
	/*
	for(int i=1;i<=5;i++)
	{	
		if(root.find(arr[i]+1)==0) {if(test1)printf("<1>");return 0;}
	}
	for(int i=1;i<=5;i++)
	{
		char tmp[6]={0};
		for(int j=1;j<=5;j++)
		{
			tmp[j-1]=arr[j][i];
		}
		if(root.find(tmp)==0) {if(test1)printf("<2>");return 0;}
	}*/
	char tmp[6]={0};
	for(int i=1;i<=5;i++)
	{	
		tmp[i-1]=arr[i][i];
		//if(root.find(tmp)==0) {if(test1)printf("<3>");return 0;}
		if(get_idx(tmp)->size()==0) return 0;
	}
	memset(tmp,0,sizeof(tmp));
	for(int i=1;i<=5;i++)
	{	
		tmp[i-1]=arr[6-i][i];
		//if(root.find(tmp)==0) {if(test1)printf("<4>");return 0;}
		if(get_idx(tmp)->size()==0) return 0;
	}
	if(test1)printf("<ok>");
	return 1;
}
char * cache2[161051][5];
void get_can(char *a,int x,char can[])
{
	int hh=cal_hash(a);
	//s.push_back('0'+x);
	if(cache2[hh][x-1])
	{
		memcpy(can,cache2[hh][x-1],10);
		return ;
	}
	int can_cnt=0;
	memset(can,0,10);
	vector<int> &vec=*get_idx(a);
	for(int i=0;i<vec.size();i++)
	{
		string &s=nums[vec[i]];
		if(can[s[x-1]-'0']==0)
		{
			can[s[x-1]-'0']=1;
			can_cnt++;
			//if(can_cnt==10) return;
		}
	}
	cache2[hh][x-1]=new char[10];
	memcpy(cache2[hh][x-1],can,10);

	//vector<char> &vec2=cache2[s];
	//for(int i=0;i<10;i++)
	//	vec2.push_back(can[i]);


	return ;
}
int search_cnt=0;
void dfs(int depth)
{
	search_cnt++;
	if(ok()==0) return;
	if(depth==24)
	{
		string tmp;
		for(int i=1;i<=5;i++)
		{
			tmp+=arr[i]+1;
		}
		ans.push_back(tmp);
		//printf("%s\n",tmp.c_str());
		return ;
	}
	/*
	int best_res=0;
	for(int i=1;i<=5;i++)
		for(int j=1;j<=5;j++)
		{
			if(arr[i][j]!=0) continue;
			int cnt=0;
			char *a=arr[i]+1;
			char b[6];
			for(int k=1;k<=5;k++)
			{
				b[k-1]=arr[k][j];
			}
			for(int k=1;k<=5;k++)
			{
				if(a[k-1]) cnt++;
				if(b[k-1]) cnt++;
			}
			if(cnt>best_res)  best_res=cnt;
		}*/
	int best=99999;
	int best_i,best_j;
	char can1[10];
	char can2[10];
	for(int i=1;i<=5;i++)
		for(int j=1;j<=5;j++)
		{
			if(arr[i][j]!=0) continue;
			int cnt=0;
			char *a=arr[i]+1;
			char b[6];
			for(int k=1;k<=5;k++)
			{
				b[k-1]=arr[k][j];
			}
			for(int k=1;k<=5;k++)
			{
				if(a[k-1]) cnt++;
				if(b[k-1]) cnt++;
			}
			//if(cnt!=best_res) continue;
			cnt=0;
			get_can(a,j,can1);
			get_can(b,i,can2);
			for(int k=0;k<=9;k++)
			{
				if(can1[k]&&can2[k]) cnt++;
			}
			if(cnt==0) return;
			cnt*=1000;
			cnt+=rand()%500;
			if(i==j) cnt-=10000;
			if(i+j==6) cnt-=10000;
			if(cnt<best) 
			{
				best=cnt;
				best_i=i;
				best_j=j;
			}
		}
	int i=best_i,j=best_j;

	char *a=arr[i]+1;
	char b[5];
	for(int k=1;k<=5;k++)
	{
		b[k-1]=arr[k][j];
	}
	get_can(a,j,can1);
	get_can(b,i,can2);
	for(int k=0;k<=9;k++)
	{
		if(can1[k]&&can2[k])
		{
			arr[i][j]='0'+k;
			dfs(depth+1);
			arr[i][j]=0;
		}
	}

}
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif           
    //cache.reserve(100000);
    //cache2.reserve(100000);
    srand(12345);
    init_prime();
    int filter,start;
    scanf("%d %d",&filter,&start);
    for(int i=10000;i<=99999;i++)
    {
	    if(is_p[i])
	    {
		    char tmp[10];
		    sprintf(tmp,"%d",i);
		    int sum=0;
		    for(int j=0;j<5;j++)
		    {
			    sum+=tmp[j]-'0';
		    }
		    if(sum==filter)
		    {
			    if(test)printf("<%s>",tmp);
			    root.insert(tmp,tmp);
			    nums.push_back(tmp);
		    }
	    }
    }
    arr[1][1]='0'+start;
    dfs(0);
    if(ans.size()==0) printf("NONE\n");
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++)
    {
	    if(i) printf("\n");
	    //printf("%s",ans[i].c_str());
	    for(int j=0;j<25;j++)
	    {
		    if(j&&j%5==0) printf("\n");
		    printf("%c",ans[i][j]);
	    }
	    printf("\n");
    }
    if(test)printf("<<%d>>\n",search_cnt);
    //if(test) printf("cache_size=%d\n",cache.size());
    //if(test) printf("cache2_size=%d\n",cache2.size());

    return 0;
}

