#include<iostream>
using namespace std;

int main(){
	int a,b,c,x,n;
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
