#include<iostream>
#include<string.h>
using namespace std;
struct info{
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

class mangSv{
	public:
		int numberOfSv;
		info *sv;
	public:
		mangSv() {
			this->numberOfSv = 0;
		}
		void addDATA(info sv) {
			this->numberOfSv = this->numberOfSv + 1;
			info *newArr = new info [this->numberOfSv];
			for (int i = 0; i < this->numberOfSv - 1; ++i) {
				newArr[i] = this->sv[i];
			}
			newArr[this->numberOfSv - 1] = sv;
			this->sv = newArr;
		};
		void duyet_mang() {
			for (int i = 0; i < this->numberOfSv; ++i) {
				this->sv[i].pr();
				cout << endl;
			}
		}
// bubbleSort
    void bubbleSort_Ten() { // Xep theo ten
        for (int i = 0; i < this->numberOfSv - 1; ++i) {
            for (int j = 0; j < this->numberOfSv - i - 1; ++j) {
                if (this->sv[j].ten > this->sv[j + 1].ten) {
                    swap(this->sv[j], this->sv[j + 1]);
                }
            }
        }
    }
    
    void bubbleSort_Mssv() { // Xep theo mssv
        for (int i = 0; i < this->numberOfSv - 1; ++i) {
            for (int j = 0; j < this->numberOfSv - i - 1; ++j) {
                if (this->sv[j].mssv > this->sv[j + 1].mssv) {
                    swap(this->sv[j], this->sv[j + 1]);
                }
            }
        }
    }
    
    void bubbleSort_Diem() { // Xep theo diem
        for (int i = 0; i < this->numberOfSv - 1; ++i) {
            for (int j = 0; j < this->numberOfSv - i - 1; ++j) {
                if (this->sv[j].diem > this->sv[j + 1].diem) {
                    swap(this->sv[j], this->sv[j + 1]);
                }
            }
        }
    }
    //
    
    
    // insertionSort
    void insertionSort_Ten() { // xep theo ten
        for (int i = 1; i < this->numberOfSv; ++i) {
            info key = this->sv[i];
            int j = i - 1;
            while (j >= 0 && this->sv[j].ten > key.ten) {
                this->sv[j + 1] = this->sv[j];
                j = j - 1;
            }
            this->sv[j + 1] = key;
        }
    }
    
    void insertionSort_Mssv() { // xep theo mssv
        for (int i = 1; i < this->numberOfSv; ++i) {
            info key = this->sv[i];
            int j = i - 1;
            while (j >= 0 && this->sv[j].mssv > key.mssv) {
                this->sv[j + 1] = this->sv[j];
                j = j - 1;
            }
            this->sv[j + 1] = key;
        }
    }
    
    void insertionSort_Diem() { // xep theo diem
        for (int i = 1; i < this->numberOfSv; ++i) {
            info key = this->sv[i];
            int j = i - 1;
            while (j >= 0 && this->sv[j].diem > key.diem) {
                this->sv[j + 1] = this->sv[j];
                j = j - 1;
            }
            this->sv[j + 1] = key;
        }
    }
    //
    
    // selectionSort
    void selectionSort_Ten() { // xep theo ten
        for (int i = 0; i < this->numberOfSv - 1; ++i) {
            int min_idx = i;
            for (int j = i + 1; j < this->numberOfSv; ++j) {
                if (this->sv[j].ten < this->sv[min_idx].ten) {
                    min_idx = j;
                }
            }
            swap(this->sv[min_idx], this->sv[i]);
        }
    }
    
    void selectionSort_Mssv() { // xep theo mssv
        for (int i = 0; i < this->numberOfSv - 1; ++i) {
            int min_idx = i;
            for (int j = i + 1; j < this->numberOfSv; ++j) {
                if (this->sv[j].mssv < this->sv[min_idx].mssv) {
                    min_idx = j;
                }
            }
            swap(this->sv[min_idx], this->sv[i]);
        }
    }
    
    void selectionSort_Diem() { // xep theo diem
        for (int i = 0; i < this->numberOfSv - 1; ++i) {
            int min_idx = i;
            for (int j = i + 1; j < this->numberOfSv; ++j) {
                if (this->sv[j].diem < this->sv[min_idx].diem) {
                    min_idx = j;
                }
            }
            swap(this->sv[min_idx], this->sv[i]);
        }
    }
    //
    
