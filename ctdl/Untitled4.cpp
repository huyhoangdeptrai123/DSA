#include<iostream>
using namespace std;
int fibonaci( int x){
	if (x==0) return 0;
	if(x==1) return 1;
	else return fibonaci(x-1)+fibonaci(x-2);
}
int main(){
	int n;
	cin>>n;
	cout<<fibonaci(n);
}
