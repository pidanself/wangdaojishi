#include<iostream>
#include<map>
using namespace std;

struct p{
	string par="";
	int w=0;
	
	int gangnums=1;
	string head="";
	int gangw=0;
};
map<string,p> m;
string findroot(string x){
	if(m[x].par==""){
		return x;
	}
	string tmp=findroot(m[x].par);
	m[x].par=tmp;
	return tmp;
}

int main(){

	
	int mm,n;
	cin>>mm>>n;
	for(int i=0;i<mm;i++){
		string a,b;
		int w;
		cin>>a>>b;
		cin>>w;
		//判断在不在里面 
		if(m.count(a)==0){
			p tmp;
			m.insert(make_pair(a,tmp));
		} 
		if(m.count(b)==0){
			p tmp;
			m.insert(make_pair(b,tmp));
		}
		//为每个人增加权重 
		m[a].w+=w;
		m[b].w+=w;
		//找根节点 
		string p1=findroot(a);
		string p2=findroot(b);
		
		
		string nh;
		//若在同一个帮派
		if(p1==p2){
			m[p1].gangw+=w;
			nh=m[p1].head;
		}
		//若不在同一个
		else{
			m[p1].par=p2;
			m[p2].gangnums+=m[p1].gangnums;
			m[p2].gangw+=m[p1].gangw+w;
			string t1=m[p1].head,t2=m[p2].head;
			if(t1==""){
				nh=t2;
			}
			else if(t2==""){
				nh=t1;
			}
			else{
				if(m[t1].w>m[t2].w){
					nh=t1;
				}
				else{
					nh=t2;
				}
			}			
		}
		
		//看头目是谁,换给p2里面 
		if(nh==""){
			if(m[a].w>m[b].w){
				m[p2].head=a;
			} 
			else{
				m[p2].head=b;
			}
		}
		else{
			if(m[a].w>m[b].w){
				if(m[a].w>m[nh].w){
					m[p2].head=a;
				}
				else{
					m[p2].head=nh;
				}
			} 
			else{
				if(m[b].w>m[nh].w){
					m[p2].head=b;
				}
				else{
					m[p2].head=nh;
				}
			}
		}
	}
	
	map<string,p>::iterator it=m.begin();

	while(it!=m.end()){
		if((it->second).par==""){
			if((it->second).gangnums>2&&(it->second).gangw>n){
				cout<<(it->second).head<<" "<<(it->second).gangnums<<endl;
			}
			
		}
		it++;
	}
	return 0;
}

