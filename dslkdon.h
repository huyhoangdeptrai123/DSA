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

// sap xep danh sach
void duyet_dslk_don2(vector<Sinhvien_dslk_don> ds){
	for(auto x : ds){
		x.pr();
		cout << endl;
	}
}

// SelectionSort; Goi ham: selectionSort(dslk_don); -> in ra: duyet_dslk_don(dslk_don);
void selectionSort(node_dslk_don *head){
	for(node_dslk_don *i = head; i != NULL; i = i->next){
		node_dslk_don* minNode = i; 
		for(node_dslk_don* j = i->next; j != NULL; j = j->next){
			if(minNode->data.mssv > j->data.mssv){
				minNode = j;
			}
			Sinhvien_dslk_don tmp = minNode->data;
			minNode->data = i->data;
			i->data = tmp;
            }
		}
	}

// MergeSort; Goi ham: mergeSort1(dslk_don); -> in ra: duyet_dslk_don(dslk_don);
void partition2(node_dslk_don *&head, node_dslk_don *left, node_dslk_don *right){
	node_dslk_don *merge_list = NULL; // Danh sach hop nhat
	node_dslk_don *res = NULL; // Con tro den cuoi danh sach hop nhat
		
	// Trong khi ca hai mang con van chưa het
	while (left != NULL && right != NULL) {
		// So sanh mssv cua hai phan tu
		if (left->data.mssv <= right->data.mssv) {
		    if (merge_list == NULL) {
		        merge_list = left;
		        res = left;
			} else {
		        res->next = left;
		        res = left;
		    }
		left = left->next;
		} else {
		    if (merge_list == NULL) {
		        merge_list = right;
		        res = right;
		    } else {
		    	res->next = right;
		        res = right;
		    }
		    right = right->next;
		}
	}
		
	 // Neu mot trong hai mang con đa het, chi can noi danh sach hop nhat voi mang con lai
	if (left != NULL) {
		res->next = left;
	}
	if (right != NULL) {
		res->next = right;
	}
		
	// Cap nhat head cua danh sach
	head = merge_list;
		    
}
void merge1(node_dslk_don* head,node_dslk_don *&left,node_dslk_don *&right){
	if (head == NULL || head->next == NULL) {
        left = head;
        right = NULL;
    } else {
        node_dslk_don *slow = head; // Con tro chay cham
        node_dslk_don *fast = head->next; // Con tro chay nhanh

        // Fast chay hai buoc, slow chay 1 buoc, de fast den cuoi danh sach thi slow den giua
        while (fast != NULL) {
            fast = fast->next;
            if (fast != NULL) {
                slow = slow->next;
                fast = fast->next;
            }
        }

        left = head; // left la phan dau cua danh sach
        right = slow->next; // Right la phan sau của danh sách

        // Tach ds thanh 2
        slow->next = NULL;
    }
}
void mergeSort1(node_dslk_don *&head){
	if (head == NULL || head->next == NULL) {
        return; // Danh sach rong hoac chi co 1 phan tu, khong can sap xep
    }

    // Chia danh sach thanh 2 mang con
    node_dslk_don *left = NULL;
	node_dslk_don *right = NULL;
    merge1(head, left, right);

    // De quy sap xep 2 mang con
    mergeSort1(left);
    mergeSort1(right);

    // Hop nhat 2 mang con da sap xep
    partition2(head, left, right);
}


// HeapSort; Goi ham: chuyendoi(ds, dslk_don); -> heapSort(ds); -> in ra: duyet_dslk_don2(ds);
// Luu y: khai bao them thu vien #include<bits/stdc++.h>;  
//        khai bao them dong sau vector<Sinhvien_dslk_don> ds; (trong file do an(final).cpp)
//chuyen doi
void chuyendoi(vector<Sinhvien_dslk_don> &ds, node_dslk_don* head){
	int n = Size(head);
	ds.resize(n);
	node_dslk_don *tmp = head;
	int indx = 0;
	while(tmp != NULL){
		ds[indx] = tmp->data;
		tmp = tmp->next;
		indx++;
	}
}

