#include<iostream>
using namespace std;
void swap(int *a, int *b){
	int tmp= *a;
	*a=*b;
	*b=tmp;
}
int main(){
	int n=100, m=200;
	swap(&n,&m);
	cout<<n<<" "<<m;
}
