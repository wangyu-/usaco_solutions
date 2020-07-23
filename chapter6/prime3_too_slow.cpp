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
		if(root.find(tmp)==0) {if(test1)printf("<3>");return 0;}
	}
	memset(tmp,0,sizeof(tmp));
	for(int i=1;i<=5;i++)
	{	
		tmp[i-1]=arr[6-i][i];
		if(root.find(tmp)==0) {if(test1)printf("<4>");return 0;}
	}
	if(test1)printf("<ok>");
	return 1;
}
vector<string> ans;
vector<string> nums;
int cnt=1;
int search_cnt=0;
void dfs(int depth)
{
	search_cnt++;
	if(ok()==0) return;
	if(cnt==25)
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
	int best=999;
	trie_t *best_p1,*best_p2;
	int best_i,best_j;
	for(int i=1;i<=5;i++)
		for(int j=1;j<=5;j++)
		{
			if(arr[i][j]!=0) continue;
			if(i!=1&&arr[i-1][j]==0) continue;
			if(j!=1&&arr[i][j-1]==0) continue;
			char *tmp1=arr[i]+1;
			int len1=j-1;
			char tmp2[6]={0};
			for(int k=1;k<=i-1;k++)
				tmp2[k-1]=arr[k][j];
			int len2=i-1;
			auto p1=root.find(tmp1);
			if(p1==0) continue;
			auto p2=root.find(tmp2);
			if(p2==0) continue;
			int cnt=0;
			int xxx=min(p1->nums.size(),p2->nums.size());
			for(int k=0;k<=9;k++)
			{
				if(p1->cld['0'+k]&&p2->cld['0'+k])
					cnt++;
			}
			if(cnt==0) return;
			if(xxx<best)
			{
				best=xxx;
				best_p1=p1;
				best_p2=p2;
				best_i=i;
				best_j=j;
			}
			

		}
	int i=best_i,j=best_j;
	auto p1=best_p1,p2=best_p2;
	for(int k=0;k<=9;k++)
	{
		if(p1->cld['0'+k]&&p2->cld['0'+k])
		{
			arr[i][j]='0'+k;
			cnt++;
			dfs(depth+1);
			arr[i][j]=0;
			cnt--;
		}
	}

}
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif           
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

    return 0;
}

