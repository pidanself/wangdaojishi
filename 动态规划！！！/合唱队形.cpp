#include<iostream>
using namespace std;
//ͬѧ����
int n;
//ͬѧ�����
int h[101]; 
//�Ե�i��ͬѧΪ��ֹ�������������
int dps[101];
//�Ե�i��ͬѧΪ��ֹ���������������
int dpn[101];


int main(){
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			cin>>h[i];
		}
		//��˳
		for(int i=0;i<n;i++){
			dps[i]=1;
			for(int j=0;j<i;j++){
				if(h[j]<h[i]){
					dps[i]=max(dps[i],dps[j]+1);
				}
			}
		} 
		//����
		for(int i=n-1;i>=0;i--){
			dpn[i]=1;
			for(int j=n-1;j>i;j--){
				if(h[j]<h[i]){
					dpn[i]=max(dpn[i],dpn[j]+1);
				}
			}
		} 
		int ans=0;
		for(int i=0;i<n;i++){
			ans=max(ans,dps[i]+dpn[i]);
		}
		cout<<"���ٳ��У�"<<n-ans+1<<"��ѧ��"<<endl; 
	}

	return 0;
}

