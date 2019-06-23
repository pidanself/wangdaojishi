#include<iostream>
#include<cstring>
using namespace std;
bool isyeap(int y){
	return y%400==0||y%4==0&&y%100!=0;
}

struct date{
	int year,month,day;
	void operator ++ (int){
		day++;
		switch(month){
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
				if(day==32){
					day=1;
					month++;
				}
				break;
			case 12:
				if(day==32){
					day=1;
					month=1;
					year++;
				}
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				if(day==31){
					day=1;
					month++;
				}
				break;
			case 2:
				if(isyeap(year)){
					if(day==30){
					day=1;
					month++;
					}
				}
				else{
					if(day==29){
					day=1;
					month++;
					}
				}
				break;
		}
		
	}
};
int cmp(date a,date b){
	if(a.year==b.year&&a.month==b.month&&a.day==b.day) return 0; 
	if(a.year!=b.year){
		if(a.year>b.year){
			return 1;
		}
		else{
			return -1;
		}
	}
	else if(a.month!=b.month){
		if(a.month>b.month){
			return 1;
		}
		else{
			return -1;
		}
	}
	else{
		if(a.day>b.day){
			return 1;
		}
		else{
			return -1;
		}
	}
}

char monthname[13][20]={
	"",
	"January",
	"February",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October",
	"November",
	"December"
};

char weekname[8][20]={
	"",
	"Monday",
	"Tuesday",
	"Wednesday",
	"Thursday",
	"Friday",
	"Saturday",
	"Sunday"
};
char month[20];


int main(){
	int c;
	
	date n,p;
	p.day=8;p.month=10;p.year=2001;
	scanf("%d%s%d",&n.day,month,&n.year);
	
	for(int i=1;i<13;i++){
		if(strcmp(monthname[i],month)==0){
			n.month=i;
			break;
		}
	}
	int t=cmp(n,p);
	if(t==0){
		cout<<"Monday";
		return 0;
	}
	else if(t>0){
		c=0;
		while(cmp(n,p)!=0){
			c++;
			p++;
		}
	}
	else{
		c=0;
		while(cmp(n,p)!=0){
			c++;
			n++;
		}
	}
	
	c=c%7;
	cout<<weekname[c+1];

	return 0;
}

