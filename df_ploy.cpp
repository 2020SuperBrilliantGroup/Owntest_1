#include<bits/stdc++.h>
using namespace std;
int main(int argc, char** argv){
	freopen("df_ploy.in","r",stdin);
	freopen("df_ploy.out","w",stdout);
	int r,p,t,c=0;
	string f,g;
	f.push_back('f');
	f.push_back('(');
	f.push_back('x');
	f.push_back(')');
	f.push_back('=');
	cin>>g;
	t=g.size();
	p=g.find('=')+1;
	for(int i=p;i<t;i++){
		if(g[i]=='x'&&(g[i-1]=='+'||g[i-1]=='-'||g[i-1]=='=')){
			f.push_back('1');
		}
		f.push_back(g[i]);
	}
	r=f.size();
	p=f.find('=')+1;
	for(int i=r-1;i>=0;i--){
		if(f[i]=='+'||f[i]=='-'){
			break;
		}
		c++;
	}
	for(int i=p;i<r;i++){
		if(f[i]=='^'){
			f[i-2]=(f[i-2]-48)*(f[i+1]-48);
			f[i+1]=f[i+1]-49;
		}
		if(f[i]=='x'&&(f[i+1]=='+'||f[i+1]=='-')){
			f[i]=0;
			f[i-1]-=48;
		}
	}
	cout<<"f'(x)=";
	for(int i=p;i<r-c-1;i++){
		if(f[i]=='^'){
			if(f[i+1]==1){
				i++;
			}
			else{
				cout<<(char)f[i];
			}
		}
		else if(f[i]=='+'||f[i]=='-'||f[i]=='x'){
			cout<<(char)f[i];
		}
		else if(f[i]!=0){
			cout<<(int)f[i];
		}
	}
	if(g[t]>='0'&&g[t]<='9'&&g[t-1]=='='){
		cout<<0;
	}
	return 0;
}
