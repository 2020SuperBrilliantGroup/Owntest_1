#include <bits/stdc++.h>
using namespace std;
int f[51][51];
bool fb[51][51]= {0};
int rand_X(int x) {
	srand(rand());
	return rand()%x+1;
}
int main() {
	memset(f,-1,sizeof(f));
	int n,m,st;
	string filename;
	cin>>n>>m>>st;
	cin>>filename;
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
		f[x][y]=rand_X(500);
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
	cout<<st<<" "<<rand_X(st)-1;
	return 0;
}
