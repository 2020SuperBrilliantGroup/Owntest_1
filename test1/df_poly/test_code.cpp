#include<bits/stdc++.h>
using namespace std;
struct f{
	int x;
	int c;
}a[1001];
bool cmp(f u,f v){
	return u.c>v.c;
}
int main(int argc, char** argv){
	freopen("df_poly1.in","w",stdout);
	srand((unsigned)time(NULL));
	int n=rand()%1000;
	cout<<"f(x)=";
	for(int i=0;i<n;i++){
		a[i].x=rand()*rand()%32768-16384;
		a[i].c=rand()*rand()%32768-16384;
	}
	sort(a,a+n,cmp);
	cout<<a[0].x<<"x^"<<a[0].c;
	for(int i=1;i<n;i++){
		if(a[i].x>0){
			cout<<'+'<<a[i].x<<"x^"<<a[i].c;
		}
		else{
			cout<<a[i].x<<"x^"<<a[i].c;
		}
	}
	int b=rand()%2;
	if(b==1){
		int r=rand()%32768;
		if(r>0){
			cout<<'+';
		}
		cout<<r;
	}
	return 0;
}
