#include<iostream>
#include<string.h>
using namespace std;
struct Sinhvien_dslk_don{
	string stt;
	string mssv;
	string ho;
	string ten;
	string lop;
	string diem;
	void pr() {
		cout << this->stt << " " << this->mssv << " " << this->ho << " " << this->ten << " " << this->lop << " " << this->diem;
	}
	void setinfo(string stt,string mssv, string ho, string ten,string lop, string diem) {
		this->stt= stt;
		this->mssv=mssv;
		this->ho=ho;
		this->ten=ten;
		this->lop=lop;
		this->diem=diem;
	}
};
 struct node_dslk_don{
 		Sinhvien_dslk_don data;
 		node_dslk_don *next;
 };
node_dslk_don* makeNode(Sinhvien_dslk_don x){
	node_dslk_don* newNode = new node_dslk_don();
	newNode->data = x;
	newNode->next =NULL;
	return newNode;
}
int Size(node_dslk_don* a){
	int cnt= 0;
	while(a != NULL ){
		++cnt;
		a=a->next;//
	}
	return cnt;
}
void themcuoi_dslk_don(node_dslk_don* &a,Sinhvien_dslk_don x ){
	node_dslk_don* tmp = makeNode(x);
	if(a == NULL){
		a= tmp;
	}
	else{
		node_dslk_don* p =a;
		while(p->next != NULL){
			p= p->next;
		}
		p->next= tmp;
	}
}
void duyet_dslk_don(node_dslk_don* head){
	while(head != NULL) {
		head->data.pr();
		cout << endl;
		head= head->next;
	}
	
}

