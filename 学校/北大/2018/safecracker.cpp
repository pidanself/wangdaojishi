#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
bool cmp(char s1,char s2){
	return s1>s2;
}
int main(){
	int t;
	string s;
	cin>>t>>s;
	while(t!=0){
		sort(s.begin(),s.end(),cmp);
		int mark[s.size()]={0};
		for(int i1=0;i1<s.size();i1++){
			mark[i1]=1;
			for(int i2=0;i2<s.size();i2++){
				if(mark[i2]==1) continue;
				else{
					mark[i2]=1;
				}
				for(int i3=0;i3<s.size();i3++){
					if(mark[i3]==1) continue;
					else{
						mark[i3]=1;
					}
					for(int i4=0;i4<s.size();i4++){
						if(mark[i4]==1) continue;
						else{
							mark[i4]=1;
						}
						for(int i5=0;i5<s.size();i5++){
							if(mark[i5]==1) continue;
							else{
								mark[i5]=1;
							}
							int v,w,x,y,z;
							v=s[i1]-'A'+1;
							w=s[i2]-'A'+1;
							x=s[i3]-'A'+1;
							y=s[i4]-'A'+1;
							z=s[i5]-'A'+1;
							int tt=v-pow(w,2)+pow(x,3)-pow(y,4)+pow(z,5);
							if(tt==t){
								printf("%c%c%c%c%c\n",s[i1],s[i2],s[i3],s[i4],s[i5]);
								goto ans;
							}
							mark[i5]=0;
						}
						mark[i4]=0;
					}
					mark[i3]=0;
				}
				mark[i2]=0;
			}
			mark[i1]=0;
		}
		
		noans:
			printf("no solution\n");
		ans:
		cin>>t>>s;
	}

	return 0;
}

