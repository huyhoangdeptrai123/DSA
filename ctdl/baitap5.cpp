#include <iostream>
#include <string>
using namespace std;

struct SinhVien {
    string ten;
    int maSV;
    int namSinh;
    string lop;
    SinhVien* next;
};

// ham them 1 node sinh vien vao dslk
void themSinhVien(SinhVien*& head, string ten, int maSV, int namSinh, string lop) {
    SinhVien* svMoi = new SinhVien;
    svMoi->ten = ten;
    svMoi->maSV = maSV;
    svMoi->namSinh = namSinh;
    svMoi->lop = lop;
    svMoi->next = NULL;

    if (head == NULL) {
        head = svMoi;
    } else {
        SinhVien* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = svMoi;
    }
}

// ham in ds sinh vien
void hienThiDanhSach(SinhVien* head) {
    SinhVien* temp = head;
    while (temp != NULL) {
        cout << "Ten          : " << temp->ten << endl;
		cout << "Ma sinh vien : " << temp->maSV << endl;
		cout << "Nam sinh     : " << temp->namSinh << endl;
		cout << "Lop          : " << temp->lop << endl;
		cout << "-------------------------------- \n";
        temp = temp->next;
    }
}
void giaiPhong(SinhVien*& head) {
    SinhVien* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}
// Ham sap xep insertionSort;
void insertionSort(SinhVien*& head) {
    if (head == NULL || head->next == NULL)
        return;

    SinhVien* sorted = NULL;
    SinhVien* current = head;
    while (current != NULL) {
        SinhVien* next = current->next;
        if (sorted == NULL || sorted->maSV >= current->maSV) {
            current->next = sorted;
            sorted = current;
        }
        else {
            SinhVien* search = sorted;
            while (search->next != NULL && search->next->maSV < current->maSV) {
                search = search->next;
            }
            current->next = search->next;
            search->next = current;
        }
        current = next;
    }
    head = sorted;
}

int main() {
    SinhVien* head = NULL;
	SinhVien* last = NULL;

    // Them sinh vien vao danh sach
    themSinhVien(head, "Nguyen Hoa Hau", 20093, 2002, "D20");
    themSinhVien(head, "Do Luc Si"     , 20079, 2000, "D20");
    themSinhVien(head, "Ly Minh Tinh"  , 21085, 2003, "D21");
    themSinhVien(head, "Tran Dai Gia"  , 21096, 2003, "D21");
    themSinhVien(head, "Duong Vo Su"   , 18011, 2000, "D18");
    cout<<"Danh sach sinh vien truoc khi sap xep: "<<endl;
    hienThiDanhSach(head);
	insertionSort(head);
    cout << "Danh sach sinh vien sau khi sap xep bang Insertion Sort:" << endl;
    hienThiDanhSach(head);


    
    return 0;
}

