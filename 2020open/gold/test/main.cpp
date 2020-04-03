#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <iostream>
using namespace std;
struct segtree
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
segtree wy(32000);
int main()
{
int n;
int i,j,k;
wy.ins(1,100);
wy.ins(1,100);
wy.ins(2,-300);
printf("%d",wy.value(1,1000));
return 0;
}

