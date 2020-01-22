/*
ID: wangyu.1
LANG: C++11
TASK: friday
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
int days_of_month(int y,int m)
{
	m+=1;
	switch(m)
	{
		case 4:
		case 6:
		case 9:
		case 11:
			return 30;
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			return 31;
		case 2:
			if(y%400==0) return 29;
			if(y%100==0) return 28;
			if(y%4==0) return 29;
			return 28;
		default:
		assert(0);
	}
}
int cnt_arr[7]={0};
int main() 
{


#ifndef TEST
	freopen ("friday.in", "r",stdin);
	freopen ("friday.out", "w",stdout);
#endif

	int n;
	scanf("%d",&n);
	int year=1900;
	int day_of_week=0;
	for(int i=0;i<n*12;i++)	
	{
		int d_of_m=days_of_month(year+i/12,i%12);
		//printf("<%d,%d>",i,d_of_m);
		for(int j=0;j<d_of_m;j++)
		{
			if(j==12)
			{
				cnt_arr[day_of_week]++;		
			}
			day_of_week++;
			day_of_week%=7;	
		}
		
	}
	for(int i=0;i<7;i++)
	{
		if(i!=0) printf(" ");
		printf("%d",cnt_arr[(i+7-2)%7]);
		//printf("%d",cnt_arr[i]);
	}
	printf("\n");
	return 0;
}

