//https://blog.csdn.net/wayne17/article/details/81431622#commentsedit
#include<iostream>
#include<math.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		double a,b,c;
		cin>>a>>b>>c;
		double ans1,ans2;
		
		double t=b*b-4.0*a*c;
		if(t<0){
			cout<<"NaN"<<endl;
		}
		else if(t==0){
			ans1=-b/(2.0*a);
			printf("%.2f %.2f\n",&ans1,&ans1);
		}
		else{
			ans1=(-b+pow(t,0.5))/(2*a);
			ans2=(-b-pow(t,0.5))/(2*a);
			printf("%.2f %.2f\n",ans1,ans2);
		}
		
	}

	return 0;
}

