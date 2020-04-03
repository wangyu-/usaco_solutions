/*
ID: wangyu.1
LANG: C++11
TASK: socdist1
*/
#define TASKNAME "haircut"

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

struct segtree  //template write by me years ago
{
        int *node;
        int end;
        segtree(int e)
        {
                end=e;
                node=(int*)malloc(e*4*sizeof(int)+100);
                memset(node,0,e*4*sizeof(int)+100);
        }
        void ins(int k,int c,int l=0,int r=-1,int pos=1)
        {
                if(r==-1) r=end;
                node[pos]+=c;
                if(l==r) return ;
                int mid=(l+r)/2;
                if(k<=mid)
                        ins(k,c,l,mid,pos*2);
                else
                        ins(k,c,mid+1,r,pos*2+1);
        }
        int value(int l2,int r2,int l=0,int r=-1,int pos=1)
        {
                if(r==-1) r=end;
                if(l2==l&&r2==r) return node[pos];
                int mid=(l+r)/2;
                if(r2<=mid) return value(l2,r2,l,mid,pos*2);
                if(l2>=mid+1) return value(l2,r2,mid+1,r,pos*2+1);
                else return value(l2,mid,l,mid,pos*2)+value(mid+1,r2,mid+1,r,pos*2+1);
        }
};
//segtree wy(8);
segtree wy(100010);

long long sum[100000+5];
int main() 
{
#ifndef TEST
	freopen (TASKNAME".in", "r",stdin);
	freopen (TASKNAME".out", "w",stdout);
#endif
	
	//wy.ins(0,1);
	//printf("%d\n",wy.value(0,0));
	memset(sum,0,sizeof(sum));
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int len;
		scanf("%d",&len);
		wy.ins(len,1);
		int larger=wy.value(len+1,n+5);
		if(test) printf("<num=%d:%d>",len,larger);
		sum[len]+=larger;
	}
	if(test)printf("\n");
	if(test)
	{
		for(int i=0;i<=n;i++)
		{
			printf("<sum%d= %d>",i,sum[i]);
		}
	}
	long long real_sum=0;
	printf("0\n");
	for(int i=0;i<n-1;i++)
	{
		real_sum+=sum[i];
		printf("%lld\n",real_sum);
	}
	return 0;
}