void heapify(vector<Sinhvien_dslk_don>& ds, int n, int i) {
	    int largest = i;
	    int l = 2 * i + 1;
	    int r = 2 * i + 2;
	    if (l < n && ds[l].mssv > ds[largest].mssv)
	        largest = l;
	
	    if (r < n && ds[r].mssv > ds[largest].mssv)
	        largest = r;
	
	    if (largest != i) {
	        swap(ds[i], ds[largest]);
	        heapify(ds, n, largest);
	    }
}

void heapSort(vector<Sinhvien_dslk_don>& ds){
    int n = ds.size();	
	for (int i = n / 2 - 1; i >= 0; i--)
	    heapify(ds, n, i);
	
	for (int i = n - 1; i > 0; i--) {
	    swap(ds[0], ds[i]);
	    heapify(ds, i, 0);
	}
}

// BubbleSort; Goi ham: bubbleSort(dslk_don); -> in ra: duyet_dslk_don(dslk_don);
void bubbleSort(node_dslk_don *head){
	node_dslk_don *i, *j;
	for (i = head; i != NULL; i = i->next){
		for (j = i->next; j != NULL; j = j->next){
			if (i->data.diem > j->data.diem){
				Sinhvien_dslk_don tmp = i->data;
				i->data = j->data;
				j->data = tmp;
			}
		}
	}
} 



// InsertionSort; Goi ham: insertionSort(dslk_don); -> in ra: duyet_dslk_don(dslk_don);
void insertionSort(node_dslk_don *head){
		for(node_dslk_don *i = head; i != NULL; i = i->next){
			Sinhvien_dslk_don tmp = i->data;
			for(node_dslk_don *j = i->next; j != NULL && i->data.diem > j->data.diem; j = j->next){
				j->next->data = j->data;
				j->next->data = tmp;
			}
		}
}

node_dslk_don *layend(node_dslk_don* head){
		node_dslk_don *tmp = head;
		while(tmp != NULL && tmp->next != NULL){
			tmp = tmp->next;
		}
		return tmp;
}

// QuickSort; Goi ham: quickSort(dslk_don); -> in ra: duyet_dslk_don(dslk_don);
node_dslk_don* partition2(node_dslk_don* head,node_dslk_don* end,node_dslk_don *&newhead, node_dslk_don *&newend){
	node_dslk_don* res;
	node_dslk_don* pivot = end;
	node_dslk_don* pro = NULL;
	node_dslk_don* tmp = head;
	node_dslk_don* tail = pivot;
	while(tmp != pivot){
		if(tmp->data.mssv < pivot->data.mssv){
			if(newhead == NULL) newhead = tmp;
			pro = tmp;
			tmp = tmp->next;
		}
		else{
			if(pro) pro->next = tmp->next;
			node_dslk_don* temp = tmp->next;
			tmp->next = NULL;
			tail->next = tmp;
			tail = tmp;
			tmp = temp; 
		}
	}
	if(newhead == NULL) newhead = pivot;
	newend = tail;
	res = pivot;
	return res;
}
node_dslk_don* quicksortRec(node_dslk_don* head, node_dslk_don* end){	
		if(!head || head == end) return head;
		node_dslk_don* newhead = NULL;
		node_dslk_don* newend = NULL;
		node_dslk_don* pivot = partition2(head, end, newhead,newend);
		if(newhead != pivot){
			node_dslk_don* tmp = newhead;
			while(tmp->next != pivot){
				tmp = tmp->next;
			}
			tmp->next = NULL;
			newhead = quicksortRec(newhead, tmp);
			tmp = layend(newhead);
			tmp->next = pivot;
		}
		pivot->next = quicksortRec(pivot->next, newend);
		return newhead;
}
void quickSort(node_dslk_don *&head){
	head = quicksortRec(head, layend(head));
}
