/*
  ID: wangyu.1
  LANG: C++11
  TASK: lgame
*/
#define TASKNAME "lgame"

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
using namespace std;

#ifdef TEST
int test=0;
#else
int test=0;
#endif

char stable[26]={0};
char slist[]="q7w6e1r2t2y5u4i1o3p5a2s1d4f6g5h5j7k6l3z7x7c4v6b5n2m5";

string input;
char in_stat[26]={0};
string in_nd;

vector<string> dict;

int cs(string &s)
{
    int sum=0;
    for(int i=0;i<(int)s.length();i++)
    {
	sum+=stable[s[i]-'a'];
    }
    return sum;
}

int csl(string &s,string &left)
{
    static char stat[26]={0};
    int ok=1;
    int sum=0;
    for(int i=0;i<(int)s.length();i++)
    {
	stat[s[i]-'a']++;
	sum+=stable[s[i]-'a'];
	if(stat[s[i]-'a']>in_stat[s[i]-'a'])
	    ok=0;
    }
    if(ok==0) sum=-1;
    
    int left_len=input.length()-s.length();
    if(sum!=-1&&left_len>=3)
    {
	assert(left.length()==0);
	assert(left_len<=4);
	for(int i=0;i<(int)in_nd.size();i++)
	{
	    char c=in_nd[i];
	    for(int j=0;j<in_stat[c-'a']-stat[c-'a'];j++)
	    {
		left.push_back(c);
	    }
	}

    }

    for(int i=0;i<(int)s.length();i++)
    {
	stat[s[i]-'a']--;
    }
    return sum;
    
}
void get_nd(string &s,string &nd)
{
    assert(nd.size()==0);
    static char stat[26]={0};
    for(int i=0;i<4;i++)
    {
	char c=s[i];
	if(stat[c-'a']==0)
	    nd.push_back(c);
	stat[c-'a']++;
    }
    for(int i=0;i<4;i++)
    {
	stat[s[i]-'a']--;
    }
}

unordered_map<string,int> s34;
unordered_map<string,vector<int> > l34;

int run(int goal=-999)
{
    int best=0;
    string left;
    string left2;
    string nd;
    vector<string> res_right;
    for(int i=0;i<(int)dict.size();i++)
    {
	string &ss=dict[i];
	left.clear();
	int score1=csl(ss,left);
	int score2=0;
	if(score1==-1) continue;
	if(score1==goal)
	{
	    printf("%s\n",ss.c_str());
	    continue;
	}
	if(left.length()>=3)
	{
	    if(test) printf("<%s %s>",ss.c_str(),left.c_str());
	    if(s34.find(left)!=s34.end())
	    {
		score2=s34[left];
		if(goal==score1+score2)
		    for(auto idx:l34[left])
		    {
			if(idx>i)
			{
			    printf("%s %s\n",ss.c_str(),dict[idx].c_str());
			}
		    }
	    }
	    else if(left.length()==4)
	    {
		nd.clear();
		get_nd(left,nd);
		if(test) printf("<nd=%s>",nd.c_str());
		res_right.clear();
		for(int j=0;j<(int)nd.size();j++)
		{
		    left2=left;
		    for(int k=0;k<4;k++)
		    {
			if(left2[k]==nd[j])
			    left2.erase(k,1);
		    }
		    if(test) printf("[%s %s]",ss.c_str(),left2.c_str());
		    if(s34.find(left2)==s34.end())
			continue;
		    int score_tmp=s34[left2];
		    if(score_tmp> score2)
			score2=score_tmp;
		    if(goal==score1+score_tmp)
		    {
			for(auto idx:l34[left2])
			{
			    if(idx>i)
			    {
				res_right.push_back(dict[idx].c_str());
			    }
			}
		    }
		}
		sort(res_right.begin(),res_right.end());
		for(auto sss:res_right)
		{
		    printf("%s %s\n",ss.c_str(),sss.c_str());
		}
	    }
	}
	if(test) printf("\n");
	int score=score1+score2;
	if(test)printf("%d %d %d\n",score1,score2,score);
	if(score>best)
	    best=score;	
    }
    return best;
}
int main()
{
#ifndef TEST
    freopen (TASKNAME".in", "r",stdin);
    freopen (TASKNAME".out", "w",stdout);
#endif
    int len=strlen(slist);
    assert(len%2==0);
    for(int i=0;i<len;i+=2)
    {
	stable[slist[i]-'a']=slist[i+1]-'0';
    }

    auto fp=fopen("lgame.dict","r");
    char s[10];
    while(1)
    {
	fscanf(fp,"%s",s);
	if(s[0]=='.') break;
	dict.emplace_back(s);
	string &ss=dict[dict.size()-1];
	int len=ss.length();
	if(len==3||len==4)
	{
	    sort(s,s+len);
	    s34[s]=cs(ss);
	    l34[s].push_back(dict.size()-1);
	}
    }
    scanf("%s",s);
    input=s;
    for(int i=0;s[i];i++)
    {
	if(in_stat[s[i]-'a']==0) 
	    in_nd.push_back(s[i]);
	in_stat[s[i]-'a']++;
    }
    sort(in_nd.begin(),in_nd.end());
    int best=run();
    if(test) printf("========\n");
    printf("%d\n",best);
    run(best);



    return 0;
}

