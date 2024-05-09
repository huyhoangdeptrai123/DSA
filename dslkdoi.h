#include<iostream>
#include<string.h>
using namespace std;
struct Sinhvien_dslk_kep{
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
struct node_dslk_kep{
	Sinhvien_dslk_kep data;
	node_dslk_kep *next;
	node_dslk_kep *prev;
};
node_dslk_kep *makeNode(Sinhvien_dslk_kep x){  // tao ra con tro kieu node
	node_dslk_kep *newNode = new node_dslk_kep(); //cap phat
	newNode->data = x;
	newNode->next= NULL;
	newNode->prev= NULL;
	return newNode;
}

void duyet_dslk_kep(node_dslk_kep *head){
	int dem = 0;
	while(head != NULL){
		head->data.pr();
		cout << endl;
		dem ++;
		head = head->next;
	}
}
void themcuoi_dslk_kep(node_dslk_kep *&head, Sinhvien_dslk_kep x){
	node_dslk_kep *newNode = makeNode(x);
	if (head == NULL){
		head = newNode;
		return;
	}
	
	node_dslk_kep *tmp= head;
	while (tmp -> next != NULL){
		tmp= tmp->next;
	}
	tmp->next= newNode;
	newNode->prev= tmp;
}
