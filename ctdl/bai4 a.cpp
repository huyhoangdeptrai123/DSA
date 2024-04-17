#include<iostream>
using namespace std;

int ham(int n,int x){
	if (n==0 ) return 1;
	else if(n==1) return x;
	else return ham(n-1,x) - ham(n-2,x);
	
}
int main(){
	int a,b,c,x,n;;
	cin>>a>>b;
	cout<<ham(a,b);
	cin>>n;
	cin>>x;
	a=1;
	b=x;
	for(int i=2;i<=n;i++){
		c= b-a;
		a=b;
		b=c;
	}
	cout<<c;
}
