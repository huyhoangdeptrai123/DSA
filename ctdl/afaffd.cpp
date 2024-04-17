#include<iostream>
using namespace std;

struct Sinhvien{
	string ten,diachi;
	int tuoi;
};

int main(){
	int *a = new int [100000];
	for (int i=0;i<5;i++){
		cin>>a[i];
	}
	delete []a;
}
