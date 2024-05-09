#include<iostream>
#include<string.h>
using namespace std;
struct Sinhvien_dslk_vong{
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
struct node_dslk_vong
{
	Sinhvien_dslk_vong data;
	node_dslk_vong*next;
	node_dslk_vong*prev;
};
//	node_dslkv* head;
node_dslk_vong *makeNode(Sinhvien_dslk_vong x){
	node_dslk_vong *newNode = new node_dslk_vong(); //cap phat
	newNode->data = x;
	newNode->next= NULL;
	newNode->prev= NULL;
	return newNode;
}
void themcuoi_dslkv(node_dslk_vong *&head,Sinhvien_dslk_vong x){
	node_dslk_vong *newNode = makeNode(x);
	if (head == NULL) {
        head = newNode;
        newNode->next = head; 
	}
	else {
		node_dslk_vong*current = head;
		while(current->next != head){
			current= current ->next;
		}
		current->next= newNode;
		newNode->next= head;
	}
}
void duyet_dslk_vong(node_dslk_vong*head)
{
	
	node_dslk_vong *tmp= head;
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
