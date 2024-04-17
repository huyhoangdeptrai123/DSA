#include <bits/stdc++.h>
#include<iostream>
using namespace std;
void double1( int x){
	x*= 10;
}  
void double2(int &x){
	x*= 10;
}  
void double3( int  *x){
	*x= (*x ) * 10;
}
int main(){
	int n=200;
	double3(&n);
	cout<<n;
	

}