    // MergeSort
    void merge_ten(int left, int mid, int right) { // xep theo ten
        int n1 = mid - left + 1;
        int n2 = right - mid;
        info* L = new info[n1];
        info* R = new info[n2];
        for (int i = 0; i < n1; ++i)
            L[i] = this->sv[left + i];
        for (int j = 0; j < n2; ++j)
            R[j] = this->sv[mid + 1 + j];
        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (L[i].ten <= R[j].ten) {
                this->sv[k] = L[i];
                i++;
            } else {
                this->sv[k] = R[j];
                j++;
            }
            k++;
        }
        while (i < n1) {
            this->sv[k] = L[i];
            i++;
            k++;
        }
        while (j < n2) {
            this->sv[k] = R[j];
            j++;
            k++;
        }
        delete[] L;
        delete[] R;
    }
    void mergeSort_Ten(int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSort_Ten(left, mid);
            mergeSort_Ten(mid + 1, right);
            merge_ten(left, mid, right);
        }
    }
    
    
    void merge_mssv(int left, int mid, int right) { // xep theo mssv
        int n1 = mid - left + 1;
        int n2 = right - mid;
        info* L = new info[n1];
        info* R = new info[n2];
        for (int i = 0; i < n1; ++i)
            L[i] = this->sv[left + i];
        for (int j = 0; j < n2; ++j)
            R[j] = this->sv[mid + 1 + j];
        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (L[i].mssv <= R[j].mssv) {
                this->sv[k] = L[i];
                i++;
            } else {
                this->sv[k] = R[j];
                j++;
            }
            k++;
        }
        while (i < n1) {
            this->sv[k] = L[i];
            i++;
            k++;
        }
        while (j < n2) {
            this->sv[k] = R[j];
            j++;
            k++;
        }
        delete[] L;
        delete[] R;
    }
    void mergeSort_Mssv(int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSort_Mssv(left, mid);
            mergeSort_Mssv(mid + 1, right);
            merge_mssv(left, mid, right);
        }
    }
    
    
    void merge_diem(int left, int mid, int right) { // xep theo diem
        int n1 = mid - left + 1;
        int n2 = right - mid;
        info* L = new info[n1];
        info* R = new info[n2];
        for (int i = 0; i < n1; ++i)
            L[i] = this->sv[left + i];
        for (int j = 0; j < n2; ++j)
            R[j] = this->sv[mid + 1 + j];
        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (L[i].diem <= R[j].diem) {
                this->sv[k] = L[i];
                i++;
            } else {
                this->sv[k] = R[j];
                j++;
            }
            k++;
        }
        while (i < n1) {
            this->sv[k] = L[i];
            i++;
            k++;
        }
        while (j < n2) {
            this->sv[k] = R[j];
            j++;
            k++;
        }
        delete[] L;
        delete[] R;
    }
    void mergeSort_Diem(int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSort_Diem(left, mid);
            mergeSort_Diem(mid + 1, right);
            merge_diem(left, mid, right);
        }
    }
    
    
    
    
    // heapSort
    void heapify_ten(int n, int i) { // xep theo ten
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < n && this->sv[left].ten > this->sv[largest].ten)
            largest = left;
        if (right < n && this->sv[right].ten > this->sv[largest].ten)
            largest = right;
        if (largest != i) {
            swap(this->sv[i], this->sv[largest]);
            heapify_ten(n, largest);
        }
    }
    void heapSort_Ten() {
        for (int i = this->numberOfSv / 2 - 1; i >= 0; i--)
            heapify_ten(this->numberOfSv, i);
        for (int i = this->numberOfSv - 1; i > 0; i--) {
            swap(this->sv[0], this->sv[i]);
            heapify_ten(i, 0);
        }
    }
    
    
    void heapify_mssv(int n, int i) { // xep theo mssv
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < n && this->sv[left].mssv > this->sv[largest].mssv)
            largest = left;
        if (right < n && this->sv[right].mssv > this->sv[largest].mssv)
            largest = right;
        if (largest != i) {
            swap(this->sv[i], this->sv[largest]);
            heapify_mssv(n, largest);
        }
    }
    void heapSort_Mssv() {
        for (int i = this->numberOfSv / 2 - 1; i >= 0; i--)
            heapify_mssv(this->numberOfSv, i);
        for (int i = this->numberOfSv - 1; i > 0; i--) {
            swap(this->sv[0], this->sv[i]);
            heapify_mssv(i, 0);
        }
    }
    
    
    void heapify_diem(int n, int i) { // xep theo diem
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < n && this->sv[left].diem > this->sv[largest].diem)
            largest = left;
        if (right < n && this->sv[right].diem > this->sv[largest].diem)
            largest = right;
        if (largest != i) {
            swap(this->sv[i], this->sv[largest]);
            heapify_diem(n, largest);
        }
    }
    void heapSort_Diem() {
        for (int i = this->numberOfSv / 2 - 1; i >= 0; i--)
            heapify_diem(this->numberOfSv, i);
        for (int i = this->numberOfSv - 1; i > 0; i--) {
            swap(this->sv[0], this->sv[i]);
            heapify_diem(i, 0);
        }
    }
    
    
    //quickSort
    int partition_ten(int low, int high) { // xep theo ten
        string pivot = this->sv[high].ten;
        int i = (low - 1);
        for (int j = low; j <= high - 1; j++) {
            if (this->sv[j].ten < pivot) {
                i++;
                swap(this->sv[i], this->sv[j]);
            }
        }
        swap(this->sv[i + 1], this->sv[high]);
        return (i + 1);
    }
    void quickSort_Ten(int low, int high) {
        if (low < high) {
            int pi = partition_ten(low, high);
            quickSort_Ten(low, pi - 1);
            quickSort_Ten(pi + 1, high);
        }
    }
    
    
    int partition_mssv(int low, int high) { // xep theo mssv
        string pivot = this->sv[high].mssv;
        int i = (low - 1);
        for (int j = low; j <= high - 1; j++) {
            if (this->sv[j].mssv < pivot) {
                i++;
                swap(this->sv[i], this->sv[j]);
            }
        }
        swap(this->sv[i + 1], this->sv[high]);
        return (i + 1);
    }
    void quickSort_Mssv(int low, int high) {
        if (low < high) {
            int pi = partition_mssv(low, high);
            quickSort_Mssv(low, pi - 1);
            quickSort_Mssv(pi + 1, high);
        }
    }
    
    
    int partition_diem(int low, int high) { // xep theo diem
        string pivot = this->sv[high].diem;
        int i = (low - 1);
        for (int j = low; j <= high - 1; j++) {
            if (this->sv[j].diem < pivot) {
                i++;
                swap(this->sv[i], this->sv[j]);
            }
        }
        swap(this->sv[i + 1], this->sv[high]);
        return (i + 1);
    }
    void quickSort_Diem(int low, int high) {
        if (low < high) {
            int pi = partition_diem(low, high);
            quickSort_Diem(low, pi - 1);
            quickSort_Diem(pi + 1, high);
        }
    }
};
