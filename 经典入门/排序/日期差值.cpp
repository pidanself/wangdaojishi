#include<iostream>
#include<stdio.h>
#include<math.h>
//宏定义判断闰年函数 
#define isYeap(x) x%100!=0&&x%4==0||x%400==0?1:0
using namespace std;
int dayOfMonth[13][2]={
	0,0,
	31,31,
	28,29,
	31,31,
	30,30,
	31,31,
	30,30,
	31,31,
	31,31,
	30,30,
	31,31,
	30,30,
	31,31
};

struct Date{
	int Day;
	int Month;
	int Year;
	void nextDay(){
		Day++;
		if(Day>dayOfMonth[Month][isYeap(Year)]){
			Day=1;
			Month++;
			if(Month>12){
				Month=1;
				Year++;
			}
		}
	}
};
int buf[10000][13][32];



int main(){
	Date tmp;
	tmp.Year=1900;
	tmp.Month=1;
	tmp.Day=1;
	int total=0;
	while(tmp.Year<10000){
		buf[tmp.Year][tmp.Month][tmp.Day]=total;
		tmp.nextDay();
		total++;
	}
	int d1,m1,y1;
	int d2,m2,y2;
	while(scanf("%4d%2d%2d",&y1,&m1,&d1)!=EOF){
		scanf("%4d%2d%2d",&y2,&m2,&d2);
		printf("%d\n",abs(buf[y1][m1][d1]-buf[y2][m2][d2])+1);
	}

	return 0;
}

