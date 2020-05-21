/*
ID: wangyu.1
LANG: C++11
TASK: transform
*/
#define TASKNAME "transform"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#ifdef TEST
int test=1;
#else
int test=0;
#endif

int n;
struct pat_t
{
	char data[15][15];
	int equal(pat_t b)
	{
		const pat_t &a=*this;
		int eq=1;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(a.data[i][j]!=b.data[i][j])
					eq=0;
			}
		}
		return eq;
	}
	pat_t rotate()
	{
		const pat_t &a=*this;
		pat_t b;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				b.data[i][j]=a.data[n-1-j][i];
			}
			b.data[i][n]=0;
		}
		return b;
	}
	pat_t reflect()
	{
		const pat_t &a=*this;
		pat_t b;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				b.data[i][j]=a.data[i][n-1-j];
			}
		}
		return b;	
	}
	pat_t reflect2()
	{
		const pat_t &a=*this;
		pat_t b;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				b.data[i][j]=a.data[n-1-i][j];
			}
		}
		return b;	
	}
	pat_t both()
	{
		return (*this).reflect().reflect2();
	}
	void prt()
	{
		if(test)
		{
			printf("========");
			for(int i=0;i<n;i++)printf("%s\n",data[i]);
		}
	}
};

int main() 
{
#ifndef TEST
	freopen (TASKNAME".in", "r",stdin);
	freopen (TASKNAME".out", "w",stdout);
#endif
	pat_t pat1,pat2;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%s",pat1.data[i]);
	};
	for(int i=0;i<n;i++)
	{
		scanf("%s",pat2.data[i]);
	};
	if(pat2.equal(pat1.rotate())) {printf("1\n");return 0;}
	if(pat2.equal(pat1.rotate().rotate())) {printf("2\n");return 0;}
	if(pat2.equal(pat1.rotate().rotate().rotate())) {printf("3\n");return 0;}
	if(pat2.equal(pat1.reflect())) {printf("4\n");return 0;}
	pat_t tmp=pat1;
	for(int i=0;i<4;i++)
	{
		tmp=tmp.rotate();
//		if(pat2.equal(tmp.reflect())  ||pat2.equal(tmp.reflect2())||pat2.equal(tmp.both()))
		if(pat2.equal(tmp.reflect()))
		{
			printf("5\n");return 0;
		} 
	}
	//if(0) {printf("5\n");return 0;}
	if(pat2.equal(pat1)) {printf("6\n");return 0;}
	printf("7\n");
	
	return 0;
}

