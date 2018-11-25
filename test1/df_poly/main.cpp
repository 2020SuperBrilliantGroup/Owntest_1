#include<bits/stdc++.h>
using namespace std;
string f,g;
queue<int>tnum;
int turn(char hi){
	int po=1,d=0,f=tnum.size()-1;
	if(hi=='-'){
		po=-1;
	}
	while(!tnum.empty()){
		d+=tnum.front()*pow(10,f);
		tnum.pop();
		f--;
	}
	return po*d;
}
int main(){
	freopen("df_poly7.in","r",stdin);
	freopen("df_poly7.ans","w",stdout);
	int r,p,t,c=0,cx=1,con,w=0;
	bool b=true,cs=false;
	char h;
	for(int i=0;i<5;i++){
		cin>>h;
	}
	cin>>g;
	t=g.size();
	if(g[0]>='0'&&g[0]<='9'){
		f.push_back('+');
	}
	if(g[0]=='x'){
		f.push_back('+');
		f.push_back('1');
	}
	for(int i=0;i<t;i++){
		if(g[i]=='x'&&(g[i-1]=='+'||g[i-1]=='-'||g[i-1]=='=')){
			f.push_back('1');
		}
		f.push_back(g[i]);
		if(g[i]=='x'&&((g[i+1]=='+'||g[i+1]=='-')||i+1==t)){
			f.push_back('^');
			f.push_back('+');
			f.push_back('1');
		}
		if(g[i]=='^'&&g[i+1]>='0'&&g[i+1]<='9'){
			f.push_back('+');
		}
	}
	//cout<<f<<endl;
	r=f.size();
	for(int i=0;i<r;i++){
		if(f[i]=='x'){
			b=false;
			break;
		}
	}
	if(b){
		cout<<"f'(x)=0";
		return 0;
	}
	vector<int>xi,ci;
	xi.clear();
	ci.clear();
	int u,v,j,k,m,n,po;
	for(int i=0;i<f.size();i++){
		if(f[i]=='+'||f[i]=='-'||f[i]=='='){
			h=f[i];
			i++;
			while(f[i]>='0'&&f[i]<='9'){
				tnum.push((int)f[i]-48);
				i++;
			}
			i--;
			if(cx>0){
				xi.push_back(turn(h));
			}
			else{
				ci.push_back(turn(h));
			}
			cx*=-1;
		}
	}//字符串形式转代数形式
	t=xi.size();
	for(int i=0;i<t;i++){
		if(ci[i]>32768){
			ci[i]=0;
		}
	}
	for(int i=0;i<t;i++){
		if(ci[i]!=0){
			xi[i]*=ci[i];
			ci[i]--;
			if(ci[i]==0){
				cs=true;
				con=xi[i];
			}
		}
	}
	if(cs&&t>1&&ci[0]==0){
		w++;
	}
	//for(int i=0;i<t;i++){
	//	cout<<xi[i]<<' '<<ci[i]<<endl;
	//}
	cout<<"f'(x)=";
	if(xi[w]==-1){
		cout<<'-';
		if(ci[w]==0){
			cout<<1;
		}
	}
	else if(xi[w]!=1){
		cout<<xi[w];
	}
	if(ci[w]!=0){
		cout<<'x';
		if(ci[w]!=1){
			cout<<'^'<<ci[w];
		}
	}
	for(int i=w+1;i<t;i++){
		if(ci[i]!=0){
			if(xi[i]>0){
				cout<<'+';
			}
			if(ci[i]==0){
				cout<<xi[i];
			}
			else if(ci[i]==1){
				cout<<xi[i]<<'x';
			}
			else{
				if(xi[i]!=1&&xi[i]!=-1){
					cout<<xi[i];
				}
				if(xi[i]==-1){
					cout<<'-';
				}
				cout<<"x^"<<ci[i];
			}
		}
	}
	if(cs&&t>1){
		if(con>0){
			cout<<'+';
		}
		cout<<con;
	}
	return 0;
}
