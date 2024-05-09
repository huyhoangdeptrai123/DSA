#include<iostream>
#include<string.h>
using namespace std;
struct Sinhvien_dslkv{
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
struct node_dslkv
{
	Sinhvien_dslkv data;
	node_dslkv *next;
	node_dslkv *prev;
};
//	node_dslkv* head;
node_dslkv *makeNode(Sinhvien_dslkv x){
	node_dslkv *newNode = new node_dslkv(); //cap phat
	newNode->data = x;
	newNode->next= NULL;
	newNode->prev= NULL;
	return newNode;
}
void themcuoi_dslkv(node_dslkv *&head,Sinhvien_dslkv x){
	node_dslkv *newNode = makeNode(x);
	if (head == NULL) {
        head = newNode;
        newNode->next = head; 
	}
	else {
		node_dslkv *current = head;
		while(current->next != head){
			current= current ->next;
		}
		current->next= newNode;
		newNode->next= head;
	}
}
void duyet(node_dslkv *head)
{
	
	node_dslkv *tmp= head;
	if (head!= NULL){
		do
		{
			tmp->data.pr();
			cout<<endl;
			tmp= tmp->next;
			
		}
		while(tmp != head);
	}
}
