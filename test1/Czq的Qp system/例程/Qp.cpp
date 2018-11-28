#include<bits/stdc++.h>
using namespace std;
int n,m,st;
int f[50][100]={0};
bool v[50]={0};
bool flaga=false;
int minn=999999999;
void dfs(int pos,int lq){
	if(pos==n){
		minn=min(minn,lq);
		flaga=true;
		return;
	}
	v[pos]=false;
	for(int i=1;i<=n;i++){
		if(f[pos][i]!=0&&v[i]){
			dfs(i,lq+f[pos][i]);
		}
	}
	v[pos]=true;
}
int main(){
	freopen("Qp.in","r",stdin);
	freopen("Qp.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int tb,te,tq;
		cin>>tb>>te>>tq;
		f[tb][te]=tq;
	}
	cin>>st;
	for(int i=1;i<=n;i++){
		v[i]=true;
	}
	dfs(1,0);
	if(flaga){
		cout<<st-minn;
	}else{
		cout<<-1;
	}
	return 0;
}
