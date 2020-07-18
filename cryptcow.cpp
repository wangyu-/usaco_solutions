/*
  ID: wangyu.1
  LANG: C++11
  TASK: cryptcow
*/
#define TASKNAME "cryptcow"

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
int test=0;
#else
int test=0;
#endif

struct trie_t
{
	trie_t *cld[128]={0};
	void insert(char *p)
	{
		int c=*p;
		if(c==0) return;
		if(cld[c]==0)
		{
			cld[c]=new trie_t;
		}
		cld[c]->insert(p+1);
	}
	int find(char *p)
	{
		int c=*p;
		if(c==0) return 1;
		if(cld[c]==0) 
		{
			//printf("[[[%s]]]",p);
			return 0;
		}
		return cld[c]->find(p+1);
	}
}root,root2,root3,root4,root5;
unordered_set<string> hh;
char target[]="Begin the Escape execution at the Break of Dawn";
int t_stat[128]={0};
int in_stat[128]={0};
int not_ok(char *s)
{
	int n=strlen(s);
	char tmp[n+10];
	strcpy(tmp,s);
	int i;
	for(i=0;i<n;i++)
	{
		if(tmp[i]=='C') break;
	}
	tmp[i]=0;
	if(root3.find(tmp)==0) return 1;
	if(i!=n)
		tmp[i]='C';
	reverse(tmp,tmp+n);
	for(i=0;i<n;i++)
	{
		if(tmp[i]=='W') break;
	}
	tmp[i]=0;
	if(root4.find(tmp)==0) return 1;
	if(i!=n)
		tmp[i]='W';
	reverse(tmp,tmp+n);

	char *p=strtok(tmp,"COW");
	//if(p==tmp&&root3.find(p)==0)
	//	return 0;
	char *last=p;
	while(p!=0)
	{
		last=p;
		if(test)printf("<%s>",p);
		if(root.find(p)==0)
		{
			if(test)printf("[not ok:%s]",p);
			return 1;
		}
		p=strtok(0,"COW");
	}
	//reverse(last,last+strlen(last));
	//if(root4.find(last)==0) return 0;
	return 0;
}
int dfs(char *s,int depth)
{
	if(not_ok(s)) return 0;
	//if(test||1) printf("<<%s>>\n",s);
	//if(root5.find(s)) return 0;
	if(hh.find(s)!=hh.end()) return 0;
	if(depth==0)
	{
		if(not_ok(s)) return 0;
		return 1;
	}
	int n=strlen(s);
	int c[depth+5];
	int c_cnt=0;
	int o[depth+5];
	int o_cnt=0;
	int w[depth+5];
	int w_cnt=0;
	for(int i=0;s[i];i++)
	{
		if(s[i]=='C') c[c_cnt++]=i;
		if(s[i]=='O') o[o_cnt++]=i;
		if(s[i]=='W') w[w_cnt++]=i;
	}
	for(int i=0;i<c_cnt;i++)
	{
		int cc=c[i];
		for(int j=0;j<o_cnt;j++)
		{
			int oo=o[j];
			if(oo<cc) continue;
			for(int k=0;k<w_cnt;k++)
			{
				int ww=w[k];
				if(ww<oo) continue;
				char tmp[n+10]={0};
				int cnt=0;
				for(int x=0;x<=cc-1;x++)
				{
					tmp[cnt++]=s[x];
				}
				for(int x=oo+1;x<=ww-1;x++)
				{
					tmp[cnt++]=s[x];
				}
				for(int x=cc+1;x<=oo-1;x++)
				{
					tmp[cnt++]=s[x];
				}
				for(int x=ww+1;x<n;x++)
				{
					tmp[cnt++]=s[x];
				}
				if(dfs(tmp,depth-1)) return 1;
			}
		}
	}
	hh.insert(s);
	//root5.insert(s);
	return 0;
}
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif           
    char input[100];
    fgets(input,100,stdin);
    input[strlen(input)-1]=0;
    for(int i=0;input[i];i++)
    {
	    in_stat[input[i]]++;
    }
    for(int i=0;target[i];i++)
    {
	    t_stat[target[i]]++;
	    root.insert(target+i);
    }
    root3.insert(target);
    reverse(target,target+strlen(target));
    root4.insert(target);
    reverse(target,target+strlen(target));
    int depth=in_stat['C'];
    if(in_stat['O']!=depth||in_stat['W']!=depth)
    {
	    if(test)printf("<aaa>");
	    printf("0 0\n");
	    return 0;
    }
    in_stat['C']=in_stat['O']=in_stat['W']=0;
    int ok=1;
    for(int i=0;i<128;i++)
    {
	    if(in_stat[i]!=t_stat[i]) ok=0;
    }
    if(!ok)
    {
	    if(test)printf("<bbb>");
	    printf("0 0\n");
	    return 0;
    }
    /*
    if(not_ok(input))
    {
	    if(test)printf("<ccc>");
	    printf("0 0\n");
	    return 0;
    }*/
    if(dfs(input,depth)==0)
    {
	    if(test)printf("<ddd>");
	    printf("0 0\n");
	    return 0;
    }
    printf("%d %d\n",1,depth);


    return 0;
}

