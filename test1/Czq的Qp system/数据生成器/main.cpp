#include <bits/stdc++.h>
#include <random>
using namespace std;
int f[51][51];
bool fb[51][51]= {0};
int rand_X(int x) {
	static uniform_int_distribution<unsigned> u(1,x);
	static default_random_engine e;
//	e.seed(time(0));
	return u(e);
}
int fuc(int n,int m,int st,string filename) {
	memset(f,-1,sizeof(f));
	freopen(filename.c_str(),"w",stdout);
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			fb[i][j]=true;
		}
	}
	
	int x=1,y=rand_X(n);
	while(!fb[x][y]) {
		y=rand_X(n);
	}
	for(int i=0; i<m; i++) {
		f[x][y]=rand_X(st);
		fb[x][y]=false;
		x=y;
		y=rand_X(n);
		while(!fb[x][y]) {
			y=rand_X(n);
		}
	}
	cout<<n<<" "<<m<<endl;
	for(int i=1; i<=n; i++) {
        for(int j=1;j<=n;j++){
        	if(f[i][j]!=-1){
        		cout<<i<<" "<<j<<" "<<f[i][j]<<endl;
			}
		}
	}
	cout<<st;
	return 0;
}
int main(){
	int n,m,st;
	string filename;
	cin>>n>>m>>st;
	cin>>filename;
	fuc(n,m,st,filename);
}
