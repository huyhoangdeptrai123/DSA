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

int Size(node_dslk_kep* a){
	int cnt= 0;
	while(a != NULL ){
		++cnt;
		a=a->next;
	}
	return cnt;
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

// Sap xep danh sach
void duyet_dslk_kep_2(vector<Sinhvien_dslk_kep> ds){
	for(auto x : ds){
		x.pr();
		cout << endl;
	}
}

// SelectionSort; Goi ham: selectionSort(dslk_kep); -> in ra: duyet_dslk_kep(dslk_kep);
void selectionSort(node_dslk_kep *head){    
	for(node_dslk_kep *i = head; i != NULL; i = i->next){ 
		node_dslk_kep* minNode = i; 
		for(node_dslk_kep* j = i->next; j != NULL; j = j->next){
			if(minNode->data.mssv > j->data.mssv){
				minNode = j;
			}
			Sinhvien_dslk_kep tmp = minNode->data;
			minNode->data = i->data;
			i->data = tmp;
            }
		}
	}

// merge sort; Goi ham: mergeSort_kep_1(dslk_kep); -> in ra: duyet_dslk_kep(dslk_kep);
void partition_kep_2(node_dslk_kep *&head, node_dslk_kep *left, node_dslk_kep *right){
	node_dslk_kep *merge_list = NULL; // Danh sach hop nhat
	node_dslk_kep *res = NULL; // Con tro den cuoi danh sach hop nhat
		
	// Trong khi ca hai mang con van chưa het
	while (left != NULL && right != NULL) {
		// So sanh mssv cua hai phan tu
		if (left->data.mssv <= right->data.mssv) { // Xep theo tieu chi: thay mssv = ten, diem
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
void merge_kep_1(node_dslk_kep* head,node_dslk_kep *&left,node_dslk_kep *&right){
	if (head == NULL || head->next == NULL) {
        left = head;
        right = NULL;
    } else {
        node_dslk_kep *slow = head; // Con tro chay cham
        node_dslk_kep *fast = head->next; // Con tro chay nhanh

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
void mergeSort_kep_1(node_dslk_kep *&head){
	if (head == NULL || head->next == NULL) {
        return; // Danh sach rong hoac chi co 1 phan tu, khong can sap xep
    }

    // Chia danh sach thanh 2 mang con
    node_dslk_kep *left = NULL;
	node_dslk_kep *right = NULL;
    merge_kep_1(head, left, right);

    // De quy sap xep 2 mang con
    mergeSort_kep_1(left);
    mergeSort_kep_1(right);

    // Hop nhat 2 mang con da sap xep
    partition_kep_2(head, left, right);
}


// HeapSort: Goi ham: chuyendoi(ds, dslk_kep);  -> heapSort(ds); -> in ra: duyet_dslk_kep_2(ds);
// Luu y: khai bao thu vien #include<bits/stdc++.h> 
//        khai bao: vector<Sinhvien_dslk_kep> ds; o ham main (do an(final).ccp)
//chuyen doi
void chuyendoi(vector<Sinhvien_dslk_kep> &ds, node_dslk_kep* head){
	int n = Size(head);
	ds.resize(n);
	node_dslk_kep *tmp = head;
	int indx = 0;
	while(tmp != NULL){
		ds[indx] = tmp->data;
		tmp = tmp->next;
		indx++;
	}
}


void heapify(vector<Sinhvien_dslk_kep>& ds, int n, int i) {
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

void heapSort(vector<Sinhvien_dslk_kep>& ds){
    int n = ds.size();	
	for (int i = n / 2 - 1; i >= 0; i--)
	    heapify(ds, n, i);
	
	for (int i = n - 1; i > 0; i--) {
	    swap(ds[0], ds[i]);
	    heapify(ds, i, 0);
	}
}


// BubbleSort; Goi ham: bubbleSort(dslk_kep); -> in ra: duyet_dslk_kep(dslk_kep);
void bubbleSort(node_dslk_kep *head){
	node_dslk_kep *i, *j;
	for (i = head; i != NULL; i = i->next){
		for (j = i->next; j != NULL; j = j->next){
			if (i->data.diem > j->data.diem){
				Sinhvien_dslk_kep tmp = i->data;
				i->data = j->data;
				j->data = tmp;
			}
		}
	}
} 



// InsertionSort; Goi ham: insertionSort(dslk_kep); -> in ra: duyet_dslk_kep(dslk_kep);
void insertionSort(node_dslk_kep *head){
		for(node_dslk_kep *i = head; i != NULL; i = i->next){
			Sinhvien_dslk_kep tmp = i->data;
			for(node_dslk_kep *j = i->next; j != NULL && i->data.diem > j->data.diem; j = j->next){
				j->next->data = j->data;
				j->next->data = tmp;
			}
		}
}

node_dslk_kep *layend(node_dslk_kep* head){
		node_dslk_kep *tmp = head;
		while(tmp != NULL && tmp->next != NULL){
			tmp = tmp->next;
		}
		return tmp;
}

// QuickSort; Goi ham: quickSort(dslk_kep); -> in ra: duyet_dslk_kep(dslk_kep);
node_dslk_kep* partition2(node_dslk_kep* head,node_dslk_kep* end,node_dslk_kep *&newhead, node_dslk_kep *&newend){
	node_dslk_kep* res;
	node_dslk_kep* pivot = end;
	node_dslk_kep* pro = NULL;
	node_dslk_kep* tmp = head;
	node_dslk_kep* tail = pivot;
	while(tmp != pivot){
		if(tmp->data.mssv < pivot->data.mssv){
			if(newhead == NULL) newhead = tmp;
			pro = tmp;
			tmp = tmp->next;
		}
		else{
			if(pro) pro->next = tmp->next;
			node_dslk_kep* temp = tmp->next;
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
node_dslk_kep* quicksortRec(node_dslk_kep* head, node_dslk_kep* end){	
		if(!head || head == end) return head;
		node_dslk_kep* newhead = NULL;
		node_dslk_kep* newend = NULL;
		node_dslk_kep* pivot = partition2(head, end, newhead,newend);
		if(newhead != pivot){
			node_dslk_kep* tmp = newhead;
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
void quickSort(node_dslk_kep *&head){
	head = quicksortRec(head, layend(head));
}
