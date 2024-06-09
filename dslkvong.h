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

// Sap xep danh sach
void swap(Sinhvien_dslk_vong &a, Sinhvien_dslk_vong &b) {
    Sinhvien_dslk_vong temp = a;
    a = b;
    b = temp;
}

// BubbleSort; Goi ham: bubbleSort(dslk_vong); -> in ra: duyet_dslk_vong(dslk_vong);
void bubbleSort(node_dslk_vong* head) {
    if (head == NULL) return;
    node_dslk_vong *i, *j;
    bool swapped;
    do {
        swapped = false;
        for (i = head; i->next != head; i = i->next) {
            j = i->next;
            if (stof(i->data.diem) > stof(j->data.diem)) {
                swap(i->data, j->data);
                swapped = true;
            }
        }
    } while (swapped);
}

// SelectionSort; Goi ham: selectionSort(dslk_vong);
void selectionSort(node_dslk_vong* head) {
    if (head == NULL) return;
    node_dslk_vong *i, *j, *min;
    for (i = head; i->next != head; i = i->next) {
        min = i;
        for (j = i->next; j != head; j = j->next) {
            if (stof(j->data.diem) < stof(min->data.diem)) {
                min = j;
            }
        }
        if (min != i) {
            swap(i->data, min->data);
        }
    }
}

// InsertionSort; Goi ham: insertionSort(dslk_vong); -> in ra: duyet_dslk_vong(dslk_vong);
void insertionSort(node_dslk_vong* &head) {
    if (head == NULL || head->next == head) return;
    node_dslk_vong *sorted = NULL, *current = head;
    do {
        node_dslk_vong *next = current->next;
        current->next = current->prev = current;
        if (sorted == NULL) {
            sorted = current;
        } else if (stof(current->data.diem) <= stof(sorted->data.diem)) {
            current->next = sorted;
            current->prev = sorted->prev;
            sorted->prev->next = current;
            sorted->prev = current;
            sorted = current;
        } else {
            node_dslk_vong *tmp = sorted;
            while (tmp->next != sorted && stof(tmp->next->data.diem) < stof(current->data.diem)) {
                tmp = tmp->next;
            }
            current->next = tmp->next;
            current->prev = tmp;
            tmp->next->prev = current;
            tmp->next = current;
        }
        current = next;
    } while (current != head);
    head = sorted;
}
