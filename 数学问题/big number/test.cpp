#include<stdio.h>  
int main()  
{  
	char s[50];  
	printf("请输入16进制数："); 
	scanf("%s",s);  
	int t;  
	long sum=0;  
	for(int i=0;s[i];i++)  
	{  
		if(s[i]<='9')  
			t=s[i]-'0';  
		else  
			t=s[i]-'A'+10;  
		sum=sum*16+t;  
	}  
	printf("转化为10进制数为：%ld\n",sum);  
	return 0;  
}
